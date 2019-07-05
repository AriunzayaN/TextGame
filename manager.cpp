#include <iostream>
#include "manager.h"
using namespace std;


static map<string, Entity*> allEntities;
static map<string, Place*> allPlaces;

void loadAllPlaces(vector<string>& places){
    for (auto& place: places){
        allPlaces[place] = new Place(place);
    }
    allPlaces["inventory"] = new Place("inventory");
    allPlaces["current"] = allPlaces[places[0]];
};

void loadAllEntities(map<string, vector<string>>& entities){
    for(auto& entity: entities){
        string classname = entity.second[0];
        string location  = entity.second[1];
        if(classname == "Axe"){
            allEntities[entity.first] = new Axe();    
        }
        else if(classname == "Key"){
            allEntities[entity.first] = new Key();    
        }
        else if(classname == "Crate"){
            allEntities[entity.first] = new Crate();    
        }
        else{
            cout << "Unknown entity class name " + classname << endl;
            exit(1);
        }
        getPlace(location)->add(entity.first);
    }
};

void loadTheGame(vector<string> gameState){
    
};

Entity* getEntity(std::string entityName){
    if(allEntities.find(entityName) == allEntities.end()){
        cout << "Unknown entity name " << entityName << endl;
        exit(1);
    }
    return allEntities[entityName];
};
Place* getPlace(std::string placeName){
    if(allPlaces.find(placeName) == allPlaces.end()){
        cout << "Unknown place name " << placeName << endl;
        exit(1);
    }
    return allPlaces[placeName];
};