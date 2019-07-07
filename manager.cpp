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

void loadAllEntities(vector<vector<string>> entities){
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
    cout << "Game loaded " <<  endl;
};

string flatten(vector<string> v){
    string res;
    for(auto i: v){
        res += i + " ";
    }
    res.back() = '\n';
    return res;
};

string saveTheGame(){
    vector<string> places = {getPlace("current")->getName()};
    for(auto place : allPlaces){
        set<string> exclude = {places[0],"inventory","current","N/A"};
        if (exclude.count(place.first) == 0){
            places.push_back(place.first);
        }
    }
    string res = flatten(places);
    for(auto entity: allEntities){
        res += flatten(entity.second->save());
    }
    return res;
}

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
    allEntities[entity]->setPlaceName("inventory");
    return "Added " + entity + " to inventory";
};


string playerCommand(vector<string> command){
    if(command.size() == 1){
        return commandWithOne(command[0]);
        
    }else if(command.size() == 2){
        return commandWithTwo(command[0], command[1]);

    }else if(command.size() == 4){
        return commandWithFour(command[0], command[1], command[3]);
    }
    
    cout << "unknown command " << command[0] << endl;
    exit(1);
};

string commandWithOne(string command){
    if(command == "look" || command == "see")
        return allPlaces["current"]->observe();
    else if (command == "inventory")
        return allPlaces["inventory"]->observe();
    
    cout << "unknown command " << command << endl;
    exit(1);
    
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
            return allEntities[entity]->pickUp();
        }else{
            return entity + " not present";
        }

    }else if(command == "look" && entity == "around"){

    }
    else if(command == "look" || command == "see"){
        if(entity == "inventory"){
            return allPlaces["inventory"]->observe();
        }else if(allPlaces["current"]->contains(entity) ||
            allPlaces["inventory"]->contains(entity)){
                return allEntities[entity]->observe();
            }else{
            return entity + " not present";
        }
    }

    cout << "unknown command " << command << endl;
    exit(1);
};

string commandWithFour(string command, string entityOfTarget, string entityOfUse){
    if(!allPlaces["current"]->contains(entityOfTarget) &&
        !allPlaces["inventory"]->contains(entityOfTarget)){
        return "You don't have access to " + entityOfTarget;


    }else if(!allPlaces["current"]->contains(entityOfUse) &&
            !allPlaces["inventory"]->contains(entityOfUse)){
        return "You don't have access to " + entityOfUse;


    }else if(command == "use"){
        return allEntities[entityOfTarget]->use(allEntities[entityOfUse]);


    }else if(command == "hit"){
        return allEntities[entityOfUse]->use(allEntities[entityOfTarget]);
    }

    cout << "unknown command " << command << endl;
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
    s += "\ncontents of inventory: " + allPlaces["inventory"]->observe();


    return s;
};