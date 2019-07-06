#include <iostream>
#include <cassert>
#include "parser.h"

using namespace std;

template <typename T>
void passert(T target, T reference){
    if (target != reference){
        cout << target << endl;
        cout << reference << endl;
        assert(false);
    }
}

void valid_input_test();
int main(){
    auto v = split("woo waa wee", true);
    passert(v[0], string("woo"));
    passert(v[1], string("waa"));
    passert(v[2], string("wee"));
    valid_input_test();
    cout << "Parser test pass" << endl;
    return 0;
}

void valid_input_test(){
    passert(valid_input(split("USE",true)), false );
    passert(valid_input(split("USE stuff ON ?",true)), false );
    passert(valid_input(split("USE stuff ON lala-land",true)), true );
    passert(valid_input(split("HIT stuff ON lala-land",true)), false );
    passert(valid_input(split("HIT stuff with lala-land",true)), true );
    passert(valid_input(split("GET >>",true)), false);
    passert(valid_input(split("Get life",true)), true );
    passert(valid_input(split("?? life",true)), false );    
};