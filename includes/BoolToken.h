//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_BOOLTOKEN_H
#define CPLUSPLAYGROUND_BOOLTOKEN_H

#include "Token.h"


class BoolToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_BOOLTOKEN_H
