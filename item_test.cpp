#include "item.h"
#include <iostream>
#include <cassert>

using namespace std;

void passert(string target, string reference){
    if (target != reference){
        cout << target << endl;
        cout << reference << endl;
        assert(false);
    }
}

int main(){
    Manager m;
    Item a("Axe", &m);
    Item c("Crate", &m);
    passert(a.use(c), "Swung Axe Box broke open and you see gold inside.");
    cout << "Tests passed." << endl;
    return 0;
}