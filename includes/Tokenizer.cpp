//
// Created by ehern on 10/11/2023.
//

#include "Tokenizer.h"
Tokenizer::Tokenizer(std::string input) : input(std::move(input)), position(0){}
Token* Tokenizer::tokenizeSymbol(){
    if(input[position] == '('){
        position++;
        return new LeftParenToken();
    } else if (input[position] == ')'){
        position++;
        return new RightParenToken();
    } else {
        return nullptr;
    }
}
Token* Tokenizer::tokenizeIdentifierOrReservedWord(){
    std::string name;
    if(isalpha(input[position])){ // If character at current position is letter
        name += input[position];
        position++;
        while(position < input.length() && isalnum(input[position])){ // add letters to name
            name += input[position];
            position++;
        }
        // better way to check is to
        // make a hashtable of all the
        // tokens, and use that value as
        // the return type
        if(name == "int"){
            return new IntToken();
        } else if(name == "bool"){
            return new BoolToken();
        } else if(name == "true"){
            return new TrueToken();
        } else if(name == "false"){
            return new FalseToken();
        } else if(name == "vardec"){
            return new VarDecToken();
        } else if(name == "while"){
            return new WhileToken();
        } else {
            return new IdentifierToken(name);
        }
    }
    return nullptr;
}
NumberToken* Tokenizer::tokenizeNumber(){
    std::string digits;
    while(position < input.length() && isdigit(input[position])){
        digits += input[position];
        position++;
    }
    if(digits.length() > 0){
        return new NumberToken(stoi(digits));
    } else {
        return nullptr;
    }
}
Token* Tokenizer::readToken(){
    Token* retval = tokenizeNumber();
    if(retval != nullptr){
        return retval;
    }
    retval = tokenizeIdentifierOrReservedWord();
    if(retval != nullptr){
        return retval;
    }
    retval = tokenizeSymbol();
    if(retval != nullptr){
        return retval;
    }
    return nullptr;
}
void Tokenizer::skipWhitespace(){
    while (position < input.length() && isspace(input[position])){
        position++;
    }
}
std::vector<Token *> Tokenizer::tokenize(){
    std::vector<Token*> retval = std::vector<Token*>();
    skipWhitespace();
    while(position < input.length()){
        retval.push_back(readToken());
        skipWhitespace();
    }
    return retval;
}