#include "libnormaliz/libnormaliz.h"

namespace geometric {

using namespace libnormaliz;

typedef mpz_class Integer;
typedef mpq_class Rational;
typedef pair< vector<Integer>, Integer > Hyperplane;
typedef vector< pair< Matrix<Integer>, Matrix<Integer> > > SemilinearSet;
/*
Semilinear sets are finite unions of hybird linear sets.
Each hybrid linear set is a pair of 2 matrices - the first contains the vectors of the polytope, the second the basis of the recession cone. 
The vectors are the matrix's rows.
*/


class SENode {

private:
    int op; //the operation the node is computing between its 2 children. If empty, it is a leaf
    /*
    0 - leaf
    -1 - union
    -2 - intersection
    larger than 0 - projection on the op-th component
    */
    
    bool complement;
    
    SENode* left_child;
    SENode* right_child;

    void init();

public:
    SENode();
    SENode(int dim, short op= 0, bool complement = false, SENode* left = nullptr, SENode* right = nullptr);
    SENode(int dim, const vector<Integer>& v, short op = 0, bool complement = false, SENode* left = nullptr, SENode* right = nullptr);

    vector<Integer> GetSolution(); //returns a solution if semi-linear set is non-empty. Returns empty vector otherwise.
    void PrintSolutions(); //prints all hybrid linear sets inside semilinear_set

    void ComputeSubtree(bool first_vertex = true);
    void ComputeOperation();
    void TranslateToSemilinearSet();

    void Complement();
    void Intersection();
    void Union();
    void ProjectCoordinateGen(int c); //project away coordinate c for the polyhedra in generator representation
    void ProjectCoordinateConstr(int c); //project away coordinate c for the polyhedra in constraint representation
    
    bool in_constraint; //0 if the node represents a polyhedron in generator representation; 1 if in constraint representation
    int dim;
    vector<int> dv;

    SemilinearSet semilinear_set; //the semilinear set this node represents if it is in generator representation
    
    Matrix<Integer> sys_ineq; //the system of inequalities(half spaces) this node contains if it is in constraint representation
};

}