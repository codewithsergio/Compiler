//
// Created by ehern on 10/11/2023.
//

#ifndef CPLUSPLAYGROUND_TOKEN_H
#define CPLUSPLAYGROUND_TOKEN_H

#include <iostream>

class Token {
public:
    virtual ~Token() = default;
    virtual std::string toString() const {
        return "Token";
    }
};

#endif //CPLUSPLAYGROUND_TOKEN_H
