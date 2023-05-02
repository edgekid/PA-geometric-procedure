#include "bits/stdc++.h"

#include "libnormaliz/libnormaliz.h"
#include "semilinear_expression.h"
#include "arrangement.h"
// #include "semilinear_set_operations.h"

using namespace std;
using namespace libnormaliz;
using namespace geometric;

typedef mpz_class Integer;

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

    geometric::SENode *in6 = new geometric::SENode(3, -2, false, in5, u1);
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

void test3() {
    //this is the orange polytope in test1() but complemented
    vector<Integer> v6{1, -3, 10};
    vector<Integer> v7{6, 9, -10};
    vector<Integer> v8{-5, 1, 7};
    geometric::SENode *in4 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v6), new geometric::SENode(3, v7));
    geometric::SENode *in5 = new geometric::SENode(3, -2, true, in4, new geometric::SENode(3, v8));

    // geometric::SENode *acc = new geometric::SENode(3, 2, true, u1);

    in5->ComputeSubtree();

    in5->PrintSolutions();

    vector<Integer> ans = in5->GetSolution();
    if(!ans.empty()) {
        cout<<"Solution for x = "<<ans;
    }
    else {
        cout<<"No solution";
    }
}

int main() {
    test2();
}
