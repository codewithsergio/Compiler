//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_TOKENIZER_H
#define CPLUSPLAYGROUND_TOKENIZER_H
#include "Token.h"
#include "NumberToken.h"
#include "Token.h"
#include "IdentifierToken.h"
#include "NumberToken.h"
#include "IntToken.h"
#include "BoolToken.h"
#include "RightParenToken.h"
#include "LeftParenToken.h"
#include "WhileToken.h"
#include "FalseToken.h"
#include "TrueToken.h"
#include "VarDecToken.h"
#include <vector>

class Tokenizer{
public:
    const std::string input;
    int position;
    explicit Tokenizer(std::string input);
    Token* tokenizeSymbol();
    Token* tokenizeIdentifierOrReservedWord();
    NumberToken* tokenizeNumber();
    Token* readToken();
    void skipWhitespace();
    std::vector<Token *> tokenize();
};


#endif //CPLUSPLAYGROUND_TOKENIZER_H
