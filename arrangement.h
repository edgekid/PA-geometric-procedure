#include "libnormaliz/libnormaliz.h"

namespace geometric {

using namespace libnormaliz;

typedef mpz_class Integer;
typedef mpq_class Rational;
typedef pair< vector<Integer>, Integer > Hyperplane;

class Arrangement {

private:

    //This struct is used to describe a face's polytope and recession cone.
    struct Polyhedron {
        vector<vector<Rational>> vertices; //polytope
        vector<vector<Rational>> rays; //recession cone
    };

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

    int dim; //dimension of the space the arrangement spans
    int d; //dimension of the space the arrangement is in
    map<vector<short>, FaceNode*> initial_nodes; //a map mapping position vectors to the faces for the initial arrangement
    FaceNode *first, *last; //The (-1)-dimensional and (d+1)-dimensional faces
    Matrix<Integer> Arr; //the set of hyperplanes currently in arrangement - the rows are the coefficients for each variables
    vector<Integer> RHS; //the set of constants for each hyperplane currently in the arrangement
    Matrix<Integer> AddH; //set containing the additional hyperplanes added to the initial arrangement to make all initial normal vectors span R^dim

    map<FaceNode*, Hyperplane> mp_etoh; //for initial arrangement - maps an edge to the indice of a hyperplane that intersects the edge in a single point multiplied by the direction; used to get a point strictly inside this unbounded edge

bool b = 1;

    void InitIncidenceGraph(vector<short> &v);
    void AddHyperplane(Hyperplane h);
    void CalculateInsidePoint(FaceNode* f);

public:
    Arrangement(int dim = 0);
    void ConstructArrangement(vector<Hyperplane> hyperplanes);

};

}