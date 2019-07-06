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
    string testFileName = "test.txt";
    loadTheGame(testFileName);
    cout << log() << endl;
    return 0;
}