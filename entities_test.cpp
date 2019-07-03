#include <iostream>
#include "entities.h"

using namespace std;

int main(){
    Entity* a = new Axe();
    cout << a->name() << endl;

    Entity* c = new Crate();
    cout << c->name() << endl;
    cout << a->use(c) << endl;

    Entity* k = new Key();
    cout << k->name() << endl;
    cout << k->observe() <<endl;
    return 0; 
}