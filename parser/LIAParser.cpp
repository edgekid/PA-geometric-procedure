
// Generated from LIA.g4 by ANTLR 4.13.1


#include "LIAListener.h"

#include "LIAParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LIAParserStaticData final {
  LIAParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LIAParserStaticData(const LIAParserStaticData&) = delete;
  LIAParserStaticData(LIAParserStaticData&&) = delete;
  LIAParserStaticData& operator=(const LIAParserStaticData&) = delete;
  LIAParserStaticData& operator=(LIAParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag liaParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LIAParserStaticData *liaParserStaticData = nullptr;

void liaParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (liaParserStaticData != nullptr) {
    return;
  }
#else
  assert(liaParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LIAParserStaticData>(
    std::vector<std::string>{
      "start", "term", "term2", "formula", "formula2", "relop", "boolop", 
      "termop"
    },
    std::vector<std::string>{
      "", "", "", "", "'('", "')'", "'+'", "'-'", "'*'", "'>'", "'<'", "'='", 
      "'||'", "'&&'", "':'", "'!'"
    },
    std::vector<std::string>{
      "", "QUANT", "VARIABLE", "INT", "LPAREN", "RPAREN", "PLUS", "MINUS", 
      "MULT", "GT", "LT", "EQ", "OR", "AND", "COLON", "NOT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,16,96,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,27,8,1,10,1,12,1,30,9,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,45,8,2,1,2,
  	1,2,1,2,5,2,50,8,2,10,2,12,2,53,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,66,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,
  	79,8,4,1,4,1,4,1,4,1,4,5,4,85,8,4,10,4,12,4,88,9,4,1,5,1,5,1,6,1,6,1,
  	7,1,7,1,7,0,3,2,4,8,8,0,2,4,6,8,10,12,14,0,3,1,0,9,11,1,0,12,13,1,0,6,
  	7,99,0,16,1,0,0,0,2,19,1,0,0,0,4,44,1,0,0,0,6,65,1,0,0,0,8,78,1,0,0,0,
  	10,89,1,0,0,0,12,91,1,0,0,0,14,93,1,0,0,0,16,17,3,6,3,0,17,18,5,0,0,1,
  	18,1,1,0,0,0,19,20,6,1,-1,0,20,21,3,4,2,0,21,28,1,0,0,0,22,23,10,2,0,
  	0,23,24,3,14,7,0,24,25,3,2,1,3,25,27,1,0,0,0,26,22,1,0,0,0,27,30,1,0,
  	0,0,28,26,1,0,0,0,28,29,1,0,0,0,29,3,1,0,0,0,30,28,1,0,0,0,31,32,6,2,
  	-1,0,32,33,5,3,0,0,33,34,5,8,0,0,34,45,3,4,2,5,35,36,3,14,7,0,36,37,3,
  	4,2,4,37,45,1,0,0,0,38,39,5,4,0,0,39,40,3,2,1,0,40,41,5,5,0,0,41,45,1,
  	0,0,0,42,45,5,2,0,0,43,45,5,3,0,0,44,31,1,0,0,0,44,35,1,0,0,0,44,38,1,
  	0,0,0,44,42,1,0,0,0,44,43,1,0,0,0,45,51,1,0,0,0,46,47,10,6,0,0,47,48,
  	5,8,0,0,48,50,5,3,0,0,49,46,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,51,52,
  	1,0,0,0,52,5,1,0,0,0,53,51,1,0,0,0,54,55,5,1,0,0,55,56,5,2,0,0,56,57,
  	5,14,0,0,57,66,3,6,3,0,58,59,5,15,0,0,59,66,3,6,3,0,60,61,5,4,0,0,61,
  	62,3,6,3,0,62,63,5,5,0,0,63,66,1,0,0,0,64,66,3,8,4,0,65,54,1,0,0,0,65,
  	58,1,0,0,0,65,60,1,0,0,0,65,64,1,0,0,0,66,7,1,0,0,0,67,68,6,4,-1,0,68,
  	69,3,2,1,0,69,70,3,10,5,0,70,71,3,2,1,0,71,79,1,0,0,0,72,73,5,4,0,0,73,
  	74,3,8,4,0,74,75,5,5,0,0,75,79,1,0,0,0,76,77,5,15,0,0,77,79,3,8,4,1,78,
  	67,1,0,0,0,78,72,1,0,0,0,78,76,1,0,0,0,79,86,1,0,0,0,80,81,10,2,0,0,81,
  	82,3,12,6,0,82,83,3,8,4,3,83,85,1,0,0,0,84,80,1,0,0,0,85,88,1,0,0,0,86,
  	84,1,0,0,0,86,87,1,0,0,0,87,9,1,0,0,0,88,86,1,0,0,0,89,90,7,0,0,0,90,
  	11,1,0,0,0,91,92,7,1,0,0,92,13,1,0,0,0,93,94,7,2,0,0,94,15,1,0,0,0,6,
  	28,44,51,65,78,86
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  liaParserStaticData = staticData.release();
}

}

LIAParser::LIAParser(TokenStream *input) : LIAParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LIAParser::LIAParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LIAParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *liaParserStaticData->atn, liaParserStaticData->decisionToDFA, liaParserStaticData->sharedContextCache, options);
}

