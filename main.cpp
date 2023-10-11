#include <iostream>
#include <utility>
#include <vector>
#include <cctype>
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
        return "IdentifierToken";
    }
};

class NumberToken : public Token {
public:
    int value;

    explicit NumberToken(const int value) : value(value) {
    }
    string toString() const override {
        return "NumberToken";
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

class Tokenizer{
public:
    const string input;
    int position;
    explicit Tokenizer(string input) : input(std::move(input)), position(0){}
    Token* tokenizeIdentifierOrReservedWord(){
        string name;
        if(isalpha(input[position])){ // If character at current position is letter
            name += input[position];
            position++;
            while(isalnum(input[position])){ // add letters to name
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
            }
        }
        return nullptr;
    }
    NumberToken* tokenizeNumber(){
        string digits;
        while(isdigit(input[position])){
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
        return nullptr;
    }
    void skipWhitespace(){
        while (isspace(input[position])){
            position++;
        }
    }
    vector<Token *> tokenize(){
        vector<Token*> retval = vector<Token*>();
        while(position < input.length()){
            retval.push_back(readToken());
            skipWhitespace();
        }
        return retval;
    }
};


int main() {
    vector<Token *> t = Tokenizer("45 45 int 123452435 12").tokenize();
    for (Token* token : t) {
        cout << token->toString() << endl;
    }
    return 0;
}