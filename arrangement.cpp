#include "arrangement.h"
#include "utils.h"
#include <queue>

namespace geometric {

Arrangement::Arrangement(int dim) : dim(dim), d(dim) {
    first = new FaceNode(vector<int>(), -1);
    Arr = Matrix<Integer>(0, d);
}

/*
 * Generates the nodes of the initial arrangement containing only the first dim hyperplanes whose normal vectors are linearly independent
 * Constructs the arcs between faces and subfaces
 * If the given hyperplanes' normal vectors don't span the whole space, we work on a lower-dimensional arrangement and dim is reduced.
 */
void Arrangement::InitIncidenceGraph(vector<short> &v) {
    if(v.size() == dim) {
        int face_d = 0; //dimension of the face is the number of non zero entries in the position vector of the face
        vector<int> affine_subspace;
        int etoh = 0;
        for(int j = 0; j < dim; ++j) {
            face_d += (v[j] != 0);
            if(!v[j]) {
                affine_subspace.push_back(j);
            }
            else {
                etoh = j + 1;
            }
        }
        //In the lower-dimensional arrangement, all faces are included in the additional hyperplanes
        for(int j = dim; j < d; ++j) {
            affine_subspace.push_back(j);
        }

        FaceNode *face = new FaceNode(affine_subspace, face_d);
        initial_nodes[v] = face;

        if(face_d == 1) {
            /* In order to get a point inside the ray different from its only vertex, we take the hyperplane 
             * defining the halfspace it is located in and move the constant -1 or 1 based on which halfspace it's in
             */
            int j = etoh * v[etoh - 1];
            int sgn = abs(j) / j;
            mp_etoh[face] = Hyperplane(Arr[abs(j) - 1], RHS[abs(j) - 1] + sgn);
        }

        /* Creating the arcs between faces:
         * face f is a subface of face g in A(H') iff f = null (the (-1)-dimensional face) and g is a vertex, 
         * or if f is a cell and g = A(H) (the (d+1)-dimensional face), 
         * or if the position vectors v(f) and v(g) of f and g agree up to one component which equals zero in v(f).
         */
        if(face_d == 0) { //this is the common point(vertex) of the dim hyperplanes
            first->superfaces.insert(face);
            face->subfaces.insert(first);
        }
        if(face_d == dim) {
            last->subfaces.insert(face);
            face->superfaces.insert(last);
        }

        for(int j = 0; j < dim; ++j) {
            vector<short> vt = v;
            if(v[j] != 0) { //we can get a subface
                vt[j] = 0; 
                if(initial_nodes[vt]) {
                    initial_nodes[vt]->superfaces.insert(face);
                    face->subfaces.insert(initial_nodes[vt]);
                }
            }
            else { //we can get two superfaces of the face
                vt[j] = -1;
                if(initial_nodes[vt]) {
                    initial_nodes[vt]->subfaces.insert(face);
                    face->superfaces.insert(initial_nodes[vt]);
                }
                vt[j] = 1;
                if(initial_nodes[vt]) {
                    initial_nodes[vt]->subfaces.insert(face);
                    face->superfaces.insert(initial_nodes[vt]);
                }
            }
        }
        return;
    }

    for(short j = -1; j <= 1; ++j) {
        v.push_back(j);
        InitIncidenceGraph(v);
        v.pop_back();
    }
    return;
}

void Arrangement::CalculateInsidePoint(FaceNode* f) {
    if(f->dim == -1 || f->dim == dim + 1) {
        return;
    }
    else if(!f->dim) {
        //Solving the system of linear equations defining the initial arrangement:
        //All vectors are linearly independent => a unique vertex
        Matrix<Integer> M(0, d);
        vector<Integer> R;
        for(auto i : f->aff) {
            M.append(Arr[i]);
            R.push_back(RHS[i]);
        }

        Integer denom = 0;
        vector<Integer> S = M.solve_rectangular(R, denom);
        for(auto it : S) {
            f->point.push_back(it);
            f->point.back() /= denom;
        }
    }
    else if(f->dim == 1 && f->subfaces.size() == 1) {
        //Edges with only one subface are rays
        Matrix<Integer> M(0, d);
        vector<Integer> R;
        for(auto i : f->aff) {
            M.append(Arr[i]);
            R.push_back(RHS[i]);
        }
        if(mp_etoh[f].first.empty()) { 
            //We get the basis of the kernel of M which will consist of only one vector and append it to M in order to solve it uniquely.
            Matrix<Integer> kerM = M.kernel(false);
            M.append(kerM[0]);
            R.push_back(0); 
        }
        else {
            M.append(mp_etoh[f].first);
            R.push_back(mp_etoh[f].second);
        }

        Integer denom = 0;
        vector<Integer> S = M.solve_rectangular(R, denom);
        for(auto it : S) {
            f->point.push_back(it);
            f->point.back() /= denom;
        }
    }
    else { 
        f->point.resize(d);
        for(auto face : f->subfaces) {
            v_add_result(f->point, d, f->point, face->point);
        }
        Rational m = f->subfaces.size();
        v_scalar_division(f->point, m);
    }
}

void Arrangement::AddHyperplane(Hyperplane h) {
    int index = Arr.nr_of_rows();
    Arr.append(h.first);
    RHS.push_back(h.second);
    //Phase 1: Find an edge in the current arrangement that intersects the current hyperplane h
    //Find an arbitrary vertex u in current arrangement and find edge incident to v thats non-parallel to h - guaranteed to be at least 1 such edge by step 1
    FaceNode* v = *first->superfaces.begin(); //guaranteed to exist given the initial arrangement contains dim linearly independent sets
    FaceNode *e;
    vector<Rational> e_dir(d);
    for(auto edge : v->superfaces) {
        //Check if edge is parallel to the current hyperplane
        e_dir = get_direction(v->point, edge->point);
        Rational dot_prod = dot_product(e_dir, h.first);
        //If dot product is 0, they are parallel
        if(dot_prod != 0) {
            e = edge;
            break;
        }
    }

    bool intersects = 0;
    //Go along the line that contains e until we find the edge that intersects h
    if(e->subfaces.size() == 1) {
        //The edge is unbounded. We check whether it intersects h. If it doesn't, we continue our search towards the opossite direction
        Rational d1 = dot_product(v->point, h.first) - h.second;
        Rational d2 = dot_product(e->point, h.first) - h.second;
        if(d1 * d2 <= 0 || abs(d1) > abs(d2)) {
            //It intersect h, we continue with e as our starting edge
            intersects = 1;
        }
    }
    else {
        //The edge is bounded so we get its second vertex
        auto it = e->subfaces.begin();
        FaceNode *e1 = *it;
        FaceNode *e2 = *(++it);
        FaceNode *v2 = (e1 == v ? e2 : e1);
        //We get the vertex which is closed to h so we can continue walking towards that direction
        Rational d1 = dot_product(v->point, h.first) - h.second;
        Rational d2 = dot_product(v2->point, h.first) - h.second;
        if(d1 * d2 < 0) {
            //It intersect h, we continue with e as our starting edge
            intersects = 1;
        }
        else if(abs(d1) > abs(d2)) {
            //v2 is closed to h than v, thus we go towards v2 
            v = v2;
        }
    }

    while(!intersects) {
        //We get the other edge connected to v in the line containing e.
        for(auto edge : v->superfaces) {
            if(e == edge) {
                continue;
            }
            vector<Rational> edge_dir = get_direction(v->point, edge->point);
            int t = 0;
            while(edge_dir[t++] == 0);
            Rational lambda = e_dir[t - 1] / edge_dir[t - 1];
            v_scalar_multiplication(edge_dir, lambda);

            if(edge_dir == e_dir) {
                e = edge;
                break;
            }
        }

        //If the current e is unbounded, search is terminated so e must intersect h. 
        if(e->subfaces.size() == 1) {
            intersects = 1;
            break;
        }
        //If e is bounded, it intersect h iff one endpoint is in h or the endpoints are in different halfspaces.
        auto it = e->subfaces.begin();
        FaceNode *e1 = *it;
        FaceNode *e2 = *(++it);
        intersects = ((dot_product(e1->point, h.first) - h.second) * (dot_product(e2->point, h.first) - h.second) <= 0);
        //We get the other endpoint of the chosen edge (which will be closer to h)
        v = (e1 == v ? e2 : e1);
    }

    //Phase 2: Mark the faces which intersect h
    map<FaceNode*, COLOR> marked_faces;
    queue<FaceNode*> Q;
    
    Q.push(*e->superfaces.begin());
    marked_faces[Q.front()] = GREEN;

    vector<vector<FaceNode*>> L(dim + 1); //List which contains all non-white k-faces for each 0 <= k <= dim

    while(!Q.empty()) {
        FaceNode* face = Q.front();
        Q.pop();

        //Check for edges incident to current 2-face and mark them.
        for(auto edge : face->subfaces) {
            COLOR ec = marked_faces[edge];
            if(ec && ec != WHITE) {
                continue;
            }

            FaceNode *v1 = *edge->subfaces.begin();
            Rational d1 = dot_product(v1->point, h.first) - h.second;
            if(d1 == 0 && marked_faces[v1] != CRIMSON) {
                //v1 is contained in h
                L[0].push_back(v1);
                marked_faces[v1] = CRIMSON;
            }

            COLOR v1c = marked_faces[v1];

            if(edge->subfaces.size() == 1) {
                Rational d2 = dot_product(edge->point, h.first) - h.second;
                if(d2 == 0 && v1c == CRIMSON) {
                    //v2 is contained in h
                    marked_faces[edge] = CRIMSON;
                }
                else if(d1 * d2 < 0 || abs(d1) > abs(d2)) {
                    //Unbounded egde intersects h but not contained in it
                    marked_faces[edge] = RED;
                }
                else if(v1c == CRIMSON){
                    marked_faces[edge] = PINK;
                }
            }
            else {
                auto it = edge->subfaces.begin();
                FaceNode *v2 = *(++it);
                Rational d2 = dot_product(v2->point, h.first) - h.second;
                if(d2 == 0 && marked_faces[v2] != CRIMSON) {
                    //v2 is contained in h
                    L[0].push_back(v2);
                    marked_faces[v2] = CRIMSON;
                }

                if(v1c == CRIMSON && marked_faces[v2] == CRIMSON) {
                    marked_faces[edge] = CRIMSON;
                }
                else if(d1 * d2 == 0) {
                    marked_faces[edge] = PINK;
                }
                else if(d1 * d2 < 0){
                    marked_faces[edge] = RED;
                }
            }

            ec = marked_faces[edge];
            if(ec && ec != WHITE) {
                //If edge has been marked, push its incident 2-faces into the queue
                L[1].push_back(edge);
                for(auto face : edge->superfaces) {
                    if(marked_faces[face] != GREEN) {
                        Q.push(face);
                        marked_faces[face] = GREEN;
                    }
                }
            }
        }
    }
    //We mark the faces of dimension dim >= 2.
    for(int k = 2; k <= dim; ++k) {
        for(auto f : L[k - 1]) {
            for(auto g : f->superfaces) {

                COLOR gc = marked_faces[g];
                if(gc && gc != GREEN && gc != WHITE) {
                    continue;
                }

                COLOR fc = marked_faces[f];
                if(fc == PINK) {
                    //If pink subfaces on both sides of f or if one subface is red, g is red. Otherwise, pink.   
                    marked_faces[g] = PINK;
                    bool right = 0, left = 0;
                    for(auto sf : g->subfaces) { //optimization?
                        COLOR sfc = marked_faces[sf];

                        if(sfc == PINK) {
                            if(dot_product(sf->point, h.first) > h.second) {
                                right = 1;
                            }
                            else {
                                left = 1;
                            }
                            if(right && left) {
                                marked_faces[g] = RED;
                                break;
                            }
                        }
                        else if(sfc == RED) {
                            marked_faces[g] = RED;
                            break;
                        }
                    } 
                }
                else if(fc == RED) {
                    marked_faces[g] = RED;
                }
                else if(fc == CRIMSON) {
                    //If all subfaces of g are crimson, g is crimson. Pink otherwise.
                    marked_faces[g] = CRIMSON;
                    for(auto sf : g->subfaces) {
                        if(marked_faces[sf] != CRIMSON) {
                            marked_faces[g] = PINK;
                            break;
                        }
                    }
                }

                L[k].push_back(g);
            }
        }
    }

    // for(int k = 0; k <= dim; ++k) {
    //     cout<<k<<" dim:\n";
    //     for(auto f : L[k]) {
    //         cout<<f->point;
    //         cout<<"subfaces\n";
    //         for(auto sf : f->subfaces) {
    //             cout<<sf->point;
    //         }
    //         cout<<COLOR(marked_faces[f])<<" xd\n";
    //     }
    // }

    //Phase 3: Manipulate all marked faces inside the lists and create new faces if needed.
    for(int k = 0; k <= dim; ++k) {
        int s = L[k].size();
        for(int i = 0; i < s; ++i) {
            FaceNode *g = L[k][i];
            COLOR gc = marked_faces[g];
            if(gc == PINK) {
                marked_faces[g] = GREY;
            }
            else if(gc == CRIMSON) {
                marked_faces[g] = BLACK;
            }
            else if(gc == RED) {
                marked_faces[g] = BROWN;
                //Replace g by the two parts created by h dividing g.
                vector<int> g_h = g->aff;
                FaceNode *g_p = new FaceNode(g_h, k);
                g_p->aff = g->aff;
                FaceNode *g_n = new FaceNode(g_h, k);
                g_n->aff = g->aff;

                marked_faces[g_n] = GREY;
                marked_faces[g_p] = GREY;
                L[k].push_back(g_p);
                L[k].push_back(g_n);

                g_h.push_back(index);
                //The newly created face contained in h
                FaceNode *f = new FaceNode(g_h, k - 1);
                f->aff = g_h;

                marked_faces[f] = BLACK;
                L[k - 1].push_back(f);

                f->superfaces.insert(g_p);
                f->superfaces.insert(g_n);
                g_p->subfaces.insert(f);
                g_n->subfaces.insert(f);
                //connect each superface of g to g_p and g_n
                for(auto spf : g->superfaces) {
                    g_p->superfaces.insert(spf);
                    g_n->superfaces.insert(spf);
                    spf->subfaces.erase(g);
                    spf->subfaces.insert(g_p);
                    spf->subfaces.insert(g_n);
                }
                for(auto sf : g->subfaces) {           
                
                    COLOR sfc = marked_faces[sf];
                    if(sfc && sfc != WHITE && sfc != GREY) {
                        continue;
                    }

                    if(dot_product(sf->point, h.first) > h.second) {
                        //subface is on the positive halfspace
                        g_p->subfaces.insert(sf);
                        sf->superfaces.insert(g_p);
                        sf->superfaces.erase(g);
                    }
                    else {
                        //subface is on the negative halfspace
                        g_n->subfaces.insert(sf);
                        sf->superfaces.insert(g_n);
                        sf->superfaces.erase(g);
                    }

                    if(sfc == GREY) {
                        //connect black subfaces of subfaces of g to f
                        for(auto sff : sf->subfaces) {
                            if(marked_faces[sff] == BLACK) {
                                sff->superfaces.insert(f);
                                f->subfaces.insert(sff);
                            }
                        }
                    }
                }

                if(k == 1) {
                    first->superfaces.insert(f);
                    f->subfaces.insert(first);
                }

                if(f->dim == 1 && f->subfaces.size() == 1) {
                    mp_etoh[f] = Hyperplane();
                }
                CalculateInsidePoint(f);

                if(f->dim == 1 && f->subfaces.size() == 1) {
                    //Check if the point inside f is inside the face g by comparing its position vector with g's point in the current arrangement
                    for(int i = 0; i < index; ++i) {
                        Rational d1 = dot_product(f->point, Arr[i]) - RHS[i];
                        Rational d2 = dot_product(g->point, Arr[i]) - RHS[i];
                        if(d1 != 0) {
                            d1 /= abs(d1);
                        }
                        if(d2 != 0) {
                            d2 /= abs(d2);
                        }
                        if(d1 != d2) {
                            //f is not inside g so we change f's point to point towards the other direction
                            FaceNode *vf = *f->subfaces.begin();
                            for(int i = 0; i < d; ++i) {
                                f->point[i] = 2 * vf->point[i] - f->point[i];
                            }
                        }
                    }
                }
                if(g->dim == 1 && g->subfaces.size() == 1) {
                    //If g is an unbounded edge, it will be cut in another unbounded edge and a bounded edge
                    FaceNode *vg = *(g->subfaces.begin());
                    if(dot_product(vg->point, h.first) > h.second) {
                        //g_p is the bounded edge
                        CalculateInsidePoint(g_p);
                        //The point inside the unbounded edge is the internal point of g_p opposite of the point of intersection with f on g.
                        FaceNode *vg_n = *g_n->subfaces.begin();
                        g_n->point.resize(d);
                        for(int i = 0; i < d; ++i) {
                            g_n->point[i] = 2 * vg_n->point[i] - g_p->point[i];
                        }
                    }
                    else {
                        //g_n is the bounded edge
                        CalculateInsidePoint(g_n);
                        //The point inside the unbounded edge is the internal point of g_n opposite of the point of intersection with f on g.
                        FaceNode *vg_p = *g_p->subfaces.begin();
                        g_p->point.resize(d);
                        for(int i = 0; i < d; ++i) {
                            g_p->point[i] = 2 * vg_p->point[i] - g_n->point[i];
                        }
                    }
                }
                else {
                    CalculateInsidePoint(g_p);
                    CalculateInsidePoint(g_n);
                }

                // cout<<k<<" dim:]\n";
                // cout<<g->point;
                // cout<<g_p->point;
                // cout<<"subfaces\n";
                // for(auto aa : g_p->subfaces) {
                //     cout<<aa->point;
                // }
                // cout<<"superfaces\n";
                // for(auto aa : g_p->superfaces) {
                //     cout<<aa->point;
                // }
                // cout<<g_n->point;
                // cout<<"subfaces\n";
                // for(auto aa : g_n->subfaces) {
                //     cout<<aa->point;
                // }
                // cout<<"superfaces\n";
                // for(auto aa : g_n->superfaces) {
                //     cout<<aa->point;
                // }
                // cout<<f->point;
                // cout<<"subfaces\n";
                // for(auto aa : f->subfaces) {
                //     cout<<aa->point;
                // }
                // cout<<"superfaces\n";
                // for(auto aa : f->superfaces) {
                //     cout<<aa->point;
                // }
            }
        }
    }
    for(int k = 0; k <= dim; ++k) {
        for(int j = 0; j < L[k].size(); ++j) {
            if(marked_faces[L[k][j]] == BROWN) {
                delete L[k][j];
            }
            else {
                marked_faces[L[k][j]] = WHITE;
            }
        }
        L[k].clear();
    }

}

void Arrangement::ConstructArrangement(vector<Hyperplane> hyperplanes) {
    //Step 1: Construct initial arrangement.
    int n = hyperplanes.size();
    int j = 0;
    vector<bool> in_arrangement(n);
    for(int i = 0; i < n && j < dim; ++i) {
        Arr.append(hyperplanes[i].first);
        j++;
        in_arrangement[i] = 1;
        RHS.push_back(hyperplanes[i].second);

        if(Arr.rank() != j) {
            j--;
            Arr.remove_row(Arr.nr_of_rows() - 1);
            in_arrangement[i] = 0;
            RHS.pop_back();
        }
    }

    int m = 0;
    if(Arr.nr_of_rows() != dim) {
        /* If there are less than dim linearly independent normal vectors, we get a basis for the kernel of Arr.
         * We append this basis to Arr and we get a matrix of rank dim. 
         * When calculating the initial faces we only regard the faces which are included in these newly added hyperplanes.
         */
        Matrix<Integer> AddH = Arr.kernel(false);
        m = AddH.nr_of_rows();
        for(int i = 0; i < m; ++i) {
            Arr.append(AddH[i]);
            RHS.push_back(0);
        }
        //Arrangement spans a subspace of R^dim so we work on a lower-dimensional arrangement. The initial faces will in effect all be contained in the hyperplanes given by the AddH vectors.
        dim -= m;
    }
    last = new FaceNode(vector<int>(), dim + 1);

    vector<short> v = {};
    InitIncidenceGraph(v);

    //Setting points strictly inside for each face
    queue<FaceNode*> Q;
    map<FaceNode*, bool> inQ;
    Q.push(first);

    while(!Q.empty()) {
        FaceNode *cur = Q.front(); 
        Q.pop();

        for(auto face : cur->superfaces) {
            if(!inQ[face]) {
                Q.push(face);
                inQ[face] = 1;
            }
        }

        CalculateInsidePoint(cur);
    }

    Q.push(first);
    map<FaceNode*, bool> inQ2;

    while(!Q.empty()) {
        FaceNode *cur = Q.front(); 
        Q.pop();

        cout<<cur->dim<<" ; "<<cur->point<<"-\nsubfaces: ";
        for(auto face : cur->subfaces) {
            cout<<face->point<<" ";
        }
        cout<<"\n";
        for(auto face : cur->superfaces) {
            if(!inQ2[face]) {
                Q.push(face);
                inQ2[face] = 1;
            }
        }
    }

    //Step 2: We add each unadded hyperplane into the arrangement incrementally:
    for(int i = 0; i < n; ++i) {
        if(!in_arrangement[i]) {
            AddHyperplane(hyperplanes[i]);
            
            Q.push(first);
            inQ2.clear();
            while(!Q.empty()) {
                FaceNode *cur = Q.front(); 
                Q.pop();

                cout<<cur->dim<<" ; "<<cur->point<<"-\nsubfaces: ";
                for(auto face : cur->subfaces) {
                    cout<<face->point<<" ";
                }
                cout<<"\n";
                for(auto face : cur->superfaces) {
                    if(!inQ2[face]) {
                        Q.push(face);
                        inQ2[face] = 1;
                    }
                }
            }
        }
        
    }
}

}