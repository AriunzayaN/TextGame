#include <iostream>
#include <string>
#include <cassert>
#include "entity.h"

using namespace std;

int main(){
    Entity e;
    assert(e.name() == "oopsie, shouldn't happen");
    cout << "ENTITY TEST PASS" << endl;
    return 0;
}