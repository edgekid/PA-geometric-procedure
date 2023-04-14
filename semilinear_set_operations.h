#include "libnormaliz/libnormaliz.h"

namespace geometric {

using namespace libnormaliz;

typedef mpz_class Integer;
typedef pair< Matrix<Integer>, Matrix<Integer> > HybridLS;
typedef vector< HybridLS > SemilinearSet;

//adds to s the intersection between a and b
inline void intersect(SemilinearSet &s, SemilinearSet &a, SemilinearSet &b) {
    
    if(a.empty() || b.empty()) {
        return;
    }

    //we find nonnegative solutions to (Q|-R) * x = v
    for(auto li : a) {
        for(auto lj : b) {

            assert(li.first.nr_of_rows() != 0);
            assert(lj.first.nr_of_rows() != 0);
            int dim = li.first.nr_of_columns();
            if(!li.second.nr_of_rows()) {
                li.second.set_nc(dim);
            }
            if(!lj.second.nr_of_rows()) {
                lj.second.set_nc(dim);
            }

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
            hybrid_ls.first.set_nc(dim);
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

            s.push_back(hybrid_ls);
        }
    }
}


//computes s as an union with a and b
inline void add(SemilinearSet &s, SemilinearSet &a, SemilinearSet &b) {
    s.insert(s.end(), a.begin(), a.end());
    s.insert(s.end(), b.begin(), b.end());
}

inline void get_linearly_independent_subsets(vector<Matrix<Integer>> &s, const Matrix<Integer> &P, vector<int> &indices, int rank) {
    //iterate over all possible linearly independent subsets of P of maximal cardinality
    int n = (int)P.nr_of_rows();
    if(indices.size() == rank) {
        Matrix<Integer> M(0, (int)P.nr_of_columns());
        for(auto i : indices) {
            M.append(P[i]);
        }
        if(M.rank() == rank) {
            //linearly independent set of maximal cardinality
            s.push_back(M);
        }
        return;
    }
    int start = (indices.empty() ? 0 : indices.back() + 1);
    for(int i = start; i < n; ++i) {
        indices.push_back(i);
        get_linearly_independent_subsets(s, P, indices, rank);
        indices.pop_back();
    }
    return;
}

//gets as input a hybrid linear set and returns a semilinear set with linearly independent vectors
inline void get_linearly_independent_sl(SemilinearSet &s, const HybridLS &h) {
    if(!h.second.nr_of_rows()) {
        s.push_back(h);
        return;
    }

    Matrix<Integer> P = h.second;
    int dim = h.first.nr_of_columns();

    vector<Matrix<Integer>> Q;
    vector<int> v;
    get_linearly_independent_subsets(Q, P, v, P.rank());

    for(auto Qi : Q) {
        //we get the lattice points inside the fundamental parallelepiped of the set Qi of vectors
        Cone<Integer> paral(Type::cone, Qi);
        paral.compute(ConeProperty::ModuleGeneratorsOverOriginalMonoid);
        Matrix<Integer> M = paral.getModuleGeneratorsOverOriginalMonoidMatrix();

        //we take the intersection with these points and the integer points of the cone generated by P
        SemilinearSet t, a, b;
        if(M.nr_of_rows()) {
            a.push_back(make_pair(M, Matrix<Integer>(0, dim)));
        }
        b.push_back(make_pair(Matrix<Integer>(1, dim), P));
        intersect(t, a, b);

        //Create the hybrid linear set for the set Qi of periods
        Matrix<Integer> A(0, dim);
        for(int i = 0; i < (int)t[0].first.nr_of_rows(); ++i) {
            for(int j = 0; j < (int)h.first.nr_of_rows(); ++j) {
                A.append(v_add(h.first[j], t[0].first[i]));
            }
        }
        s.push_back(make_pair(A, Qi));
    }
    
}

//method which computes whether a given point v is inside a given semilinear set which is assumed to have all periodic sets linearly independent.
inline bool get_membership(vector<Integer> &v, SemilinearSet &s) {
    for(auto h : s) {
        assert(v.size() == h.first.nr_of_columns());
        size_t len = v.size();
        if(!h.second.nr_of_rows()) {
            for(int i = 0; i < (int)h.first.nr_of_rows(); ++i) {
                if(h.first[i] == v) {
                    return true;
                }
            }
            continue;
        } 
        Matrix<Integer> P = h.second.transpose();
        for(int i = 0; i < (int)h.first.nr_of_rows(); ++i) {
            Integer denom = 0;
            vector<Integer> c = h.first[i];
            for (size_t j = 0; j < len; ++j) {
                c[j] = v[j] - c[j];
            }
            vector<Integer> p = P.solve_rectangular(c, denom);

            if(denom == 1 && p.size()) {
                //solution is integer so system is satisfiable. Thus, v is in the hybrid linear set
                bool is_positive = true;
                for(size_t i = 0; i < p.size(); ++i) {
                    if(p[i] < 0) {
                        is_positive = false;
                        break;
                    }
                }
                if(is_positive) {
                    return true;
                }
            }
        }
    }
    return false;
}

}