#include "place.h"
#include <iostream>

using namespace std;


Place::Place(string _name):name(_name){}

string Place::getName(){
    return name;
}
string Place::observe(){
    string s;
    for (auto& name: contentNames){
        s += "[" + name + "] ";
    }
    return s;
};
string Place::add(string contentName){
    contentNames.insert(contentName);
    return contentName + " added to " + name;
};

string Place::remove(string contentName){
    contentNames.erase(contentName);
    return contentName + " removed from " + name;
}
