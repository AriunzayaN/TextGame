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
    loadAllPlaces({"hall", "basement", "kitchen"});

    loadAllEntities({ {"fire-axe", "Axe", "hall"},
                        {"old-key", "Key", "N/A"},
                        {"big-crate", "Crate", "basement", "closed","old-key"},
                        {"old-door", "Door", "hall", "closed", "kitchen", "old-key"},
                        {"hall-stairs", "Door", "basement", "open", "hall", "N/A"},
                        {"base-stairs", "Door", "hall", "open", "basement", "N/A"} } );
    
    passert(getEntity("fire-axe")->name(), "fire-axe");
    passert(getEntity("fire-axe")->pickUp(), "Added fire-axe to inventory");
    passert(getEntity("base-stairs")->use(), "You are now in basement");
    passert(getEntity("base-stairs")->observe(), "It's a base-stairs");
    passert(getEntity("fire-axe")->use(getEntity("big-crate")), "Swung fire-axe Box broke open and you see items inside. Items: [old-key] ");
    passert(getEntity("old-key")->pickUp(), "Added old-key to inventory");
    passert(getEntity("hall-stairs")->use(), "You are now in hall");
    passert(getEntity("old-door")->pickUp(), "Can't pick old-door up");
    passert(getEntity("old-door")->shoot(), "Can't shoot with old-door");
    passert(getEntity("old-door")->hit(), "Can't hit with old-door");
    passert(getEntity("old-key")->use(getEntity("old-door")), "Key used. old-key used and old-door opened");
    passert(getEntity("old-door")->use(), "You are now in kitchen");


    cout << "All entities tests passed" << endl;
    return 0; 
}