#pragma once
#include "manager.h"
// Takes care of creation and deletion of each Item

class Item{
    Entity* entity;
    int id;
public:
    Item();
    Item(std::string name);
    std::string use();
    std::string name() const;
    std::string use(Item& item);
    std::string targeted(Item& item);
    std::string observe();
    std::string pickUp();
    Entity* getEntity();
    int getId() const;
    bool operator==(const Item& item) const;
    Item& operator=(Item& item);
    void destroy();
};