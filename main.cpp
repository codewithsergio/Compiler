#include <iostream>
#include <utility>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

struct Token{
    virtual ~Token() = default;
    virtual string toString() const {
        return "Token";
    }
};

class IdentifierToken : public Token {
public:
    string name;

    explicit IdentifierToken(string name) : name(std::move(name)) {
    }
    string toString() const override {
        return "IdentifierToken(" + name + ")";
    }
};

class NumberToken : public Token {
public:
    int value;

    explicit NumberToken(const int value) : value(value) {
    }
    string toString() const override {
        return "NumberToken(" + to_string(value) + ")";
    }
};

class IntToken : public Token {
public:
    string toString() const override {
        return "IntToken";
    }
};

class BoolToken : public Token {
public:
    string toString() const override {
        return "BoolToken";
    }
};

class VarDecToken : public Token {
public:
    string toString() const override {
        return "VarDecToken";
    }
};

class TrueToken : public Token {
public:
    string toString() const override {
        return "TrueToken";
    }
};

class FalseToken : public Token {
public:
    string toString() const override {
        return "FalseToken";
    }
};

class WhileToken : public Token {
public:
    string toString() const override {
        return "WhileToken";
    }
};

class LeftParenToken : public Token {
public:
    string toString() const override {
        return "LeftParenToken";
    }
};

class RightParenToken : public Token {
public:
    string toString() const override {
        return "RightParenToken";
    }
};

class Tokenizer{
public:
    const string input;
    int position;
    explicit Tokenizer(string input) : input(std::move(input)), position(0){}
    Token* tokenizeSymbol(){
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
    Token* tokenizeIdentifierOrReservedWord(){
        string name;
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
    NumberToken* tokenizeNumber(){
        string digits;
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
    Token* readToken(){
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
    void skipWhitespace(){
        while (position < input.length() && isspace(input[position])){
            position++;
        }
    }
    vector<Token *> tokenize(){
        vector<Token*> retval = vector<Token*>();
        skipWhitespace();
        while(position < input.length()){
            retval.push_back(readToken());
            skipWhitespace();
        }
        return retval;
    }
};


int main() {
    string snippet = "vardec x 546";

    vector<Token *> t = Tokenizer(snippet).tokenize();
    for (Token* token : t) {
        cout << token->toString() << endl;
    }
    return 0;
}