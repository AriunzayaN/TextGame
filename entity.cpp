#include <string>
#include "entity.h"
using namespace std;

Entity::Entity(string setup){
    eName = setup;
}
string Entity::use(){
    return "use oopsie, shouldn't happen";
}
string Entity::name(){
    return eName;
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