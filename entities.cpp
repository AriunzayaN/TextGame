#include "manager.h"
#include <iostream>
using namespace std;


/*
  Axe
*/
Axe::Axe(vector<string> setup):Entity(setup[0], setup[2], setup[1]){
  ;
}
string Axe::use(){
  return "Swing swing.";
}
string Axe::use(Entity *entity){
  return "Swung " + name() + " " + entity->targeted(this);
}
string Axe::targeted(Entity *entity){
  return "Does nothing to the axe.";
}
string Axe::observe(){
  return "Red fire axe, looks sharp.";
}
string Axe::pickUp(){
  return pickEntityUp(name());
}

/*
  Crate
*/
Crate::Crate(vector<string> setup):Entity(setup[0], setup[2], setup[1]){
  ;
}
string Crate::use(){
  return "It's heavy, not sure how to use it.";
}
string Crate::use(Entity *entity){
  return "It's heavy, not sure how to use it.";
}
string Crate::targeted(Entity *entity){
  if(entity->name() == "Fire-axe"){
    return "Box broke open and you see gold inside.";
  }
  else{
    return "Did nothing to the box.";
  }
}
string Crate::observe(){
  return "Heavy looking box, wonder what's inside.";
}
string Crate::pickUp(){
  return pickEntityUp(name());
}

/*
  Key
*/
Key::Key(vector<string> setup):Entity(setup[0], setup[2], setup[1]){
  ;
}
string Key::use() {
  return "You look through the keyhole, nothing out of the ordinary.";
}
string Key::use(Entity *entity) {
  return "Key used.";
}
string Key::targeted(Entity *entity) {
  return "Can't be used like that.";
}

string Key::observe() {
  return "It is a key, wonder what it opens.";
}

string Key::pickUp(){
  return pickEntityUp(name());
}


/*
  Door
*/
Door::Door(vector<string> setup):Entity(setup[0], setup[2], setup[1]){
  state = setup[3];
  targetPlace = setup[4];
  keyName = setup[5];
}
string Door::use() {
  if(state == "close"){
    return "Seem to be locked";
  }else{
    changeCurrentPlace(targetPlace);
    return "You are now in " + targetPlace;
  }
};
string Door::use(Entity *entity) {
  return "You can't pick up " + name();
};
string Door::targeted(Entity *entity) {
  if(state == "close" && keyName == entity->name()){
    state = "open";
    return entity->name() + " used and " + name() + "opened";
  }else if(state == "open"){
    return name() + " already open";
  }else{
    return "Wrong key";
  }
};
string Door::observe() {
 return "It's a " + name();
};
string Door::pickUp() {
 return "Can't pickup";
};