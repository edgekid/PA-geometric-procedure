#include "InternalTreeGen.h"

void InternalTreeGen::enterMultByConst1(LIAParser::MultByConst1Context * ctx) { 
    string text = ctx->children[2]->getText();
    term_scalar *= mpz_class(text, 10);
}
void InternalTreeGen::enterMultByConst0(LIAParser::MultByConst0Context * ctx) { 
    string text = ctx->children[0]->getText();
    term_scalar *= mpz_class(text, 10);
}

void InternalTreeGen::exitVar(LIAParser::VarContext * ctx) { 
    string text = ctx->children[0]->getText();
    int ind = var_to_num[text];
    if(!ind) {
        ind = var_to_num[text] = ++dim;
        vars.push_back(text);
        term_coeff.resize(dim);
    }
    term_coeff[ind - 1] += term_scalar;

    // cout<<ind<<" "<<term_scalar<<"\n";
}
void InternalTreeGen::exitConst(LIAParser::ConstContext * ctx) { 
    string text = ctx->children[0]->getText();
    term_a0 += term_scalar * mpz_class(text, 10);
}
void InternalTreeGen::exitMultByConst1(LIAParser::MultByConst1Context * ctx) { 
    string text = ctx->children[2]->getText();
    term_scalar /= mpz_class(text, 10);
}
void InternalTreeGen::exitMultByConst0(LIAParser::MultByConst0Context * ctx) { 
    string text = ctx->children[0]->getText();
    term_scalar /= mpz_class(text, 10);
}
void InternalTreeGen::exitTermOperation(LIAParser::TermOperationContext * ctx) { 
    if(ctx->children[1]->getText() == "-") {
        term_scalar *= (-1);
    }
}
void InternalTreeGen::exitSignedTerm(LIAParser::SignedTermContext * ctx) { 
    if(ctx->children[0]->getText() == "-") {
        term_scalar *= (-1);
    }
}

void InternalTreeGen::enterTermop(LIAParser::TermopContext * ctx) { 
    size_t type = ctx->getStart()->getType();

    switch(type) {
        case LIALexer::MINUS:
            term_scalar *= (-1);
            break;
        default:
            break;
    }
}

void InternalTreeGen::enterRelop(LIAParser::RelopContext * ctx) { 
    //RHS terms are subtracted from the LHS ones
    term_scalar *= (-1);
}

void InternalTreeGen::enterEveryRule(antlr4::ParserRuleContext * ctx) { 
    if(ctx->getRuleIndex() == 3) {
        //formula rule
        term_scalar = 1;
        term_a0 = 0;
        for(int i = 0; i < dim; ++i) {
            term_coeff[i] = 0;
        }
    }
}

void InternalTreeGen::exitTermRelation(LIAParser::TermRelationContext * ctx) { 
    string text = ctx->children[1]->getText();

    term_coeff.resize(dim + 1);

    if(text == "=") {
        term_coeff[dim] = term_a0;
        geometric::SENode *temp1 = new geometric::SENode(0, term_coeff);
        for(int i = 0; i <= dim; ++i) {
            term_coeff[i] *= (-1);
        }
        geometric::SENode *temp2 = new geometric::SENode(0, term_coeff);
        st.push(new geometric::SENode(0, -2, false, temp1, temp2));
    }
    else if(text == ">") {
        term_coeff[dim] = term_a0 - 1;
        st.push(new geometric::SENode(0, term_coeff));
    }
    else {
        term_coeff[dim] = term_a0;
        for(int i = 0; i <= dim; ++i) {
            term_coeff[i] *= (-1);
        }
        term_coeff[dim]--;
        st.push(new geometric::SENode(0, term_coeff));
    }
    
    term_coeff.resize(dim);
    term_scalar *= (-1);
}
void InternalTreeGen::exitQuant(LIAParser::QuantContext * ctx) { 
    string text = ctx->children[1]->getText();
    string quantifier = ctx->children[0]->getText();
    assert(st.size() != 0);
    geometric::SENode *temp1 = st.top();
    st.pop();

    if(quantifier == "forall") {
        //forall <=> !exists x: !(formula)
        temp1->negate();
        st.push(new geometric::SENode(0, var_to_num[text], true, temp1));
    }
    else {
        st.push(new geometric::SENode(0, var_to_num[text], false, temp1));
    }

    //quantified variables need to not be counted in the solution assignment
    vars[var_to_num[text] - 1] = "";
}
void InternalTreeGen::exitFormulaOperation(LIAParser::FormulaOperationContext * ctx) { 
    string text = ctx->children[1]->getText();
    assert(st.size() != 0);
    geometric::SENode *temp1 = st.top();
    st.pop();
    assert(st.size() != 0);
    geometric::SENode *temp2 = st.top();
    st.pop();

    st.push(new geometric::SENode(0, (text == "||" ? -1 : -2), false, temp1, temp2));
}
void InternalTreeGen::exitComplement(LIAParser::ComplementContext * ctx) { 
    st.top()->negate();
}
void InternalTreeGen::exitComplement2(LIAParser::Complement2Context * ctx) { 
    st.top()->negate();
}

geometric::SENode* InternalTreeGen::getResult() {
    assert(st.size() == 1);
    st.top()->setDim(dim + 1);
    return st.top();
}