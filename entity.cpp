#include <string>
#include "entity.h"
using namespace std;

Entity::Entity(string _entityName, string _placeName)
    :entityName(_entityName),placeName(_placeName){}


string Entity::name(){
    return entityName;
}

string Entity::getPlaceName(){
    return placeName;
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