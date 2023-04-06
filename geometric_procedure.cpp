#include "bits/stdc++.h"

#include "libnormaliz/libnormaliz.h"
#include "semilinear_expression.h"
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
    geometric::SENode *in1 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v), new geometric::SENode(3, v2));
    geometric::SENode *in2 = new geometric::SENode(3, -2, false, in1, new geometric::SENode(3, v3));

    
    vector<Integer> v4{-1, 2, -1};
    vector<Integer> v5{-20, 5, -17};
    geometric::SENode *in3 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v4), new geometric::SENode(3, v5));
    // geometric::SENode *in4 = new geometric::SENode(-2, false, in2, in3);

    geometric::SENode *u1 = new geometric::SENode(3, -1, false, in2, in3);

    vector<Integer> v6{1, -3, 10};
    vector<Integer> v7{6, 9, -10};
    vector<Integer> v8{-5, 1, 7};
    geometric::SENode *in4 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v6), new geometric::SENode(3, v7));
    geometric::SENode *in5 = new geometric::SENode(3, -2, false, in4, new geometric::SENode(3, v8));
    // geometric::SENode *in4 = new geometric::SENode(-2, false, u1, in3);

    geometric::SENode *in6 = new geometric::SENode(3, -2, false, in5, u1);
    geometric::SENode *acc = new geometric::SENode(3, 2, false, in6);

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

    // vector<geometric::Hyperplane> h{{vector<Integer>{0, 1, 0}, 0}, 
    //                                 {vector<Integer>{0, 0, 1}, 0},
    //                                 {vector<Integer>{0, 1, 1}, 6}};

    // a->ConstructArrangement(h);

    // example();

    Matrix<Integer> sh(0, 3);
    sh.append(vector<Integer>{1,2,3});
    sh.append(vector<Integer>{1,-2,-3});
    sh.resize_columns(2);
    for(int i = 0 ;i < sh.nr_of_rows(); ++i) {
        cout<<sh[i];
    }

    int n,m,d;
    cin>>n>>m>>d;

    // Matrix<Integer> first = readMatrix<Integer>("input.mat");
    // Matrix<Integer> second = readMatrix<Integer>("input2.mat");
    Matrix<Integer> v(0,d);
    for(int i = 0; i < n; ++i) {
        vector<Integer> vv(d);
        for(int j = 0; j < d; ++j) {
            cin>>vv[j];
        }
        v.append(vv);
    }
    Matrix<Integer> v2(0,d);
    for(int i = 0; i < m; ++i) {
        vector<Integer> vv(d);
        for(int j = 0; j < d; ++j) {
            cin>>vv[j];
        }
        v2.append(vv);
    }
    // vector<vector<Integer>> v = {{1, -5, -10}, {9, -5 ,-5}};
    Cone<Integer> c(Type::inhom_inequalities, v2, Type::inhom_equations, v);

    cout<<"a";


    // test1();

    // Cone<Integer> c(Type::vertices, vector<vector<mpq_class>>{{3, 2, 6}, {2, 5, 2}}, Type::cone, vector<vector<mpq_class>>{{3, 2}, {1, 0}});

    c.compute(ConeProperty::HilbertBasis);

    vector<vector<Integer>> recessionCone = c.getHilbertBasis();
    for(auto it: recessionCone) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    cout<<"a"<<endl;
    vector<vector<Integer>> maximalSubspace = c.getMaximalSubspace();
    for(auto it: maximalSubspace) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }

    vector<vector<Integer>> polytope = c.getModuleGenerators();
    cout<<"\nxD\n";
    for(auto it: polytope) {
        for(auto itt: it) {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
}
