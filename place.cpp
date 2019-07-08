#include "place.h"
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

static map<string, string> allMessages = {{
"help&help","\
commands:   use; use []; use [] on []\n\
            look; look around; look []; see []\n\
            get []; grab []; take [];\n\
            enter [] \n\
            hit [] with []\n"}};

string saveMessages;

void loadAllMessages(vector<string>& messageLines){
    for(auto& message : messageLines){
        stringstream ss(message);
        string name, state, msg;
        ss >> name >> state;
        getline(ss, msg);
        allMessages[name + "&" + state] = msg.substr(1);
    }
    saveMessages = flatten_lines(messageLines);
};

string Place::getState(){
    return state;
};


string getMessage(string _name, string _state){
    return allMessages[_name + "&" + _state];
}

string saveAllMessages(){
    return saveMessages;
};

Place::Place(string _name, string _state):name(_name),state(_state){}

void Place::setState(string _state){
    state = _state;
}

string Place::getName(){
    return name;
}
string Place::observe(){
    string s = getMessage(name, state) + "\n" + name + ": ";
    for (auto& name: contentNames){
        s += "[" + name + "] ";
    }
    s += "\n";
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

string Place::save(){
    return name + " " + state;
}