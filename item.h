#include "entity.h"
#include "manager.h"


class Item{
    Entity* entity;
    Manager* m;
    int id;
public:
    Item(std::string name, Manager* _m);
    std::string use();
    std::string name();
    std::string use(Item& item);
    std::string targeted(Item& item);
    std::string observe();
    std::string pickUp();
    Entity* getEntity();
};