//
// Created by ehern on 10/11/2023.
//

#include "NumberToken.h"

NumberToken::NumberToken(const int value) : value(value) {
}
std::string NumberToken::toString() const {
    return "NumberToken(" + std::to_string(value) + ")";
}