#include <string>
#include "entity.h"
using namespace std;

Entity::Entity(string _entityName, string _placeName, string _className)
    :entityName(_entityName),placeName(_placeName), className(_className){}


string Entity::name(){
    return entityName;
}

string Entity::getPlaceName(){
    return placeName;
}

string Entity::getClassName(){
    return className;
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
    return "oopsie, shouldn't happen";
}