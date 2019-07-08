#include "manager.h"
#include <iostream>
using namespace std;


/*
  Axe
*/
Axe::Axe(vector<string> setup):Entity(setup[0], setup[1], setup[2], "default"){
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
string Axe::pickUp(){
  return pickEntityUp(name());
}

/*
  Crate
*/
Crate::Crate(vector<string> setup):Entity(setup[0], setup[1], setup[2], setup[3]){
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
  if(entity->getClassName() == "Axe" && getState() == "closed"){
    string s = " Items: ";
    setState("open");
    for(auto item:contents){
      s += "[" + item + "] ";
      getEntity(item)->setPlaceName(getPlaceName());
      getPlace("N/A")->remove(item);
      getPlace(getPlaceName())->add(item);
    }
    return "Box broke open and you see items inside." + s ;
  }
  else if(getState() == "open"){
    return "Box is already open";
  }else{
    return "Did nothing to the box";
  }
}

vector<string> Crate::save(){
  auto v = baseSave();
  v.insert( v.end(), contents.begin(), contents.end());
  return v;
};

/*
  Key
*/
Key::Key(vector<string> setup):Entity(setup[0], setup[1], setup[2], "default"){
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

string Key::pickUp(){
  return pickEntityUp(name());
}

/*
  Button
*/
Button::Button(vector<string> setup):Entity(setup[0], setup[1], setup[2], "default"){
  target = setup[4];
}
string Button::use() {
  if(getEntity(target)){
    getEntity(target)->setState("open");
    return target + " is now open";
  }
  else if(getPlace(target)){
    getPlace(target)->setState("open");
    return "You can now enter "+ target;
  }else{
    return "Pushed button " + name();
  }
}
string Button::targeted(Entity *entity) {
  return "Can't use a button like that";
}

/*
  Readable
*/
Readable::Readable(vector<string> setup):Entity(setup[0], setup[1], setup[2], "default"){
  ;
}
string Readable::targeted(Entity *entity) {
  return "Can't use " + name() + " like that";
}

/*
  Door
*/
Door::Door(vector<string> setup):Entity(setup[0], setup[1], setup[2], setup[3]){
  targetPlace = setup[4];
  keyName = setup[5];
}
string Door::use() {
  if(getState() == "closed"){
    return "Seem to be locked";
  }else if(getPlace(targetPlace)->getState() == "forbidden"){
    return getMessage(targetPlace, getPlace(targetPlace)->getState());
  }else{
    changeCurrentPlace(targetPlace);
    return "You are now in " + targetPlace;
  }
};
string Door::use(Entity *entity) {
  return "You can't pick up " + name();
};
string Door::targeted(Entity *entity) {
  if(getState() == "closed" && keyName == entity->name()){
    setState("open");
    return entity->name() + " used and " + name() + " opened";
  }else if(getState() == "open"){
    return name() + " already open";
  }else{
    return "Wrong key";
  }
};
vector<string> Door::save(){
  auto v = baseSave();
  v.push_back(targetPlace);
  v.push_back(keyName);
  return v;
};

string Door::enter(){
  return use();
}