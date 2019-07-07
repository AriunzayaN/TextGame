#include "place.h"
#include <iostream>

using namespace std;


Place::Place(string _name):name(_name){}

string Place::getName(){
    return name;
}
string Place::observe(){
    string s = name + ": ";
    for (auto& name: contentNames){
        s += "[" + name + "] ";
    }
    s+= "\n";
    return s;
};
string Place::add(string contentName){
    contentNames.insert(contentName);
    return contentName + " added to " + name;
};

bool Place::contains(string name){
    return contentNames.count(name) > 0;
}

string Place::remove(string contentName){
    contentNames.erase(contentName);
    return contentName + " removed from " + name;
}
