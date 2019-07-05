#include "player.h"
#include <iostream>

using namespace std;

int main(){
    Place hall({"Axe", "Crate", "Key"});

    Player p(&hall);
    cout << p.observe() << endl;
    return 0;
}