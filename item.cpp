#include "item.h"
#include "manager.h"

using namespace std;

Item::Item(string name, Manager* _m){
    m = _m;
    entity = m->gen(name, id);
};
string Item::use(){
    return entity->use();
};
string Item::name(){
    return entity->name();
};
string Item::use(Item& item){
    return entity->use(item.getEntity());
};
string Item::targeted(Item& item){
    return entity->targeted(item.getEntity());
};
string Item::observe(){
    return entity->observe();    
};
string Item::pickUp(){
    return entity->pickUp();
};
Entity* Item::getEntity(){
    return entity;
};
