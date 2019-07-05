#include "player.h"

using namespace std;

Player::Player( Place* place){
    currentPlace = place;
};

Player::~Player( ){
    freeAll();
};

string Player::observe(){
    return currentPlace->observe();    
};

string Player::lookInventory(){
    return inventory.observe();
};

string Player::use(string name){
    return "use" + name;
};
string Player::observe(string name){
    return "observe" + name;
};
string Player::pickUp(string name){
    return "pickup" + name;
};
string Player::use(string used, string targeted){
    return "use" + used + ": " + targeted; 
};