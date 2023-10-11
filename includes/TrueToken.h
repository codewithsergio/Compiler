//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_TRUETOKEN_H
#define CPLUSPLAYGROUND_TRUETOKEN_H
#include "Token.h"

class TrueToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_TRUETOKEN_H
