#include "place.h"
#include <iostream>

using namespace std;

Place::Place(){
    ;
}

Place::Place(string _name, vector <string> _contents): name(_name){
    for (string content: _contents){
        items.emplace(make_pair(content, content));
    }
}

string Place::observe(){
    string s;
    for (auto& item: items){
        s += "[" + item.first + "] ";
    }
    return s;
};

string Place::add(Item item){
    items[item.name()] = item;
    return item.name() + " added to " + name;
};

string Place::pickup(std::string _name, Place& _inventory){
    Item item = items[_name];
    items.erase(_name);
    return _inventory.add(item);
}

bool Place::contains(std::string _name){
    return items.count(_name) > 0;
}

string Place::remove(std::string _name){
    items.erase(_name);
    return _name + " removed from " + name;
}