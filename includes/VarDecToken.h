//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_VARDECTOKEN_H
#define CPLUSPLAYGROUND_VARDECTOKEN_H
#include "Token.h"

class VarDecToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_VARDECTOKEN_H
