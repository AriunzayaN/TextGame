#include "entity.h"
#include <vector>
#include <string>

class Manager {
    std::vector<Entity*> allitems;
public:
    Entity* gen(std::string entityName, int& id);
    int     size();
    void    free(int id);
    ~Manager();
};
