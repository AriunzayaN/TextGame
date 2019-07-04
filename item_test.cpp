#include "item.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
void passert(T target, T reference){
    if (target != reference){
        cout << target << endl;
        cout << reference << endl;
        assert(false);
    }
}

int main(){
    Item a("Axe");
    Item c("Crate");
    passert(a.use(c), string("Swung Axe Box broke open and you see gold inside."));
    Item k("Key");
    passert(k.name(), string("Key"));
    passert(k.getId(), 2);
    Item x("Key");
    passert(k == a , false);
    passert(k == x, false);
    cout << "Tests passed." << endl;
    return 0;
}