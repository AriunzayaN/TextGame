#include "manager.h"
#include <iostream>
using namespace std;


/*
  Axe
*/
Axe::Axe(vector<string> setup):Entity(setup[0], setup[1], setup[2]){
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
Crate::Crate(vector<string> setup):Entity(setup[0], setup[1], setup[2]){
  state = setup[3];
  for(auto it = setup.begin() + 4; it != setup.end(); it++){
    contents.push_back(*it);
  }
}
string Crate::use(){
  return "It's heavy, not sure how to use it.";
}
string Crate::use(Entity *entity){
  return "It's heavy, not sure how to use it.";
}
string Crate::targeted(Entity *entity){
  if(entity->getClassName() == "Axe" && state == "closed"){
    string s = " Items: ";
    state == "open";
    for(auto item:contents){
      s += "[" + item + "] ";
      getEntity(item)->setPlaceName(getPlaceName());
      getPlace("N/A")->remove(item);
      getPlace(getPlaceName())->add(item);
    }
    return "Box broke open and you see items inside." + s ;
  }
  else if(state == "open"){
    return "Box is already open";
  }else{
    return "Did nothin to the box";
  }
}
string Crate::observe(){
  return "Heavy looking box, wonder what's inside.";
}
string Crate::pickUp(){
  return pickEntityUp(name());
}

vector<string> Crate::save(){
  auto v = baseSave();
  v.push_back(state);
  v.insert( v.end(), contents.begin(), contents.end());
  return v;
};

/*
  Key
*/
Key::Key(vector<string> setup):Entity(setup[0], setup[1], setup[2]){
  ;
}
string Key::use() {
  return "You look through the keyhole, nothing out of the ordinary.";
}
string Key::use(Entity *entity) {
  return "Key used. " + entity->targeted(this);
}
string Key::targeted(Entity *entity) {
  return "Can't use a key like that";
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
Door::Door(vector<string> setup):Entity(setup[0], setup[1], setup[2]){
  state = setup[3];
  targetPlace = setup[4];
  keyName = setup[5];
}
string Door::use() {
  if(state == "closed"){
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
  if(state == "closed" && keyName == entity->name()){
    state = "open";
    return entity->name() + " used and " + name() + " opened";
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

vector<string> Door::save(){
  auto v = baseSave();
  v.push_back(state);
  v.push_back(targetPlace);
  v.push_back(keyName);
  return v;
};
