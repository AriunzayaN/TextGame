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
    Place hall("hall");
    passert( hall.add("Axe"), string("Axe added to hall"));
    passert( hall.add("Crate"), string("Crate added to hall"));
    passert( hall.add("Key"), string("Key added to hall"));
    passert( hall.observe(), string("[Axe] [Crate] [Key] "));
    passert( hall.remove("Crate"), string("Crate removed from hall"));
    passert( hall.observe(), string("[Axe] [Key] "));
    cout << "Place test Pass" << endl;
    return 0;
}