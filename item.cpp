#include "item.h"
#include <iostream>

using namespace std;

Item::Item(){}

Item::Item(string name){
    entity = gen(name, id);
};
void Item::destroy(){
    free(id);
};
string Item::use(){
    return entity->use();
};
string Item::name() const{
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
int Item::getId() const{
    return id;    
};
bool Item::operator==(const Item& item) const{
    return id == item.getId();
};

Item& Item::operator=(Item& item){
    entity = item.getEntity();
    id = item.getId();
    return *this;
}