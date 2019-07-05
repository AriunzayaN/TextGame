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
    c.destroy();
    passert(log(), string("log: Axe,null,Key,"));
    passert(k.name(), string("Key"));
    passert(k.getId(), 2);
    Item x("Key");
    passert(k == a , false);
    passert(k == x, false);
    freeAll();
    cout << "Tests passed." << endl;
    return 0;
}