#include <iostream>
#include <cassert>
#include "entities.h"

using namespace std;

void passert(string target, string reference){
    if (target != reference){
        cout << target << endl;
        cout << reference << endl;
        assert(false);
    }
}

int main(){
    Entity* a = new Axe({"Fire axe", "Hall"});
    passert( a->name() , "Fire axe");
    passert( a->pickUp() , "Picked up Fire axe"); 
    // passert( a->observe() , "Red fire axe, looks sharp.");


    Entity* c = new Crate({"Base crate", "Basement"});
    passert( c->name() , "Base crate"); 
    passert( a->use(c) , "Swung Fire axe Box broke open and you see gold inside.");
    passert( c->pickUp() , "It's heavy, can't do it.");


    Entity* k = new Key({"Rusted key", "Basement"});
    passert( k->name() , "Rusted key"); 
    passert( k->targeted(c) , "Can't be used like that."); 

    cout << "Tests passed" << endl;
    
    return 0; 
}