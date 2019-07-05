#include "place.h"
#include <iostream>
#include <cassert>

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
    Place hall("Hall",{"Axe","Crate","Key"});
    passert( hall.observe(), string("[Axe] [Crate] [Key] "));
    passert( hall.remove("Key"), string("Key removed from Hall"));
    passert( hall.observe(), string("[Axe] [Crate] "));
    passert( log(), string("log: Axe,Crate,Key,"));
    Place room("Room",{"Key"});
    passert(room.pickup("Key", hall), string("Key added to Hall"));
    passert(hall.observe(), string("[Axe] [Crate] [Key] "));
    passert(room.observe(), string(""));
    passert( log(), string("log: Axe,Crate,Key,Key,"));
    cout << "Place test Pass" << endl;
    return 0;
}