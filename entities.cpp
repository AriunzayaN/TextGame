#include "entities.h"

using namespace std;


 string Axe::name(){
    return "Axe";
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
    return "Picked up fire axe.";
  }

 string Crate::name(){
    return "Crate";
  }
 string Crate::use(){
    return "It's heavy, not sure how to use it.";
  }
 string Crate::use(Entity *entity){
    return "It's heavy, not sure how to use it.";
  }
 string Crate::targeted(Entity *entity){
    if(entity->name() == "Axe"){
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
    return "it's heavy, can't do it.";
  }

 string Key::name() {
    return "Key";
  }
 string Key::use() {
    return "Can't use alone.";
  }
 string Key::use(Entity *entity) {
    return "Key used.";
  }
 string Key::targeted(Entity *entity) {
    return "Can't be used like that.";
  }
 string Key::observe() {
    return "It's an old key.";
  }
 string Key::pickUp() {
    return "Key picked up.";
  }