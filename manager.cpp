#include <iostream>
#include <fstream>
#include <sstream>
#include "manager.h"
using namespace std;


static map<string, Entity*> allEntities;
static map<string, Place*> allPlaces;

void loadAllPlaces(vector<string> places){
    for (auto& place: places){
        allPlaces[place] = new Place(place);
    }
    allPlaces["inventory"] = new Place("inventory");
    allPlaces["N/A"] = new Place("N/A");
    allPlaces["current"] = allPlaces[places[0]];
};

void loadAllEntities(vector<vector<string>>& entities){
    for(auto& entity: entities){
        string classname = entity[1];
        string location  = entity[2];
        if(classname == "Axe"){
            allEntities[entity[0]] = new Axe(entity);    
        }
        else if(classname == "Key"){
            allEntities[entity[0]] = new Key(entity);    
        }
        else if(classname == "Crate"){
            allEntities[entity[0]] = new Crate(entity);    
        }
        else{
            cout << "Unknown entity class name " + classname << endl;
            exit(1);
        }
        getPlace(location)->add(entity[0]);
    }
};

vector<string> split(string str){
    stringstream ss;
    ss << str;
    vector<string> entitySetup;
    string name;
    while (ss >> name){
        entitySetup.push_back(name);
    };
    return entitySetup;
}


void loadTheGame(string fileName){
    ifstream stateFile(fileName);
    string token;
    getline(stateFile, token);
    loadAllPlaces(split(token));
    
    vector<vector<string>> entitiesSetup;
    while(getline(stateFile, token)){
        entitiesSetup.push_back(split(token));
    }
    loadAllEntities(entitiesSetup);
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

void changeCurrentPlace(string place){
    allPlaces["current"] = allPlaces[place];
};

string pickEntityUp(string entity){
    allPlaces["inventory"]->add(entity);
    allPlaces["current"]->remove(entity);
    return "Added " + entity + " to inventory";
};

string log(){
    string s = "places: ";
    for(auto& place: allPlaces){
        s += place.first + " ";
    }
    s += "\nentities: ";
    for(auto& entity: allEntities){
        s += entity.first + " ";
    }
    s += "\ncurrent place: " + allPlaces["current"]->getName();
    s += "\ncontents of current place: " + allPlaces["current"]->observe();
    s += "\ncontents of basement place: " + allPlaces["basement"]->observe();

    return s;
};