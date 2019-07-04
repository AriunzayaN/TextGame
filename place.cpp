#include "place.h"
#include <iostream>

using namespace std;

Place::Place(vector <string> _contents){
    for (string content: _contents){
        contents.emplace(content);
    }
}

string Place::observe(){
    string s;
    for (const Item& content: contents){
        s += "[" + content.name() + "] ";
    }
    return s;
};

void Place::remove(string name){
    for (auto it = contents.begin(); it != contents.end();)
    {
        if( it->name() == name){
            it = contents.erase(it);
        }
        else{
            ++it;
        }
    }
    
};