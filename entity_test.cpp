#include <iostream>
#include <string>
#include <cassert>
#include "entity.h"

using namespace std;

int main(){
    Entity *e = new Entity("Dolly","Entity","Hall");
    assert(e->name() == "Dolly");
    assert(e->getPlaceName() == "Hall");
    cout << "ENTITY TEST PASS" << endl;
    return 0;
}