#include <string>
#include <vector>
#include <set>
#include "parser.h"

class Place {
    std::string name;
    std::string state;
    std::set<std::string> contentNames;
public:
    Place(std::string, std::string);
    std::string getName();
    std::string observe();
    std::string getState();
    void setState(std::string);
    bool contains(std::string);
    std::string add(std::string);
    std::string remove(std::string);
    std::string save();
};

void loadAllMessages(std::vector<std::string>& messageLines);
std::string saveAllMessages();
std::string getMessage(std::string, std::string);