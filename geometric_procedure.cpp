#include "bits/stdc++.h"

#include "libnormaliz/libnormaliz.h"
#include "semilinear_expression.h"
#include "arrangement.h"
// #include "semilinear_set_operations.h"

using namespace std;
using namespace libnormaliz;
using namespace geometric;

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
    geometric::SENode *in1 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v), new geometric::SENode(3, v2));
    geometric::SENode *in2 = new geometric::SENode(3, -2, false, in1, new geometric::SENode(3, v3));

    
    vector<Integer> v4{-1, 2, -1};
    vector<Integer> v5{-20, 5, -25};
    geometric::SENode *in3 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v4), new geometric::SENode(3, v5));
    // geometric::SENode *in4 = new geometric::SENode(-2, false, in2, in3);

    geometric::SENode *u1 = new geometric::SENode(3, -1, false, in2, in3);

    vector<Integer> v6{1, -3, 10};
    vector<Integer> v7{6, 9, -10};
    vector<Integer> v8{-5, 1, 7};
    geometric::SENode *in4 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v6), new geometric::SENode(3, v7));
    geometric::SENode *in5 = new geometric::SENode(3, -2, false, in4, new geometric::SENode(3, v8));
    // geometric::SENode *in4 = new geometric::SENode(-2, false, u1, in3);

    geometric::SENode *in6 = new geometric::SENode(3, -2, true, in5, u1);
    // geometric::SENode *acc = new geometric::SENode(3, 2, true, u1);

    in6->ComputeSubtree();

    in6->PrintSolutions();

    vector<Integer> ans = in6->GetSolution();
    if(!ans.empty()) {
        cout<<"Solution for x = "<<ans;
    }
    else {
        cout<<"No solution";
    }
}

void test2() {
    vector<Integer> v{1, 2, 0};
    vector<Integer> v2{-1, -2, 0};
    geometric::SENode *in1 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v), new geometric::SENode(3, v2));
    geometric::SENode *acc = new geometric::SENode(3, 2, true, in1);

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

// void memtest(){
//     SemilinearSet s;
//     Matrix<Integer> first = readMatrix<Integer>("input.mat");
//     Matrix<Integer> second = readMatrix<Integer>("input2.mat");
//     HybridLS h = make_pair(first, second);
//     geometric::get_linearly_independent_sl(s, h);

//     int d;
//     cin>>d;
//     vector<Integer> v(d);
//     for(int i = 0; i < d; ++i)cin>>v[i];

//     cout<<get_membership(v, s);
// }


int main() {
    // geometric::Arrangement *a = new geometric::Arrangement(2);

    // vector<geometric::Hyperplane> h{{vector<Integer>{-6, -1}, 3}, 
    //                                 {vector<Integer>{7, 1}, -3},
    //                                 {vector<Integer>{1, 0}, 0},
    //                                 {vector<Integer>{0, 1}, -3},
    //                                 {vector<Integer>{-6, -1}, 2},
    //                                 {vector<Integer>{7, 1}, -2},
    //                                 {vector<Integer>{0, 1}, -2},
    //                                 {vector<Integer>{-6, -1}, 1},
    //                                 {vector<Integer>{7, 1}, -1}};

    // vector<geometric::Hyperplane> h{{vector<Integer>{0, 1, 0}, 0}, 
    //                                 {vector<Integer>{0, 0, 1}, 0},
    //                                 {vector<Integer>{0, 1, 1}, 6}};

    // a->ConstructArrangement(h);

    // example();

    test1();
    
    
    // Matrix<Integer> first = readMatrix<Integer>("input.mat");
    // Matrix<Integer> second = readMatrix<Integer>("second.mat");
    // Matrix<Integer> third = readMatrix<Integer>("third.mat");
    // Cone<Integer> cone(Type::vertices, first, Type::cone, second, Type::inhom_inequalities, third);
    // cone.compute(ConeProperty::ConeDecomposition);
    
    // pair<vector<SHORTSIMPLEX<Integer>>, Matrix<Integer>> decomp = cone.getConeDecomposition();
    // for(int i = 0; i < decomp.first.size(); ++i) {
    //     for(auto k : decomp.first[i].key) {
    //         cout<<decomp.second[k]<<"\n";
    //     }   
    //     cout<<decomp.first[i].Excluded;
    //     cout<<endl;   
    // }
}
