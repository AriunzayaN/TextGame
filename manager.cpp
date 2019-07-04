#include "manager.h"
#include "entities.h"

using namespace std;

Entity* Manager::gen(string entityName, int& id){
    Entity* ptr; //nullptr
    if(entityName == "Axe"){
        ptr = new Axe();
    }else if(entityName == "Crate"){
        ptr = new Crate();
    }else if(entityName == "Key"){
        ptr = new Key();
    }
    id = size();
    allitems.push_back(ptr);
    return ptr;
};
int     Manager::size(){
    return allitems.size();
};
void    Manager::free(int id){
    delete allitems[id];
};
Manager::~Manager(){
    for (int i = 0; i < size(); i++)
    {
        if(allitems[i] != nullptr){
            free(i);
        }
    }
};