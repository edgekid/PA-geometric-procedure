
// Generated from LIA.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  LIALexer : public antlr4::Lexer {
public:
  enum {
    QUANT = 1, VARIABLE = 2, INT = 3, LPAREN = 4, RPAREN = 5, PLUS = 6, 
    MINUS = 7, MULT = 8, GT = 9, LT = 10, EQ = 11, OR = 12, AND = 13, COLON = 14, 
    NOT = 15, WS = 16
  };

  explicit LIALexer(antlr4::CharStream *input);

  ~LIALexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

