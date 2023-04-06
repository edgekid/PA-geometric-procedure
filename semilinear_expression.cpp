#include "semilinear_expression.h"
#include "arrangement.h"
#include "utils.h"

namespace geometric {

void SENode::init() {
    in_constraint = true;
    dv.resize(dim);
}

SENode::SENode() : dim(0), op(0), complement(false) {
    sys_ineq = Matrix<Integer>(0);
    init();
}

SENode::SENode(int dim, short op, bool complement, SENode* left, SENode* right) : dim(dim + 1), op(op), complement(complement), left_child(left), right_child(right) {
    sys_ineq = Matrix<Integer>(0);
    init();
}

SENode::SENode(int dim, const vector<Integer>& v, short op, bool complement, SENode* left, SENode* right) : dim(dim + 1), op(op), complement(complement), left_child(left), right_child(right) {
    sys_ineq = Matrix<Integer>(v);
    init();
}

vector<Integer> SENode::GetSolution() {
    if(semilinear_set.empty()) {
        return vector<Integer>();
    }
    return semilinear_set[0].first[0];
}

void SENode::PrintSolutions() {
    for(int j = 0; j < semilinear_set.size(); ++j){
        cout<<"HybridLS "<<j + 1<<":\nBase set:\n";
        auto it = semilinear_set[j];
        for(int i = 0; i < it.first.nr_of_rows(); ++i) {
            cout<<it.first[i];
        }
        cout<<"Periodic set:\n";
        for(int i = 0; i < it.second.nr_of_rows(); ++i) {
            cout<<it.second[i];
        }
        cout<<"\n";
    }
}

void SENode::ComputeSubtree(bool first_vertex) {
    if(complement) {
        return;
    }
    if(op != 0) { //not a leaf
        if(left_child) {
            left_child->ComputeSubtree(false);
            in_constraint = left_child->in_constraint;
            dim = left_child->dim;
        }
        if(right_child) {
            right_child->ComputeSubtree(false);
            in_constraint = right_child->in_constraint;
            dim = right_child->dim;
        }
    }

    ComputeOperation();

    if(first_vertex && in_constraint) { //If this is the node defining the formula, we compute its semi-linear set if its not been computed already
        TranslateToSemilinearSet();
    }

}

//computations
void SENode::ComputeOperation() {
    switch(op) {
        case -2: //Intersection of semilinear sets     
            Intersection();
            break;
        
        case -1: //Union of semilinear sets.
            Union();
            break;

        case 0:
            break;

        default:
            if(left_child->in_constraint) {
                left_child->ProjectCoordinateConstr(op);
                sys_ineq = left_child->sys_ineq;
            }
            else {
                left_child->ProjectCoordinateGen(op);
                semilinear_set = left_child->semilinear_set;
            }
            dv = left_child->dv;
            break;
    }
}

//translate the polyhedrons into a semilinear set
void SENode::TranslateToSemilinearSet() {
    Cone<Integer> polyhedron = Cone<Integer>(Type::inhom_inequalities, sys_ineq);
    polyhedron.compute(ConeProperty::HilbertBasis);
    
    Matrix<Integer> recession_cone = polyhedron.getHilbertBasisMatrix();
    //Get the maximal subspace in case it contains minimal faces
    vector<vector<Integer>> max_subspace = polyhedron.getMaximalSubspace();
    for(auto v : max_subspace) { //libnormaliz returns basis for the lattice of the maximal subspace modulo unit group - need to include their inverses as well
        recession_cone.append(v);
        v_scalar_multiplication(v, Integer(-1));
        recession_cone.append(v);
    }

    Matrix<Integer> polytope = polyhedron.getModuleGeneratorsMatrix();

    //set recession cone's dimension in case it is empty.
    recession_cone.set_nc(polytope.nr_of_columns());

    semilinear_set.push_back(make_pair(polytope, recession_cone));

    //Get rid of homogenizing coordinates (0 and 1)
    ProjectCoordinateGen(dim);

    in_constraint = false;
}

void SENode::ProjectCoordinateGen(int coord) {
    SemilinearSet new_sl_set;
    int c = coord + dv[coord - 1];
    for(int i = 0; i < semilinear_set.size(); ++i) {
        Matrix<Integer> polytope(0, semilinear_set[i].first.nr_of_columns() - 1), recession_cone(0, semilinear_set[i].first.nr_of_columns() - 1);
        
        map<vector<Integer>, bool> vectors_in_recessionc, vectors_in_polytope; //placeholder: inefficient
        for(size_t j = 0; j < semilinear_set[i].first.nr_of_rows(); ++j) {
            vector<Integer> vec = semilinear_set[i].first[j];
            vec.erase(vec.begin() + c - 1);

            if(!vectors_in_polytope[vec]) {
                vectors_in_polytope[vec] = 1;
                polytope.append(vec);
            }
        }
        for(size_t j = 0; j < semilinear_set[i].second.nr_of_rows(); ++j) {
            vector<Integer> vec = semilinear_set[i].second[j];
            vec.erase(vec.begin() + c - 1);

            if(!vectors_in_recessionc[vec]) {
                vectors_in_recessionc[vec] = 1;
                recession_cone.append(vec);
            }
        }

        new_sl_set.push_back(make_pair(polytope, recession_cone));
    }

    semilinear_set = new_sl_set;

    for(int i = coord - 1; i < dv.size(); ++i) {
        dv[i]++;
    }

    dim--;
}

void SENode::ProjectCoordinateConstr(int coord) {
    vector<vector<Integer>> system = sys_ineq.get_elements();

    int c = coord + dv[coord - 1];

    for(auto &vec : system) {
        vec.erase(vec.begin() + c - 1);
    }

    sys_ineq = Matrix<Integer>(system);

    for(int i = coord - 1; i < dv.size(); ++i) {
        dv[i]++;
    }

    dim--;
}

void SENode::Union() {
    //if the children are still in constraint representation, now it's time to translate it
    if(left_child->in_constraint) {
        left_child->TranslateToSemilinearSet();
    }
    semilinear_set.insert(semilinear_set.end(), left_child->semilinear_set.begin(), left_child->semilinear_set.end());
    if(right_child->in_constraint) {
        right_child->TranslateToSemilinearSet();
    }
    semilinear_set.insert(semilinear_set.end(), right_child->semilinear_set.begin(), right_child->semilinear_set.end());

    in_constraint = false;
}

void SENode::Intersection() {
    //If both are still in constraint, just create a new polyhedron with all the constraints from both.
    if(left_child->in_constraint && right_child->in_constraint) {
        size_t cur_dim = left_child->sys_ineq.nr_of_columns();
        sys_ineq.set_nc(cur_dim);
        sys_ineq.append(left_child->sys_ineq);
        sys_ineq.append(right_child->sys_ineq);
        return;
    }
    in_constraint = false;
    //If only one is in constraint representation, we need to translate it
    if(left_child->in_constraint) {
        left_child->TranslateToSemilinearSet();
        dim = left_child->dim;
    }
    if(right_child->in_constraint) {
        right_child->TranslateToSemilinearSet();
        dim = right_child->dim;
    }

    if(left_child->semilinear_set.empty() || right_child->semilinear_set.empty()) {
        return;
    }

    //we find nonnegative solutions to (Q|-R) * x = v
    for(auto li : left_child->semilinear_set) {
        for(auto lj : right_child->semilinear_set) {
            //Q = li.second
            Matrix<Integer> Q = li.second.transpose();
            Matrix<Integer> A(Q);
            //-R = -lj.second
            for(auto vec: lj.second.get_elements()) {
                v_scalar_multiplication(vec, Integer(-1));
                A.append_column(vec);
            }

            pair< Matrix<Integer>, Matrix<Integer> > hybrid_ls;

            //first get solutions to homogeneous system (Q|-R) * x = 0
            Cone<Integer> homA(Type::equations, A);
            homA.compute(ConeProperty::HilbertBasis);
            Matrix<Integer> P = homA.getHilbertBasisMatrix();
            //we take the transpose of the matrix since the vectors spanning the set of solutions are the ROWS of the matrix
            P = P.transpose();
            //We project the solution set onto the components corresponding to how many vectors there are in Q.
            for(int i = 0; i < lj.second.nr_of_rows(); ++i) {
                P.remove_row(P.nr_of_rows() - 1);
            }
            hybrid_ls.second = Q.multiplication(P);
            hybrid_ls.second = hybrid_ls.second.transpose();

            //we get in a set all possible vectors of the form v = d - c
            set< pair< vector<Integer>, vector<Integer> > > rhs_vecs;
            for(auto c : li.first.get_elements()) {
                for(auto d : lj.first.get_elements()) {
                    size_t s = d.size();
                    for (size_t i = 0; i < s; i++) {
                        // d[i] -= c[i];
                        d[i] = -(d[i] - c[i]); //we keep -v instead of v, where v = d - c
                    }
                    rhs_vecs.insert(make_pair(d, c));
                }
            }

            map<vector<Integer>, bool> vectors_in_hls; //placeholder: ineficient

            //set dimenstion of hybrid linear set polytope
            hybrid_ls.first.set_nc(li.first[0].size());
            //The integer solutions to the system of linear equations for each d - c.
            for(auto elem : rhs_vecs) {
                Matrix<Integer> AA(A);
                AA.append_column(elem.first);
                
                Cone<Integer> poly(Type::inhom_equations, AA);
                poly.compute(ConeProperty::ModuleGenerators);
                Matrix<Integer> E = poly.getModuleGeneratorsMatrix();
                //We project the set of vectors onto the components corresponding to how many vectors there are in Q + 1 (+1 is for the fact that we computed inhomogeneous equations)
                E = E.transpose();
                for(int i = 0; i <= lj.second.nr_of_rows(); ++i) {
                    E.remove_row(E.nr_of_rows() - 1);
                }
                //We get the set of vectors Q * E
                E = Q.multiplication(E);
                //The vectors will be as columns and we want them rows since we represent hybrid linear sets' vectors as rows
                E = E.transpose();
                //Add vector c to the set of vectors
                for(size_t i = 0; i < E.nr_of_rows(); ++i) {
                    for(size_t j = 0; j < E.nr_of_columns(); ++j){
                        E[i][j] += elem.second[j];
                    }
                    // cout<<E[i]<<"\n";
                    if(!vectors_in_hls[E[i]]) {
                        vectors_in_hls[E[i]] = 1;
                        hybrid_ls.first.append(E[i]);
                    }
                }
            }

            semilinear_set.push_back(hybrid_ls);
        }
    }
}

void SENode::Complement() {
    vector<Hyperplane> hyperplanes;
    for(auto hl : semilinear_set) {
        //We get the support hyperplanes for each recession cone of each hybrid linear set.
        Cone<Integer> recession_cone(Type::cone, hl.second);
        recession_cone.compute(ConeProperty::SupportHyperplanes);
        vector<vector<Integer>> support_hyperplanes = recession_cone.getSupportHyperplanes();

        //We add the hyperplanes defining each cone in the hybrid linear set
        for(auto vec : hl.first.get_elements()) {
            for(auto v : support_hyperplanes) {
                hyperplanes.push_back(Hyperplane(v, -v_scalar_product(v, vec)));
            }
        }
    }

    //We get the arrangement of these hyperplanes
    Arrangement *arr = new Arrangement(dim);
    arr->ConstructArrangement(hyperplanes);
    SemilinearSet s = arr->GetZArrangement();
}
    
}