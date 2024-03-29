
// Generated from LIA.g4 by ANTLR 4.13.1


#include "LIALexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LIALexerStaticData final {
  LIALexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LIALexerStaticData(const LIALexerStaticData&) = delete;
  LIALexerStaticData(LIALexerStaticData&&) = delete;
  LIALexerStaticData& operator=(const LIALexerStaticData&) = delete;
  LIALexerStaticData& operator=(LIALexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lialexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LIALexerStaticData *lialexerLexerStaticData = nullptr;

void lialexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lialexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(lialexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LIALexerStaticData>(
    std::vector<std::string>{
      "QUANT", "VARIABLE", "VALID_ID_START", "VALID_ID_CHAR", "INT", "LPAREN", 
      "RPAREN", "PLUS", "MINUS", "MULT", "GT", "LT", "EQ", "OR", "AND", 
      "COLON", "NOT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,16,102,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,0,3,0,50,8,0,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,1,2,1,2,
  	1,3,1,3,3,3,63,8,3,1,4,4,4,66,8,4,11,4,12,4,67,1,5,1,5,1,6,1,6,1,7,1,
  	7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,14,1,
  	14,1,14,1,15,1,15,1,16,1,16,1,17,4,17,97,8,17,11,17,12,17,98,1,17,1,17,
  	0,0,18,1,1,3,2,5,0,7,0,9,3,11,4,13,5,15,6,17,7,19,8,21,9,23,10,25,11,
  	27,12,29,13,31,14,33,15,35,16,1,0,2,3,0,65,90,95,95,97,122,3,0,9,10,13,
  	13,32,32,104,0,1,1,0,0,0,0,3,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,
  	0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,
  	35,1,0,0,0,1,49,1,0,0,0,3,51,1,0,0,0,5,58,1,0,0,0,7,62,1,0,0,0,9,65,1,
  	0,0,0,11,69,1,0,0,0,13,71,1,0,0,0,15,73,1,0,0,0,17,75,1,0,0,0,19,77,1,
  	0,0,0,21,79,1,0,0,0,23,81,1,0,0,0,25,83,1,0,0,0,27,85,1,0,0,0,29,88,1,
  	0,0,0,31,91,1,0,0,0,33,93,1,0,0,0,35,96,1,0,0,0,37,38,5,102,0,0,38,39,
  	5,111,0,0,39,40,5,114,0,0,40,41,5,97,0,0,41,42,5,108,0,0,42,50,5,108,
  	0,0,43,44,5,101,0,0,44,45,5,120,0,0,45,46,5,105,0,0,46,47,5,115,0,0,47,
  	48,5,116,0,0,48,50,5,115,0,0,49,37,1,0,0,0,49,43,1,0,0,0,50,2,1,0,0,0,
  	51,55,3,5,2,0,52,54,3,7,3,0,53,52,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,
  	55,56,1,0,0,0,56,4,1,0,0,0,57,55,1,0,0,0,58,59,7,0,0,0,59,6,1,0,0,0,60,
  	63,3,5,2,0,61,63,2,48,57,0,62,60,1,0,0,0,62,61,1,0,0,0,63,8,1,0,0,0,64,
  	66,2,48,57,0,65,64,1,0,0,0,66,67,1,0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,
  	68,10,1,0,0,0,69,70,5,40,0,0,70,12,1,0,0,0,71,72,5,41,0,0,72,14,1,0,0,
  	0,73,74,5,43,0,0,74,16,1,0,0,0,75,76,5,45,0,0,76,18,1,0,0,0,77,78,5,42,
  	0,0,78,20,1,0,0,0,79,80,5,62,0,0,80,22,1,0,0,0,81,82,5,60,0,0,82,24,1,
  	0,0,0,83,84,5,61,0,0,84,26,1,0,0,0,85,86,5,124,0,0,86,87,5,124,0,0,87,
  	28,1,0,0,0,88,89,5,38,0,0,89,90,5,38,0,0,90,30,1,0,0,0,91,92,5,58,0,0,
  	92,32,1,0,0,0,93,94,5,33,0,0,94,34,1,0,0,0,95,97,7,1,0,0,96,95,1,0,0,
  	0,97,98,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,100,1,0,0,0,100,101,6,
  	17,0,0,101,36,1,0,0,0,6,0,49,55,62,67,98,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lialexerLexerStaticData = staticData.release();
}

}

LIALexer::LIALexer(CharStream *input) : Lexer(input) {
  LIALexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *lialexerLexerStaticData->atn, lialexerLexerStaticData->decisionToDFA, lialexerLexerStaticData->sharedContextCache);
}

LIALexer::~LIALexer() {
  delete _interpreter;
}

std::string LIALexer::getGrammarFileName() const {
  return "LIA.g4";
}

const std::vector<std::string>& LIALexer::getRuleNames() const {
  return lialexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LIALexer::getChannelNames() const {
  return lialexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LIALexer::getModeNames() const {
  return lialexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LIALexer::getVocabulary() const {
  return lialexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LIALexer::getSerializedATN() const {
  return lialexerLexerStaticData->serializedATN;
}

const atn::ATN& LIALexer::getATN() const {
  return *lialexerLexerStaticData->atn;
}




void LIALexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lialexerLexerInitialize();
#else
  ::antlr4::internal::call_once(lialexerLexerOnceFlag, lialexerLexerInitialize);
#endif
}
