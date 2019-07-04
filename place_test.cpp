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
    Place hall({"Axe","Crate","Key"});
    passert( hall.observe(), string("Key,Crate,Axe,"));
    hall.remove("Key");
    passert( hall.observe(), string("Crate,Axe,"));
    return 0;
}