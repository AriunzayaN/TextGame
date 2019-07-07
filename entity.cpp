#include <string>
#include "entity.h"
using namespace std;

Entity::Entity(string _entityName, string _className, string _placeName)
    :entityName(_entityName), className(_className), placeName(_placeName){}


string Entity::name(){
    return entityName;
}

string Entity::getPlaceName(){
    return placeName;
}

string Entity::getClassName(){
    return className;
}

vector<string> Entity::baseSave(){
    return {entityName, className, placeName};
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
    return "use oopsie, shouldn't happen";
}
string Entity::use(Entity *entity){
    return "oopsie, shouldn't happen";
}
string Entity::targeted(Entity *entity){
    return "oopsie, shouldn't happen";
}
string Entity::observe(){
    return "oopsie, shouldn't happen";
}
string Entity::pickUp(){
    return "Can't pick " + entityName + " up" ;
}