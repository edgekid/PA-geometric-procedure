
// Generated from LIA.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LIAParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LIAParser.
 */
class  LIAListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(LIAParser::StartContext *ctx) = 0;
  virtual void exitStart(LIAParser::StartContext *ctx) = 0;

  virtual void enterTermTmp(LIAParser::TermTmpContext *ctx) = 0;
  virtual void exitTermTmp(LIAParser::TermTmpContext *ctx) = 0;

  virtual void enterTermOperation(LIAParser::TermOperationContext *ctx) = 0;
  virtual void exitTermOperation(LIAParser::TermOperationContext *ctx) = 0;

  virtual void enterMultByConst0(LIAParser::MultByConst0Context *ctx) = 0;
  virtual void exitMultByConst0(LIAParser::MultByConst0Context *ctx) = 0;

  virtual void enterSignedTerm(LIAParser::SignedTermContext *ctx) = 0;
  virtual void exitSignedTerm(LIAParser::SignedTermContext *ctx) = 0;

  virtual void enterMultByConst1(LIAParser::MultByConst1Context *ctx) = 0;
  virtual void exitMultByConst1(LIAParser::MultByConst1Context *ctx) = 0;

  virtual void enterVar(LIAParser::VarContext *ctx) = 0;
  virtual void exitVar(LIAParser::VarContext *ctx) = 0;

  virtual void enterConst(LIAParser::ConstContext *ctx) = 0;
  virtual void exitConst(LIAParser::ConstContext *ctx) = 0;

  virtual void enterParen1(LIAParser::Paren1Context *ctx) = 0;
  virtual void exitParen1(LIAParser::Paren1Context *ctx) = 0;

  virtual void enterQuant(LIAParser::QuantContext *ctx) = 0;
  virtual void exitQuant(LIAParser::QuantContext *ctx) = 0;

  virtual void enterComplement(LIAParser::ComplementContext *ctx) = 0;
  virtual void exitComplement(LIAParser::ComplementContext *ctx) = 0;

  virtual void enterParen2(LIAParser::Paren2Context *ctx) = 0;
  virtual void exitParen2(LIAParser::Paren2Context *ctx) = 0;

  virtual void enterFormulaTmp(LIAParser::FormulaTmpContext *ctx) = 0;
  virtual void exitFormulaTmp(LIAParser::FormulaTmpContext *ctx) = 0;

  virtual void enterFormulaOperation(LIAParser::FormulaOperationContext *ctx) = 0;
  virtual void exitFormulaOperation(LIAParser::FormulaOperationContext *ctx) = 0;

  virtual void enterTermRelation(LIAParser::TermRelationContext *ctx) = 0;
  virtual void exitTermRelation(LIAParser::TermRelationContext *ctx) = 0;

  virtual void enterParen3(LIAParser::Paren3Context *ctx) = 0;
  virtual void exitParen3(LIAParser::Paren3Context *ctx) = 0;

  virtual void enterComplement2(LIAParser::Complement2Context *ctx) = 0;
  virtual void exitComplement2(LIAParser::Complement2Context *ctx) = 0;

  virtual void enterRelop(LIAParser::RelopContext *ctx) = 0;
  virtual void exitRelop(LIAParser::RelopContext *ctx) = 0;

  virtual void enterBoolop(LIAParser::BoolopContext *ctx) = 0;
  virtual void exitBoolop(LIAParser::BoolopContext *ctx) = 0;

  virtual void enterTermop(LIAParser::TermopContext *ctx) = 0;
  virtual void exitTermop(LIAParser::TermopContext *ctx) = 0;


};

