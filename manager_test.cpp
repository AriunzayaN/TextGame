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
    int id2;
    Entity* key1 = gen("Key", id2);
    int id3;
    Entity* key2 = gen("Key", id3);
    int id4;
    Entity* key3 = gen("Key", id4);
    freeAll();
    passert(log(), string("log: null,null,null,null,null,"));
    cout << "Tests passed." << endl;


}