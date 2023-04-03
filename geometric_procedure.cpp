#include "bits/stdc++.h"

#include "libnormaliz/libnormaliz.h"
#include "formula_tree.h"
#include "arrangement.h"

using namespace std;
using namespace libnormaliz;

typedef mpz_class Integer;

void example() {

    cout<<"-=-=-=-=-=-=-= EXAMPLE:\n";

    Matrix<Integer> first = readMatrix<Integer>("input.mat");;
    // vector<vector<Integer>> v = {{1, -5, -10}, {9, -5 ,-5}};
    Cone<Integer> cone(Type::inhom_inequalities, first);

    cone.compute(ConeProperty::HilbertBasis);

    vector<vector<Integer>> recessionCone = cone.getHilbertBasis();
    vector<vector<Integer>> maximalSubspace = cone.getMaximalSubspace();
    for(auto it: recessionCone) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    cout<<"a"<<endl;
    for(auto it: maximalSubspace) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }

    vector<vector<Integer>> polytope = cone.getModuleGenerators();
    cout<<"\nxD\n";
    for(auto it: polytope) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    cout<<"-=-=-=-=-=-=-=- EXAMPLE \n\n";
}

void test1() {
    vector<Integer> v{1, -5, 5};
    vector<Integer> v2{9, -5, 5};
    vector<Integer> v3{7, 1, 3};
    geometric::FormulaNode *in1 = new geometric::FormulaNode(-2, false, new geometric::FormulaNode(v), new geometric::FormulaNode(v2));
    geometric::FormulaNode *in2 = new geometric::FormulaNode(-2, false, in1, new geometric::FormulaNode(v3));

    
    vector<Integer> v4{-1, 2, -1};
    vector<Integer> v5{-20, 5, -17};
    geometric::FormulaNode *in3 = new geometric::FormulaNode(-2, false, new geometric::FormulaNode(v4), new geometric::FormulaNode(v5));
    // geometric::FormulaNode *in4 = new geometric::FormulaNode(-2, false, in2, in3);

    geometric::FormulaNode *u1 = new geometric::FormulaNode(-1, false, in2, in3);

    vector<Integer> v6{1, -3, 10};
    vector<Integer> v7{6, 9, -10};
    vector<Integer> v8{-5, 1, 7};
    geometric::FormulaNode *in4 = new geometric::FormulaNode(-2, false, new geometric::FormulaNode(v6), new geometric::FormulaNode(v7));
    geometric::FormulaNode *in5 = new geometric::FormulaNode(-2, false, in4, new geometric::FormulaNode(v8));
    // geometric::FormulaNode *in4 = new geometric::FormulaNode(-2, false, u1, in3);

    geometric::FormulaNode *in6 = new geometric::FormulaNode(-2, false, in5, u1);
    geometric::FormulaNode *acc = new geometric::FormulaNode(2, false, in6);

    acc->ComputeSubtree();

    acc->PrintSolutions();

    vector<Integer> ans = acc->GetSolution();
    if(!ans.empty()) {
        cout<<"Solution for x = "<<ans;
    }
    else {
        cout<<"No solution";
    }
}

int main() {
    geometric::Arrangement *a = new geometric::Arrangement(3);

    // vector<geometric::Hyperplane> h{{vector<Integer>{1, 2, 3}, 10}, 
    //                                 {vector<Integer>{0, 1, 0}, 0},
    //                                 {vector<Integer>{5, 3, 2}, 5},
    //                                 {vector<Integer>{0, 1, 0}, 1},
    //                                 {vector<Integer>{5, 1, 2}, 4}};

    vector<geometric::Hyperplane> h{{vector<Integer>{0, 1, 0}, 0}, 
                                    {vector<Integer>{0, 0, 1}, 0},
                                    {vector<Integer>{0, 1, 1}, 6}};

    // a->ConstructArrangement(h);

    example();

}
