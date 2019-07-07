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
    string testFileName = "designs/example.txt";
    loadTheGame(testFileName);
    getPlace("inventory")->add("gun");
    cout << log() << endl;
    cout << "All manager tests passed" << endl;
    return 0;
}