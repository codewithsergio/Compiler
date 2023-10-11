//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_INTTOKEN_H
#define CPLUSPLAYGROUND_INTTOKEN_H

#include "Token.h"

class IntToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_INTTOKEN_H
