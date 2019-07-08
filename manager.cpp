#include <iostream>
#include "manager.h"
#include "parser.h"

using namespace std;


static map<string, Entity*> allEntities;
static map<string, Place*> allPlaces;

void loadAllPlaces(vector<string>& placeLines){
    for (auto& place: placeLines){
        auto v = split(place);
        allPlaces[v[0]] = new Place(v[0], v[1]);
    }
    allPlaces["inventory"] = new Place({"inventory","default"});
    allPlaces["N/A"] = new Place({"N/A","default"});
    changeCurrentPlace(split(placeLines[0]).front());
};

void loadAllEntities(vector<string>& entityLines){
    for(auto& line: entityLines){
        auto entity = split(line);
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
        else if(classname == "Readable"){
            allEntities[entity[0]] = new Readable(entity);    
        }
        else if(classname == "Button"){
            allEntities[entity[0]] = new Button(entity);    
        }
        else{
            cout << "Unknown entity class name " + classname << endl;
            exit(1);
        }
        getPlace(location)->add(entity.front());
    }
};

void loadTheGame(string fileName){
    vector<string> placeLines, entityLines, messageLines;
    read_sections(fileName, placeLines, entityLines, messageLines);
    loadAllPlaces(placeLines);
    loadAllEntities(entityLines);
    loadAllMessages(messageLines);
};

string saveTheGame(){
    vector<string> places = {getPlace("current")->getName()};
    for(auto place : allPlaces){
        set<string> exclude = {places[0],"inventory","current","N/A"};
        if (exclude.count(place.first) == 0){
            places.push_back(place.second->save());
        }
    }
    string res = flatten_lines(places);
    res += "#enitities\n";
    for(auto entity: allEntities){
        auto entitySave = (entity.second)->save();
        res += flatten(entitySave);
    }
    return res +"#messages\n" + saveAllMessages();
}

Entity* getEntity(std::string entityName){
    if(allEntities.find(entityName) == allEntities.end()){
        return nullptr;
    }
    return allEntities[entityName];
};
Place* getPlace(std::string placeName){
    if(allPlaces.find(placeName) == allPlaces.end()){
        return nullptr;
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
    if(command == "help" || command == "h"){
        return getMessage("help","help");
    }else if(command == "look" || command == "see"){
        return allPlaces["current"]->observe();
    }else if (command == "inventory" || command == "i"){
        return allPlaces["inventory"]->observe();
    }
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
    }if(command == "enter"){
            if(allPlaces["current"]->contains(entity)){
                 return allEntities[entity]->enter();
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
        return allPlaces["current"]->observe();

    }else if(command == "look" || command == "see"){
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
    string s = "LOG: \nplaces: ";
    for(auto& place: allPlaces){
        s += place.first + " ";
    }
    s += "\nentities: ";
    for(auto& entity: allEntities){
        s += entity.first + " ";
    }

    for(auto& place: allPlaces){
        s += place.second->observe() + " \n";
    }
    // s += "\ncurrent place: " + allPlaces["current"]->getName();
    // s += "\ncontents of current place: " + allPlaces["current"]->observe();
    // s += "\ncontents of basement place: " + allPlaces["basement"]->observe();
    // s += "\ncontents of inventory: " + allPlaces["inventory"]->observe();

    return s;
};