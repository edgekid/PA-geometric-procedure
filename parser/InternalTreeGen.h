#include <map>
#include <vector>
#include <stack>
#include "LIAParser.h"
#include "LIALexer.h"
#include "../semilinear_expression.h"
#include "LIABaseListener.h"
#include <gmpxx.h>

using namespace std;

class InternalTreeGen : public LIABaseListener {

private:
    map<string, int> var_to_num;
    stack<geometric::SENode*> st;
    int dim = 0;

    vector<mpz_class> term_coeff;
    mpz_class term_scalar;
    mpz_class term_a0;

public:
    void enterMultByConst0(LIAParser::MultByConst0Context * ctx) override;
    void exitMultByConst0(LIAParser::MultByConst0Context * ctx) override;

    void enterMultByConst1(LIAParser::MultByConst1Context * ctx) override;
    void exitMultByConst1(LIAParser::MultByConst1Context * ctx) override;

    void exitSignedTerm(LIAParser::SignedTermContext * ctx) override;

    void exitTermOperation(LIAParser::TermOperationContext * ctx) override;

    void exitConst(LIAParser::ConstContext * ctx) override;

    void exitVar(LIAParser::VarContext * ctx) override;

    void enterEveryRule(antlr4::ParserRuleContext * ctx) override;

    void exitTermRelation(LIAParser::TermRelationContext * ctx) override;

    void exitQuant(LIAParser::QuantContext * ctx) override;

    void exitFormulaOperation(LIAParser::FormulaOperationContext * ctx) override;

    void enterRelop(LIAParser::RelopContext * ctx) override;

    void enterTermop(LIAParser::TermopContext * ctx) override;

    void exitComplement(LIAParser::ComplementContext * ctx) override;
    void exitComplement2(LIAParser::Complement2Context * ctx) override;

    geometric::SENode* getResult();

    vector<string> vars;

};
