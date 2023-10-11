//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_LEFTPARENTOKEN_H
#define CPLUSPLAYGROUND_LEFTPARENTOKEN_H
#include "Token.h"

class LeftParenToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_LEFTPARENTOKEN_H
