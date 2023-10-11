//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_RIGHTPARENTOKEN_H
#define CPLUSPLAYGROUND_RIGHTPARENTOKEN_H
#include "Token.h"

class RightParenToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_RIGHTPARENTOKEN_H
