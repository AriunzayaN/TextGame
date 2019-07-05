#include "item.h"
#include <map>
#include <utility>

class Place {
    std::string name;
    std::map<std::string, Item> items;
public:
    Place();
    Place(std::string, std::vector<std::string> );
    std::string observe();
    std::string add(Item);
    bool contains(std::string);
    std::string pickup(std::string, Place&);
    std::string remove(std::string);
    Item& getItem(std::string);
};