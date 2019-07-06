#include <iostream>
#include <cassert>
#include "manager.h"

using namespace std;

void passert(string target, string reference){
    if (target != reference){
        cout << target << endl;
        cout << reference << endl;
        assert(false);
    }
}

int main(){
    cout << "Begin" << endl;
    loadAllPlaces({"hall", "basement", "kitchen"});
    Entity* a = new Axe({"Fire-axe", "Axe", "hall"});
    Entity* c = new Crate({"Big-crate", "Crate", "basement"});
    Entity* k = new Key({"Old-key", "Key", "N/A"});
    Entity* d = new Door({"Old-door", "Door", "hall", "closed", "kitchen", "Old-key"});
    Entity* hs = new Door({"Hall-stairs", "Door", "hall", "open", "basement", "N/A"});
    Entity* bs = new Door({"Base-stairs", "Door", "basement", "open", "hall", "N/A"});
    
    passert(a->name(), "Fire-axe");
    cout << a->pickUp() << endl;
    cout << hs->use() << endl;
    cout << bs->observe() << endl;
    cout << a->use(c) << endl;
    cout << k->pickUp() << endl;
    cout << bs->use() << endl;
    cout << k->use(d) << endl;
    cout << d->use() << endl;

    return 0; 
}