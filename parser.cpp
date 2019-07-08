#include <sstream>
#include <set>
#include <fstream>
#include <iostream>
#include "parser.h"

using namespace std;


vector<string> split(string str){
    stringstream ss;
    ss << str;
    vector<string> v;
    string name;
    while (ss >> name){
        v.push_back(name);
    };
    return v;
}

string flatten(vector<string> v){
    string res;
    for(auto i: v){
        res += i + " ";
    }
    res.back() = '\n';
    return res;
};

string flatten_lines(vector<string> v){
    string res;
    for(auto i: v){
        res += i + "\n";
    }
    return res;
}

bool valid_chars(std::string str){
    set<char> chars = {'/', '-', ' '};
    for(auto c = 'a'; c <= 'z'; c++){
        chars.insert(c);
    }
    for(auto c : str){
        if(chars.count(c) == 0){
            return false;
        }
    }
    return true;
}

bool valid_input(std::vector<std::string> input){
    for(auto s: input){
        if(!valid_chars(s)){
            return false;
        }
    }
    switch(input.size()){
        case 1:{
            const set<string> valid = {"look", "see", "inventory", "i", "help", "h"};
            return valid.count(input[0]) > 0;
        }
        break;
        case 2:{
            const set<string> valid = {"use", "look","see", "get", "grab", "take", "enter"};
            return valid.count(input[0]) > 0;
        }
        break;
        case 4:
            return (input[0] == "use" and input[2] == "on") or
            (input[0] == "hit" and input[2] == "with");
        break;
        default:
            return false;
        break;
    }
}

void read_sections(std::string fileName, vector<string>& places, vector<string>& entities, vector<string>& messages){
    ifstream stateFile(fileName);
    for(string token; getline(stateFile, token) && token[0] != '#';){
        places.push_back(token);
    }
    for(string token; getline(stateFile, token) && token[0] != '#';){
        entities.push_back(token);
    }
    for(string token; getline(stateFile, token);){
        messages.push_back(token);
    }
    stateFile.close();
}