//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_FALSETOKEN_H
#define CPLUSPLAYGROUND_FALSETOKEN_H
#include "Token.h"

class FalseToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_FALSETOKEN_H
