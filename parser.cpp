#include <sstream>

#include "parser.h"

using namespace std;

vector<string> split(string str){
    stringstream ss;
    ss << str;
    vector<string> entitySetup;
    string name;
    while (ss >> name){
        entitySetup.push_back(name);
    };
    return entitySetup;
}
