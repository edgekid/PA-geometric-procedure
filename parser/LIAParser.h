
// Generated from LIA.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  LIAParser : public antlr4::Parser {
public:
  enum {
    QUANT = 1, VARIABLE = 2, INT = 3, LPAREN = 4, RPAREN = 5, PLUS = 6, 
    MINUS = 7, MULT = 8, GT = 9, LT = 10, EQ = 11, OR = 12, AND = 13, COLON = 14, 
    NOT = 15, WS = 16
  };

  enum {
    RuleStart = 0, RuleTerm = 1, RuleTerm2 = 2, RuleFormula = 3, RuleFormula2 = 4, 
    RuleRelop = 5, RuleBoolop = 6, RuleTermop = 7
  };

  explicit LIAParser(antlr4::TokenStream *input);

  LIAParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LIAParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class TermContext;
  class Term2Context;
  class FormulaContext;
  class Formula2Context;
  class RelopContext;
  class BoolopContext;
  class TermopContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FormulaContext *formula();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TermTmpContext : public TermContext {
  public:
    TermTmpContext(TermContext *ctx);

    Term2Context *term2();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  TermOperationContext : public TermContext {
  public:
    TermOperationContext(TermContext *ctx);

    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    TermopContext *termop();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Term2Context : public antlr4::ParserRuleContext {
  public:
    Term2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Term2Context() = default;
    void copyFrom(Term2Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultByConst0Context : public Term2Context {
  public:
    MultByConst0Context(Term2Context *ctx);

    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MULT();
    Term2Context *term2();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SignedTermContext : public Term2Context {
  public:
    SignedTermContext(Term2Context *ctx);

    TermopContext *termop();
    Term2Context *term2();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultByConst1Context : public Term2Context {
  public:
    MultByConst1Context(Term2Context *ctx);

    Term2Context *term2();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarContext : public Term2Context {
  public:
    VarContext(Term2Context *ctx);

    antlr4::tree::TerminalNode *VARIABLE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ConstContext : public Term2Context {
  public:
    ConstContext(Term2Context *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Paren1Context : public Term2Context {
  public:
    Paren1Context(Term2Context *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    TermContext *term();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Term2Context* term2();
  Term2Context* term2(int precedence);
  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FormulaContext() = default;
    void copyFrom(FormulaContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FormulaTmpContext : public FormulaContext {
  public:
    FormulaTmpContext(FormulaContext *ctx);

    Formula2Context *formula2();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Paren2Context : public FormulaContext {
  public:
    Paren2Context(FormulaContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    FormulaContext *formula();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ComplementContext : public FormulaContext {
  public:
    ComplementContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    FormulaContext *formula();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  QuantContext : public FormulaContext {
  public:
    QuantContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *QUANT();
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *COLON();
    FormulaContext *formula();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  FormulaContext* formula();

  class  Formula2Context : public antlr4::ParserRuleContext {
  public:
    Formula2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Formula2Context() = default;
    void copyFrom(Formula2Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FormulaOperationContext : public Formula2Context {
  public:
    FormulaOperationContext(Formula2Context *ctx);

    std::vector<Formula2Context *> formula2();
    Formula2Context* formula2(size_t i);
    BoolopContext *boolop();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  TermRelationContext : public Formula2Context {
  public:
    TermRelationContext(Formula2Context *ctx);

    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    RelopContext *relop();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Paren3Context : public Formula2Context {
  public:
    Paren3Context(Formula2Context *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    Formula2Context *formula2();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Complement2Context : public Formula2Context {
  public:
    Complement2Context(Formula2Context *ctx);

    antlr4::tree::TerminalNode *NOT();
    Formula2Context *formula2();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Formula2Context* formula2();
  Formula2Context* formula2(int precedence);
  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();

  class  BoolopContext : public antlr4::ParserRuleContext {
  public:
    BoolopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BoolopContext* boolop();

  class  TermopContext : public antlr4::ParserRuleContext {
  public:
    TermopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermopContext* termop();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool term2Sempred(Term2Context *_localctx, size_t predicateIndex);
  bool formula2Sempred(Formula2Context *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