LIAParser::~LIAParser() {
  delete _interpreter;
}

const atn::ATN& LIAParser::getATN() const {
  return *liaParserStaticData->atn;
}

std::string LIAParser::getGrammarFileName() const {
  return "LIA.g4";
}

const std::vector<std::string>& LIAParser::getRuleNames() const {
  return liaParserStaticData->ruleNames;
}

const dfa::Vocabulary& LIAParser::getVocabulary() const {
  return liaParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LIAParser::getSerializedATN() const {
  return liaParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

LIAParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LIAParser::FormulaContext* LIAParser::StartContext::formula() {
  return getRuleContext<LIAParser::FormulaContext>(0);
}

tree::TerminalNode* LIAParser::StartContext::EOF() {
  return getToken(LIAParser::EOF, 0);
}


size_t LIAParser::StartContext::getRuleIndex() const {
  return LIAParser::RuleStart;
}

void LIAParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void LIAParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

LIAParser::StartContext* LIAParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, LIAParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    formula();
    setState(17);
    match(LIAParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

LIAParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LIAParser::TermContext::getRuleIndex() const {
  return LIAParser::RuleTerm;
}

void LIAParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermTmpContext ------------------------------------------------------------------

LIAParser::Term2Context* LIAParser::TermTmpContext::term2() {
  return getRuleContext<LIAParser::Term2Context>(0);
}

LIAParser::TermTmpContext::TermTmpContext(TermContext *ctx) { copyFrom(ctx); }

void LIAParser::TermTmpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermTmp(this);
}
void LIAParser::TermTmpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermTmp(this);
}
//----------------- TermOperationContext ------------------------------------------------------------------

std::vector<LIAParser::TermContext *> LIAParser::TermOperationContext::term() {
  return getRuleContexts<LIAParser::TermContext>();
}

LIAParser::TermContext* LIAParser::TermOperationContext::term(size_t i) {
  return getRuleContext<LIAParser::TermContext>(i);
}

LIAParser::TermopContext* LIAParser::TermOperationContext::termop() {
  return getRuleContext<LIAParser::TermopContext>(0);
}

LIAParser::TermOperationContext::TermOperationContext(TermContext *ctx) { copyFrom(ctx); }

void LIAParser::TermOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermOperation(this);
}
void LIAParser::TermOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermOperation(this);
}

LIAParser::TermContext* LIAParser::term() {
   return term(0);
}

LIAParser::TermContext* LIAParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LIAParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  LIAParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, LIAParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<TermTmpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(20);
    term2(0);
    _ctx->stop = _input->LT(-1);
    setState(28);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<TermOperationContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(22);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(23);
        termop();
        setState(24);
        term(3); 
      }
      setState(30);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Term2Context ------------------------------------------------------------------

LIAParser::Term2Context::Term2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LIAParser::Term2Context::getRuleIndex() const {
  return LIAParser::RuleTerm2;
}

void LIAParser::Term2Context::copyFrom(Term2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultByConst0Context ------------------------------------------------------------------

tree::TerminalNode* LIAParser::MultByConst0Context::INT() {
  return getToken(LIAParser::INT, 0);
}

tree::TerminalNode* LIAParser::MultByConst0Context::MULT() {
  return getToken(LIAParser::MULT, 0);
}

LIAParser::Term2Context* LIAParser::MultByConst0Context::term2() {
  return getRuleContext<LIAParser::Term2Context>(0);
}

LIAParser::MultByConst0Context::MultByConst0Context(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::MultByConst0Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultByConst0(this);
}
void LIAParser::MultByConst0Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultByConst0(this);
}
//----------------- SignedTermContext ------------------------------------------------------------------

