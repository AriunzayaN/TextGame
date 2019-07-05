#include <iostream>
#include <string>
#include <cassert>
#include "entity.h"

using namespace std;

int main(){
    Entity *e = new Entity("dolly");
    assert(e->name() == "dolly");
    cout << "ENTITY TEST PASS" << endl;
    return 0;
}