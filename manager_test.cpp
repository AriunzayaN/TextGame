#include <cassert>
#include <iostream>
#include <string>
#include "manager.h"

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
    int id;
    Entity* axe = gen("Axe", id);
    int id1;
    Entity* key = gen("Key", id1);
    passert(axe->name(), string("Axe"));
    passert(id, 0);
    passert(key->name(), string("Key"));
    passert(id1,1);
    free(id);    
    free(id1);
    cout << "Tests passed." << endl;


}