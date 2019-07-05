#include "item.h"
#include <unordered_set>
#include <functional>


class ItemHash{
public:
    size_t operator()(const Item& item) const{
        return std::hash<int>()(item.getId());
    }
};

class Place {
    std::unordered_set<Item, ItemHash> contents;
public:
    Place();
    Place(std::vector<std::string> _contents);
    std::string observe();
    void remove(std::string name);

};