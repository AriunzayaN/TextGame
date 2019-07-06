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

string playerCommand(vector<string> command){
    if(command.size() == 1){
        return allPlaces["current"]->observe();

    }else if(command.size() == 2){
        if(command[0] == "use"){
            if(allPlaces["current"]->contains(command[1]) ||
             allPlaces["inventory"]->contains(command[1])){
                 return allEntities[command[1]]->use();
             }else{
                 return command[1] + " not present";
             }
        }else if(command[0] == "get" || command[0] == "grab" ||
                 command[0] == "take"){
            if(allPlaces["current"]->contains(command[1]) ){
                return allEntities[command[1]]->use();
            }else{
                return command[1] + " not present";
            }

        }else if(command[0] == "look"){
            if(allPlaces["current"]->contains(command[1]) ||
             allPlaces["inventory"]->contains(command[1])){
                 return allEntities[command[1]]->observe();
             }else{
                return command[1] + " not present";
            }
        }

    }else if(command.size() == 4){
            if(!allPlaces["current"]->contains(command[1]) &&
               !allPlaces["inventory"]->contains(command[1])){
                 return "You don't have access to " + command[1];


             }else if(!allPlaces["current"]->contains(command[3]) &&
                      !allPlaces["inventory"]->contains(command[3])){
                 return "You don't have access to " + command[3];


             }else if(command[0] == "use"){
                    return allEntities[command[3]]->use(allEntities[command[1]]);


             }else if(command[0] == "hit"){
                set<string> hittables = {"Axe"};
                if(hittables.count(allEntities[command[3]]->getClassName()) == 1 ){
                    return allEntities[command[3]]->use(allEntities[command[1]]);
                }else{
                    return "You can't hit with " + command[3];
                }


             }
        
    }
    
    cout << "unknown command " << command[0] << endl;
    exit(1);
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