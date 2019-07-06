#include <iostream>
#include <fstream>
#include "manager.h"
#include "parser.h"

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
        else if(classname == "Door"){
            allEntities[entity[0]] = new Door(entity);    
        }
        else{
            cout << "Unknown entity class name " + classname << endl;
            exit(1);
        }
        getPlace(location)->add(entity[0]);
    }
};

void loadTheGame(string fileName){
    ifstream stateFile(fileName);
    string token;
    getline(stateFile, token);
    loadAllPlaces(split(token, false));
    
    vector<vector<string>> entitiesSetup;
    while(getline(stateFile, token)){
        entitiesSetup.push_back(split(token, false));
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




string playerCommand(vector<string> command){
    if(command.size() == 1){
        commandWithOne(command[0]);
        
    }else if(command.size() == 2){
        commandWithTwo(command[0], command[1]);

    }else if(command.size() == 4){
        commandWithFour(command[0], command[1], command[2], command[3]);
    }
    
    cout << "unknown command " << command[0] << endl;
    exit(1);
};

string commandWithOne(string command){
    return allPlaces["current"]->observe();
};

string commandWithTwo(string command, string entity){
    if(command == "use"){
            if(allPlaces["current"]->contains(entity) ||
             allPlaces["inventory"]->contains(entity)){
                 return allEntities[entity]->use();
             }else{
                 return entity + " not present";
             }
    }else if(command == "get" || command == "grab" ||
                command == "take"){
        if(allPlaces["current"]->contains(entity) ){
            return allEntities[entity]->use();
        }else{
            return entity + " not present";
        }

    }else if(command == "look"){
        if(allPlaces["current"]->contains(entity) ||
            allPlaces["inventory"]->contains(entity)){
                return allEntities[entity]->observe();
            }else{
            return entity + " not present";
        }
    }
};

string commandWithFour(string command, string entityOfTarget, string fillerCommand, string entityOfUse){
    if(!allPlaces["current"]->contains(entityOfTarget) &&
        !allPlaces["inventory"]->contains(entityOfTarget)){
        return "You don't have access to " + entityOfTarget;


    }else if(!allPlaces["current"]->contains(entityOfUse) &&
            !allPlaces["inventory"]->contains(entityOfUse)){
        return "You don't have access to " + entityOfUse;


    }else if(command == "use"){
        return allEntities[entityOfUse]->use(allEntities[entityOfTarget]);


    }else if(command == "hit"){
        set<string> hittables = {"Axe"};
        if(hittables.count(allEntities[entityOfUse]->getClassName()) == 1 ){
            return allEntities[entityOfUse]->use(allEntities[entityOfTarget]);
        }else{
            return "You can't hit with " + entityOfUse;
        }
    }

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