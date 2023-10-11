//
// Created by ehern on 10/11/2023.
//

#include "IdentifierToken.h"

IdentifierToken::IdentifierToken(std::string name) : name(std::move(name)) {
}

std::string IdentifierToken::toString() const {
    return "IdentifierToken(" + name + ")";
}
