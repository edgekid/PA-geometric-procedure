
// Generated from LIA.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LIAListener.h"


/**
 * This class provides an empty implementation of LIAListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LIABaseListener : public LIAListener {
public:

  virtual void enterStart(LIAParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(LIAParser::StartContext * /*ctx*/) override { }

  virtual void enterTermTmp(LIAParser::TermTmpContext * /*ctx*/) override { }
  virtual void exitTermTmp(LIAParser::TermTmpContext * /*ctx*/) override { }

  virtual void enterTermOperation(LIAParser::TermOperationContext * /*ctx*/) override { }
  virtual void exitTermOperation(LIAParser::TermOperationContext * /*ctx*/) override { }

  virtual void enterMultByConst0(LIAParser::MultByConst0Context * /*ctx*/) override { }
  virtual void exitMultByConst0(LIAParser::MultByConst0Context * /*ctx*/) override { }

  virtual void enterSignedTerm(LIAParser::SignedTermContext * /*ctx*/) override { }
  virtual void exitSignedTerm(LIAParser::SignedTermContext * /*ctx*/) override { }

  virtual void enterMultByConst1(LIAParser::MultByConst1Context * /*ctx*/) override { }
  virtual void exitMultByConst1(LIAParser::MultByConst1Context * /*ctx*/) override { }

  virtual void enterVar(LIAParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(LIAParser::VarContext * /*ctx*/) override { }

  virtual void enterConst(LIAParser::ConstContext * /*ctx*/) override { }
  virtual void exitConst(LIAParser::ConstContext * /*ctx*/) override { }

  virtual void enterParen1(LIAParser::Paren1Context * /*ctx*/) override { }
  virtual void exitParen1(LIAParser::Paren1Context * /*ctx*/) override { }

  virtual void enterQuant(LIAParser::QuantContext * /*ctx*/) override { }
  virtual void exitQuant(LIAParser::QuantContext * /*ctx*/) override { }

  virtual void enterComplement(LIAParser::ComplementContext * /*ctx*/) override { }
  virtual void exitComplement(LIAParser::ComplementContext * /*ctx*/) override { }

  virtual void enterParen2(LIAParser::Paren2Context * /*ctx*/) override { }
  virtual void exitParen2(LIAParser::Paren2Context * /*ctx*/) override { }

  virtual void enterFormulaTmp(LIAParser::FormulaTmpContext * /*ctx*/) override { }
  virtual void exitFormulaTmp(LIAParser::FormulaTmpContext * /*ctx*/) override { }

  virtual void enterFormulaOperation(LIAParser::FormulaOperationContext * /*ctx*/) override { }
  virtual void exitFormulaOperation(LIAParser::FormulaOperationContext * /*ctx*/) override { }

  virtual void enterTermRelation(LIAParser::TermRelationContext * /*ctx*/) override { }
  virtual void exitTermRelation(LIAParser::TermRelationContext * /*ctx*/) override { }

  virtual void enterParen3(LIAParser::Paren3Context * /*ctx*/) override { }
  virtual void exitParen3(LIAParser::Paren3Context * /*ctx*/) override { }

  virtual void enterComplement2(LIAParser::Complement2Context * /*ctx*/) override { }
  virtual void exitComplement2(LIAParser::Complement2Context * /*ctx*/) override { }

  virtual void enterRelop(LIAParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(LIAParser::RelopContext * /*ctx*/) override { }

  virtual void enterBoolop(LIAParser::BoolopContext * /*ctx*/) override { }
  virtual void exitBoolop(LIAParser::BoolopContext * /*ctx*/) override { }

  virtual void enterTermop(LIAParser::TermopContext * /*ctx*/) override { }
  virtual void exitTermop(LIAParser::TermopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

