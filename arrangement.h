#include "libnormaliz/libnormaliz.h"

namespace geometric {

using namespace libnormaliz;

typedef mpz_class Integer;
typedef mpq_class Rational;
typedef pair< vector<Integer>, Integer > Hyperplane;
typedef vector< pair< Matrix<Integer>, Matrix<Integer> > > SemilinearSet;

//This struct is used to describe a face's polytope and recession cone.
struct Polyhedron {
    set<vector<Rational>> vertices; //polytope
    set<vector<Rational>> rays; //recession cone

    void add(const Polyhedron &a) {
        for(const auto &it : a.vertices) {
            vertices.insert(it);
        }
        for(const auto &it : a.rays) {
            rays.insert(it);
        }
    }
    int size() {
        return vertices.size() + rays.size();
    }
};

class Arrangement {

private:

    struct FaceNode {
        vector<Rational> point; //a random point strictly inside the face
        Polyhedron* face;
        set<FaceNode*> subfaces;
        set<FaceNode*> superfaces;
        vector<int> aff; //set of indices (wrt to Arr and RHS) of hyperplanes defining the affine subspace that contains the face
        int dim; //the dimension of the face

        FaceNode(const vector<int> &aff, int dim) : dim(dim), aff(aff) {} 
    };

    enum COLOR { 
        WHITE, //the face does not intersect the new hyperplane
        GREEN, //used to distinguish 2faces in queue in phase 2
        PINK, //face which intersect h at border only
        RED, //face which properly intersect h
        CRIMSON, //face contained in h
        GREY, //face is intersected at border only at the end
        BLACK, //face is contained in h at the end
        BROWN //delete the face after adding new hyperplane
    };

    vector<Hyperplane> hyperplanes; //set of hyperplanes defining the arrangement
    vector<Matrix<Integer>> periodic_sets; //a list of the periodic sets describing the semilinear set whose Z-Arrangement we want to make 
    int dim; //dimension of the space the arrangement spans
    int d; //dimension of the actual space the arrangement is in
    map<vector<short>, FaceNode*> initial_nodes; //a map mapping position vectors to the faces for the initial arrangement
    FaceNode *first, *last; //The (-1)-dimensional and (d+1)-dimensional faces
    Matrix<Integer> Arr; //the set of hyperplanes currently in arrangement - the rows are the coefficients for each variables
    vector<Integer> RHS; //the set of constants for each hyperplane currently in the arrangement
    Matrix<Integer> AddH; //set containing the additional hyperplanes added to the initial arrangement to make all initial normal vectors span R^dim
    map<FaceNode*, Hyperplane> mp_etoh; //for initial arrangement - maps an edge to the indice of a hyperplane that intersects the edge in a single point multiplied by the direction; used to get a point strictly inside this unbounded edge

    void InitIncidenceGraph(vector<short> &v);
    void AddHyperplane(Hyperplane h);
    void CalculateInsidePoint(FaceNode* f);

public:
    Arrangement(const vector<Hyperplane> &hyperplanes, const vector<Matrix<Integer>> &p_sets, int dim = 0);
    void ConstructArrangement();
    vector<Polyhedron> GetArrangement(); //Get the arrangement expressed as set of conex polyhedra
    
    /* Z-Arrangement = {Z1, Z2, ... Zn} is a partition of Z^d that satisfies the following conditions:
     * (1) Zi is a hybrid lineat set L(Ci, Qi)
     * (2) For each of the initial polyhedral cones, Zi is either inside them or doesn't intersect them
     * (3) For each of the initial periodic set Pj, if Zi is inside the polyhedral cone spanned by Pj, then Qi is in L(0, Pj)
     * 
     * In order to get the Z-Arrangement periodic_sets needs to be formed of sets of linearly independent periods
     */
    SemilinearSet GetZArrangement(); //Get the arrangement expressed as a semilinear set

};

}