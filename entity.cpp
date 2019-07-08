#include <string>
#include "entity.h"
using namespace std;

Entity::Entity(string _entityName, string _className, string _placeName, string _state)
    :entityName(_entityName), className(_className), placeName(_placeName), state(_state){}

string Entity::name(){
    return entityName;
}

string Entity::getPlaceName(){
    return placeName;
}

string Entity::getClassName(){
    return className;
}

string Entity::getState(){
    return state;
}

void Entity::setState(string _state){
        state = _state;
}

vector<string> Entity::baseSave(){
    return {entityName, className, placeName, state};
};

vector<string> Entity::save(){
    return baseSave();
};

void Entity::setPlaceName(string _placeName){
    placeName = _placeName;
};

string Entity::enter(){
    return "Can't enter " + entityName;
}
string Entity::hit(){
    return "Can't hit with " + entityName;
}
string Entity::shoot(){
    return "Can't shoot with " + entityName;
}
string Entity::use(){
    return "Can't use " + entityName;
}
string Entity::use(Entity *entity){
    return "Can't use " + entityName;
}
string Entity::targeted(Entity *entity){
    return "oopsie, shouldn't happen";
}
string Entity::observe(){
    return getMessage(entityName,state);
}
string Entity::pickUp(){
    return "Can't pick " + entityName + " up" ;
}