//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_WHILETOKEN_H
#define CPLUSPLAYGROUND_WHILETOKEN_H
#include "Token.h"

class WhileToken : public Token {
public:
    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_WHILETOKEN_H
