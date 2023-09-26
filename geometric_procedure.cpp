#include "bits/stdc++.h"

#include "libnormaliz/libnormaliz.h"
#include "arrangement.h"
#include "antlr4-runtime.h"
#include "parser/InternalTreeGen.h"

using namespace std;
using namespace libnormaliz;
using namespace geometric;
using namespace antlr4;

typedef mpz_class Integer;

void test1() {
    //(((x -5*y > -6) && (9*x > 5*y - 6) && (4 > -7*x -y)) || ((-x+2*y > 0 && -20*x + y*5 -16 > 0))) && (x-y*3 > -11 && x*6 + 9*y > 9 && (-5*x > -8 -y))
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
    //!(exists y : (x + 2*y = 0))
    vector<Integer> v{1, 2, 0};
    vector<Integer> v2{-1, -2, 0};
    geometric::SENode *in1 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v), new geometric::SENode(3, v2));
    geometric::SENode *acc = new geometric::SENode(3, 2, true, in1);

    cout<<acc->printTree();

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
    // !((x-y*3 > -11 && x*6 + 9*y > 9) && (-5*x > -8 -y))
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

void test4() {
    //(x + 5 < y) || (x - 10 = -2*y)
    vector<Integer> v1{-1, 1, -6};
    vector<Integer> v2{1, 2, -10};
    vector<Integer> v3{-1, -2, 10};
    geometric::SENode *aa = new geometric::SENode(3, v1);
    geometric::SENode *ab = new geometric::SENode(3, v2);
    geometric::SENode *in1 = new geometric::SENode(3, -2, false, new geometric::SENode(3, v2), new geometric::SENode(3, v3));
    geometric::SENode *u1 = new geometric::SENode(3, -1, false, in1, aa);

    u1->ComputeSubtree();

    u1->PrintSolutions();

    vector<Integer> ans = u1->GetSolution();
    if(!ans.empty()) {
        cout<<"Solution for x = "<<ans;
    }
    else {
        cout<<"No solution";
    }
}

int main() {
    std::cout<<"Give as input a LIA formula. Press Ctrl+D to signal EOF.\n";

    string line, stream = "";
    while (getline(std::cin, line)) {
        stream += line;
    }

    ANTLRInputStream input(stream);
    LIALexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LIAParser parser(&tokens);

    tree::ParseTree *tree = parser.start(); // Replace with the entry point of your grammar
    InternalTreeGen listener; // Instantiate your custom listener
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    string parseTreeS = tree->toStringTree(&parser);
    // cout<<parseTreeS<<"\n";

    geometric::SENode* a = listener.getResult();
    // cout<<a->printTree();
    a->ComputeSubtree();
    // a->PrintSolutions();
    vector<Integer> ans = a->GetSolution();
    if(!ans.empty()) {
        std::cout<<"Valid assignment: (";

        vector<string> vars;
        for(auto it : listener.vars) {
            if(it != "") {
                //unquantified variable
                vars.push_back(it);
            }
        }

        for(int i = 0; i < ans.size() - 1; ++i) {
            std::cout<<vars[i]<<" = "<<ans[i]<<", ";
        }
        std::cout<<vars[ans.size() - 1]<<" = "<<ans[ans.size() - 1]<<")\n";
    }
    else {
        std::cout<<"No solution.\n";
    }
}
