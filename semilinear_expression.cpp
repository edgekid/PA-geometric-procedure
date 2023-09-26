#include "semilinear_expression.h"
#include "arrangement.h"
#include "utils.h"
#include "semilinear_set_operations.h"

namespace geometric {

void SENode::init() {
    in_constraint = true;
    dv.resize(dim);
    trivial = 0;
}

SENode::SENode() : dim(0), op(0), complement(false) {
    sys_ineq = Matrix<Integer>(0);
    init();
}

SENode::SENode(int dim, short op, bool complement, SENode* left, SENode* right) : dim(dim), op(op), complement(complement), left_child(left), right_child(right) {
    sys_ineq = Matrix<Integer>(0, dim);
    init();
}

SENode::SENode(int dim, const vector<Integer>& v, short op, bool complement, SENode* left, SENode* right) : dim(dim), op(op), complement(complement), left_child(left), right_child(right) {
    sys_ineq = Matrix<Integer>(v);
    init();
    Integer s = 0;
    for(int i = 0; i < v.size() - 1; ++i) {
        s += (v[i] != 0);
    }
    trivial = (v[v.size() - 1] != 0 && !s);
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

    if(complement) {
        Complement();
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
                left_child->TranslateToSemilinearSet();
                in_constraint = false;
                trivial = left_child->trivial;
            }
            left_child->ProjectCoordinateGen(op);
            semilinear_set = left_child->semilinear_set;
            dv = left_child->dv;
            dim = left_child->dim;
            break;
    }
}

//translate the polyhedrons into a semilinear set
void SENode::TranslateToSemilinearSet() {
    in_constraint = false;
    if(trivial) { 
        //the system solutions is empty - we skip
        dim--;
        return;
    }

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

    //Get rid of homogenizing coordinates (0 and 1)
    dim--;
    polytope.resize_columns(dim);
    recession_cone.resize_columns(dim);

    semilinear_set.push_back(make_pair(polytope, recession_cone));
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
        dim = left_child->dim;
    }
    if(right_child->in_constraint) {
        right_child->TranslateToSemilinearSet();
        dim = right_child->dim;
    }
    
    add(semilinear_set, left_child->semilinear_set, right_child->semilinear_set);

    in_constraint = false;
}

void SENode::Intersection() {
    //If both are still in constraint, just create a new polyhedron with all the constraints from both.
    if(left_child->in_constraint && right_child->in_constraint) {
        if(left_child->trivial || right_child->trivial) {
            trivial = true;
            return;
        }
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

    intersect(semilinear_set, left_child->semilinear_set, right_child->semilinear_set);
}

void SENode::Complement() {
    //make all hybrid linear sets in current semilinear set have linearly independent (proper) periods
    SemilinearSet proper_sls;
    for(auto h : semilinear_set) {
        get_linearly_independent_sl(proper_sls, h);  
    }

    vector<Hyperplane> hyperplanes;
    map<Hyperplane, bool> included;
    vector<Integer> sv(dim);
    for(auto hl : proper_sls) {
        //We get the support hyperplanes for each recession cone of each hybrid linear set.
        vector<vector<Integer>> support_hyperplanes;
        if(hl.second.nr_of_rows()) {
            Cone<Integer> recession_cone(Type::cone, hl.second);
            recession_cone.compute(ConeProperty::SupportHyperplanes);
            support_hyperplanes = recession_cone.getSupportHyperplanes();
        }

        //We add the hyperplanes defining each cone in the hybrid linear set
        for(auto vec : hl.first.get_elements()) {
            for(auto v : support_hyperplanes) {
                Hyperplane h = Hyperplane(v, v_scalar_product(v, vec));
                vector<Integer> v_m = v;
                v_scalar_multiplication(v_m, Integer(-1));
                Hyperplane h_m = Hyperplane(v_m, -v_scalar_product(v, vec));
                if(!included[h] && !included[h_m]) {//we make sure we dont include the same hyperplane twice
                    hyperplanes.push_back(h);
                    included[h] = 1; 
                }
            }
            //We include in the hybrid linear set the hyperplanes for the standard basis - used to separate points from hybrid linear sets that have no periods or lie on the same supporting hyperplanes
            for(int i = 0; i < dim; ++i) {
                sv[i]++;
                Hyperplane h = Hyperplane(sv, v_scalar_product(sv, vec));
                sv[i] -= 2;
                Hyperplane h_m = Hyperplane(sv, -v_scalar_product(sv, vec));
                sv[i] += 2;
                if(!included[h] && !included[h_m]) {//we make sure we dont include the same hyperplane twice
                    hyperplanes.push_back(h);
                    included[h] = 1; 
                }
                sv[i]--;
            }
        }
    }

    //We get the periodic sets of the hybrid linear sets of the current semilinear set with the periodic vectors as columns
    vector<Matrix<Integer>> periodic_sets;
    for(auto hl : proper_sls) {
        periodic_sets.push_back(hl.second.transpose());
    }

    //We get the arrangement of these hyperplanes
    Arrangement *arr = new Arrangement(hyperplanes, periodic_sets, dim);
    arr->ConstructArrangement();
    SemilinearSet s = arr->GetZArrangement();

    semilinear_set.clear();
    map<vector<vector<Integer>>, int> vis_pset;
    for(auto h : s) {
        Matrix<Integer> E(0, dim);
        //get the base points in hybrid linear set that are not in the initial semilinear set.
        int nr = h.first.nr_of_rows();
        for(int i = 0; i < nr; ++i) {
            if(!get_membership(h.first[i], proper_sls)) {
                E.append(h.first[i]);
            }
        }

        if(!E.nr_of_rows()) {
            continue;
        }

        //making sure periodic sets are within stricly one hybrid linear set
        int j = vis_pset[h.second.get_elements()];
        if(j) {
            semilinear_set[j - 1].first.append(E);
        }
        else {
            semilinear_set.push_back(make_pair(E, h.second));
            vis_pset[h.second.get_elements()] = semilinear_set.size();
        }
    }
}

void SENode::setDim(int d) {
    dim = d;
    size_t tmp = sys_ineq.nr_of_columns();

    sys_ineq.resize_columns(dim);
    if(sys_ineq.nr_of_rows()) {
        //terminal node
        sys_ineq[0][dim - 1] = sys_ineq[0][tmp - 1];
        if(tmp != dim) {
            sys_ineq[0][tmp - 1] = 0;
        }
    }
    dv.resize(dim);
    if(left_child) {
        left_child->setDim(d);
    }
    if(right_child) {
        right_child->setDim(d);
    }
}

void SENode::negate() {
    complement = !complement;
}

string SENode::printTree(int no_tabs) {
    string s = "";
    for(int i = 0; i < no_tabs; ++i) s += "\t";
    s += "(Operation " + to_string(op) + ", Complement " + to_string(complement) + ", Dim " + to_string(dim) + ": ";
    if(!op) {
        s += "[ ";
        for(auto it : sys_ineq[0]) {
            s += it.get_str() + " ";
        }
        s += "]";
    }
    s += "\n";
    if(left_child) {
        s += left_child->printTree(no_tabs + 1);
    }
    if(right_child) {
        s += right_child->printTree(no_tabs + 1);
    }
    for(int i = 0; i < no_tabs; ++i) s += "\t";
    s += ")\n";
    return s;
}

}