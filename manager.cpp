#include "manager.h"

using namespace std;

static vector<Entity*> allEntities;

Entity* gen(string entityName, int& id){
    id = allEntities.size();
    if(entityName == "Axe"){
        allEntities.push_back( new Axe());
    }else if(entityName == "Crate"){
        allEntities.push_back( new Crate());
    }else if(entityName == "Key"){
        allEntities.push_back(new Key());
    }
    return allEntities.back();
};

string log(){
    string msg = "log: ";
    for(auto e: allEntities){
        if(e == nullptr){
            msg += "null";
        }
        else{
            msg += e->name();
        }
        msg += ",";
    }
    return msg;
}

void free(int id){
    delete allEntities[id];
    allEntities[id] = nullptr;
};