#include <string>
#include "place.h"

class Player{
    Place inventory;
    Place* currentPlace;
public:
    Player( Place* place);
    ~Player( );
    std::string observe();
    std::string lookInventory();
    std::string use(std::string name);
    std::string observe(std::string name);
    std::string pickUp(std::string name);
    std::string use(std::string used, std::string targeted);
};