LIAParser::TermopContext* LIAParser::SignedTermContext::termop() {
  return getRuleContext<LIAParser::TermopContext>(0);
}

LIAParser::Term2Context* LIAParser::SignedTermContext::term2() {
  return getRuleContext<LIAParser::Term2Context>(0);
}

LIAParser::SignedTermContext::SignedTermContext(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::SignedTermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignedTerm(this);
}
void LIAParser::SignedTermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignedTerm(this);
}
//----------------- MultByConst1Context ------------------------------------------------------------------

LIAParser::Term2Context* LIAParser::MultByConst1Context::term2() {
  return getRuleContext<LIAParser::Term2Context>(0);
}

tree::TerminalNode* LIAParser::MultByConst1Context::MULT() {
  return getToken(LIAParser::MULT, 0);
}

tree::TerminalNode* LIAParser::MultByConst1Context::INT() {
  return getToken(LIAParser::INT, 0);
}

LIAParser::MultByConst1Context::MultByConst1Context(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::MultByConst1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultByConst1(this);
}
void LIAParser::MultByConst1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultByConst1(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* LIAParser::VarContext::VARIABLE() {
  return getToken(LIAParser::VARIABLE, 0);
}

LIAParser::VarContext::VarContext(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}
void LIAParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}
//----------------- ConstContext ------------------------------------------------------------------

tree::TerminalNode* LIAParser::ConstContext::INT() {
  return getToken(LIAParser::INT, 0);
}

LIAParser::ConstContext::ConstContext(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::ConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst(this);
}
void LIAParser::ConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst(this);
}
//----------------- Paren1Context ------------------------------------------------------------------

tree::TerminalNode* LIAParser::Paren1Context::LPAREN() {
  return getToken(LIAParser::LPAREN, 0);
}

LIAParser::TermContext* LIAParser::Paren1Context::term() {
  return getRuleContext<LIAParser::TermContext>(0);
}

tree::TerminalNode* LIAParser::Paren1Context::RPAREN() {
  return getToken(LIAParser::RPAREN, 0);
}

LIAParser::Paren1Context::Paren1Context(Term2Context *ctx) { copyFrom(ctx); }

void LIAParser::Paren1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen1(this);
}
void LIAParser::Paren1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen1(this);
}

LIAParser::Term2Context* LIAParser::term2() {
   return term2(0);
}

LIAParser::Term2Context* LIAParser::term2(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LIAParser::Term2Context *_localctx = _tracker.createInstance<Term2Context>(_ctx, parentState);
  LIAParser::Term2Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, LIAParser::RuleTerm2, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MultByConst0Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(32);
      match(LIAParser::INT);
      setState(33);
      match(LIAParser::MULT);
      setState(34);
      term2(5);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SignedTermContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(35);
      termop();
      setState(36);
      term2(4);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Paren1Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(38);
      match(LIAParser::LPAREN);
      setState(39);
      term(0);
      setState(40);
      match(LIAParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(LIAParser::VARIABLE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConstContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(43);
      match(LIAParser::INT);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(51);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultByConst1Context>(_tracker.createInstance<Term2Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm2);
        setState(46);

        if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
        setState(47);
        match(LIAParser::MULT);
        setState(48);
        match(LIAParser::INT); 
      }
      setState(53);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FormulaContext ------------------------------------------------------------------

LIAParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LIAParser::FormulaContext::getRuleIndex() const {
  return LIAParser::RuleFormula;
}

void LIAParser::FormulaContext::copyFrom(FormulaContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FormulaTmpContext ------------------------------------------------------------------

LIAParser::Formula2Context* LIAParser::FormulaTmpContext::formula2() {
  return getRuleContext<LIAParser::Formula2Context>(0);
}

LIAParser::FormulaTmpContext::FormulaTmpContext(FormulaContext *ctx) { copyFrom(ctx); }

void LIAParser::FormulaTmpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormulaTmp(this);
}
void LIAParser::FormulaTmpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormulaTmp(this);
}
//----------------- Paren2Context ------------------------------------------------------------------

tree::TerminalNode* LIAParser::Paren2Context::LPAREN() {
  return getToken(LIAParser::LPAREN, 0);
}

LIAParser::FormulaContext* LIAParser::Paren2Context::formula() {
  return getRuleContext<LIAParser::FormulaContext>(0);
}

tree::TerminalNode* LIAParser::Paren2Context::RPAREN() {
  return getToken(LIAParser::RPAREN, 0);
}

LIAParser::Paren2Context::Paren2Context(FormulaContext *ctx) { copyFrom(ctx); }

void LIAParser::Paren2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen2(this);
}
void LIAParser::Paren2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen2(this);
}
//----------------- ComplementContext ------------------------------------------------------------------

