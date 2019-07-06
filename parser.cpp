#include <sstream>
#include <set>
#include <cctype>
#include <algorithm>
#include "parser.h"

using namespace std;

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return tolower(c); });
    return s;
}

vector<string> split(string str, bool lowercase){
    stringstream ss;
    ss << str;
    vector<string> entitySetup;
    string name;
    while (ss >> name){
        if(lowercase)
            entitySetup.push_back(str_tolower(name));
        else{
            entitySetup.push_back(name);
        }
    };
    return entitySetup;
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
            const set<string> valid = {"look", "see", "inventory"};
            return valid.count(input[0]) > 0;
        }
        break;
        case 2:{
            const set<string> valid = {"use", "look","see", "get", "grab", "take"};
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