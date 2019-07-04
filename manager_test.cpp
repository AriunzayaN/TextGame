#include <cassert>
#include <iostream>
#include <string>
#include "manager.h"

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
    Manager m = Manager();
    int id;
    Entity* axe = m.gen("Axe", id);

    passert(axe->name(), string("Axe"));
    passert(m.size(), 1);
    passert(id, 0);
    m.free(0);
    cout << "Tests passed." << endl;


}