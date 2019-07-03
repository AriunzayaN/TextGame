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
    Entity* a = new Axe();
    passert( a->name() , "Axe");
    passert( a->pickUp() , "Picked up fire axe."); 
    passert( a->observe() , "Red fire axe, looks sharp.");


    Entity* c = new Crate();
    passert( c->name() , "Crate"); 
    passert( a->use(c) , "Swung Axe Box broke open and you see gold inside.");
    passert( c->pickUp() , "It's heavy, can't do it.");


    Entity* k = new Key();
    passert( k->name() , "Key"); 
    passert( k->targeted(c) , "Can't be used like that."); 

    cout << "Tests passed" << endl;
    
    return 0; 
}