tree::TerminalNode* LIAParser::ComplementContext::NOT() {
  return getToken(LIAParser::NOT, 0);
}

LIAParser::FormulaContext* LIAParser::ComplementContext::formula() {
  return getRuleContext<LIAParser::FormulaContext>(0);
}

LIAParser::ComplementContext::ComplementContext(FormulaContext *ctx) { copyFrom(ctx); }

void LIAParser::ComplementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplement(this);
}
void LIAParser::ComplementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplement(this);
}
//----------------- QuantContext ------------------------------------------------------------------

tree::TerminalNode* LIAParser::QuantContext::QUANT() {
  return getToken(LIAParser::QUANT, 0);
}

tree::TerminalNode* LIAParser::QuantContext::VARIABLE() {
  return getToken(LIAParser::VARIABLE, 0);
}

tree::TerminalNode* LIAParser::QuantContext::COLON() {
  return getToken(LIAParser::COLON, 0);
}

LIAParser::FormulaContext* LIAParser::QuantContext::formula() {
  return getRuleContext<LIAParser::FormulaContext>(0);
}

LIAParser::QuantContext::QuantContext(FormulaContext *ctx) { copyFrom(ctx); }

void LIAParser::QuantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuant(this);
}
void LIAParser::QuantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuant(this);
}
LIAParser::FormulaContext* LIAParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 6, LIAParser::RuleFormula);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<LIAParser::QuantContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(54);
      match(LIAParser::QUANT);
      setState(55);
      match(LIAParser::VARIABLE);
      setState(56);
      match(LIAParser::COLON);
      setState(57);
      formula();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<LIAParser::ComplementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(58);
      match(LIAParser::NOT);
      setState(59);
      formula();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<LIAParser::Paren2Context>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
      match(LIAParser::LPAREN);
      setState(61);
      formula();
      setState(62);
      match(LIAParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<LIAParser::FormulaTmpContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(64);
      formula2(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formula2Context ------------------------------------------------------------------

LIAParser::Formula2Context::Formula2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LIAParser::Formula2Context::getRuleIndex() const {
  return LIAParser::RuleFormula2;
}

void LIAParser::Formula2Context::copyFrom(Formula2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FormulaOperationContext ------------------------------------------------------------------

std::vector<LIAParser::Formula2Context *> LIAParser::FormulaOperationContext::formula2() {
  return getRuleContexts<LIAParser::Formula2Context>();
}

LIAParser::Formula2Context* LIAParser::FormulaOperationContext::formula2(size_t i) {
  return getRuleContext<LIAParser::Formula2Context>(i);
}

LIAParser::BoolopContext* LIAParser::FormulaOperationContext::boolop() {
  return getRuleContext<LIAParser::BoolopContext>(0);
}

LIAParser::FormulaOperationContext::FormulaOperationContext(Formula2Context *ctx) { copyFrom(ctx); }

void LIAParser::FormulaOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormulaOperation(this);
}
void LIAParser::FormulaOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormulaOperation(this);
}
//----------------- TermRelationContext ------------------------------------------------------------------

std::vector<LIAParser::TermContext *> LIAParser::TermRelationContext::term() {
  return getRuleContexts<LIAParser::TermContext>();
}

LIAParser::TermContext* LIAParser::TermRelationContext::term(size_t i) {
  return getRuleContext<LIAParser::TermContext>(i);
}

LIAParser::RelopContext* LIAParser::TermRelationContext::relop() {
  return getRuleContext<LIAParser::RelopContext>(0);
}

LIAParser::TermRelationContext::TermRelationContext(Formula2Context *ctx) { copyFrom(ctx); }

void LIAParser::TermRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermRelation(this);
}
void LIAParser::TermRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermRelation(this);
}
//----------------- Paren3Context ------------------------------------------------------------------

tree::TerminalNode* LIAParser::Paren3Context::LPAREN() {
  return getToken(LIAParser::LPAREN, 0);
}

LIAParser::Formula2Context* LIAParser::Paren3Context::formula2() {
  return getRuleContext<LIAParser::Formula2Context>(0);
}

tree::TerminalNode* LIAParser::Paren3Context::RPAREN() {
  return getToken(LIAParser::RPAREN, 0);
}

