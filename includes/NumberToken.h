//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_NUMBERTOKEN_H
#define CPLUSPLAYGROUND_NUMBERTOKEN_H

#include "Token.h"
#include <iostream>


class NumberToken : public Token {
public:
    int value;

    explicit NumberToken(int value);
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_NUMBERTOKEN_H
