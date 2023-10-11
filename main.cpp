#include <iostream>
#include <vector>
#include "includes/Token.h"
#include "includes/Tokenizer.h"
using namespace std;


int main() {
    string snippet = "(vardec x 546 bool () while    true false hello)";

    vector<Token *> t = Tokenizer(snippet).tokenize();
    for (Token* token : t) {
        cout << token->toString() << endl;
    }
    return 0;
}