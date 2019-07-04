#include "place.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Begin" << endl;
    Place hall({"Axe","Crate","Key"});
    cout << hall.observe() << endl;
    hall.remove("Key");
    cout << log() << endl;    
    cout << hall.observe() << endl;
    return 0;
}