LIAParser::Paren3Context::Paren3Context(Formula2Context *ctx) { copyFrom(ctx); }

void LIAParser::Paren3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen3(this);
}
void LIAParser::Paren3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen3(this);
}
//----------------- Complement2Context ------------------------------------------------------------------

tree::TerminalNode* LIAParser::Complement2Context::NOT() {
  return getToken(LIAParser::NOT, 0);
}

LIAParser::Formula2Context* LIAParser::Complement2Context::formula2() {
  return getRuleContext<LIAParser::Formula2Context>(0);
}

LIAParser::Complement2Context::Complement2Context(Formula2Context *ctx) { copyFrom(ctx); }

void LIAParser::Complement2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplement2(this);
}
void LIAParser::Complement2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplement2(this);
}

LIAParser::Formula2Context* LIAParser::formula2() {
   return formula2(0);
}

LIAParser::Formula2Context* LIAParser::formula2(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LIAParser::Formula2Context *_localctx = _tracker.createInstance<Formula2Context>(_ctx, parentState);
  LIAParser::Formula2Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, LIAParser::RuleFormula2, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(78);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TermRelationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(68);
      term(0);
      setState(69);
      relop();
      setState(70);
      term(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Paren3Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(72);
      match(LIAParser::LPAREN);
      setState(73);
      formula2(0);
      setState(74);
      match(LIAParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Complement2Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      match(LIAParser::NOT);
      setState(77);
      formula2(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<FormulaOperationContext>(_tracker.createInstance<Formula2Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleFormula2);
        setState(80);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(81);
        boolop();
        setState(82);
        formula2(3); 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

LIAParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIAParser::RelopContext::EQ() {
  return getToken(LIAParser::EQ, 0);
}

tree::TerminalNode* LIAParser::RelopContext::GT() {
  return getToken(LIAParser::GT, 0);
}

tree::TerminalNode* LIAParser::RelopContext::LT() {
  return getToken(LIAParser::LT, 0);
}


size_t LIAParser::RelopContext::getRuleIndex() const {
  return LIAParser::RuleRelop;
}

void LIAParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void LIAParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

LIAParser::RelopContext* LIAParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 10, LIAParser::RuleRelop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3584) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolopContext ------------------------------------------------------------------

LIAParser::BoolopContext::BoolopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIAParser::BoolopContext::OR() {
  return getToken(LIAParser::OR, 0);
}

tree::TerminalNode* LIAParser::BoolopContext::AND() {
  return getToken(LIAParser::AND, 0);
}


size_t LIAParser::BoolopContext::getRuleIndex() const {
  return LIAParser::RuleBoolop;
}

void LIAParser::BoolopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolop(this);
}

void LIAParser::BoolopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolop(this);
}

LIAParser::BoolopContext* LIAParser::boolop() {
  BoolopContext *_localctx = _tracker.createInstance<BoolopContext>(_ctx, getState());
  enterRule(_localctx, 12, LIAParser::RuleBoolop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    _la = _input->LA(1);
    if (!(_la == LIAParser::OR

    || _la == LIAParser::AND)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermopContext ------------------------------------------------------------------

LIAParser::TermopContext::TermopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LIAParser::TermopContext::PLUS() {
  return getToken(LIAParser::PLUS, 0);
}

tree::TerminalNode* LIAParser::TermopContext::MINUS() {
  return getToken(LIAParser::MINUS, 0);
}


size_t LIAParser::TermopContext::getRuleIndex() const {
  return LIAParser::RuleTermop;
}

void LIAParser::TermopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermop(this);
}

void LIAParser::TermopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LIAListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermop(this);
}

LIAParser::TermopContext* LIAParser::termop() {
  TermopContext *_localctx = _tracker.createInstance<TermopContext>(_ctx, getState());
  enterRule(_localctx, 14, LIAParser::RuleTermop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    _la = _input->LA(1);
    if (!(_la == LIAParser::PLUS

    || _la == LIAParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool LIAParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 2: return term2Sempred(antlrcpp::downCast<Term2Context *>(context), predicateIndex);
    case 4: return formula2Sempred(antlrcpp::downCast<Formula2Context *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LIAParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool LIAParser::term2Sempred(Term2Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool LIAParser::formula2Sempred(Formula2Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void LIAParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  liaParserInitialize();
#else
  ::antlr4::internal::call_once(liaParserOnceFlag, liaParserInitialize);
#endif
}
