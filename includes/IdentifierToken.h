//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_IDENTIFIERTOKEN_H
#define CPLUSPLAYGROUND_IDENTIFIERTOKEN_H


#include "Token.h" // Include the base Token class header
#include <iostream>

class IdentifierToken : public Token {
public:
    std::string name;

    explicit IdentifierToken(std::string name);

    std::string toString() const override;
};


#endif //CPLUSPLAYGROUND_IDENTIFIERTOKEN_H
