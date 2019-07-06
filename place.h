#include <string>
#include <set>

class Place {
    std::string name;
    std::set<std::string> contentNames;
public:
    Place(std::string);
    std::string getName();
    std::string observe();
    bool contains(std::string);
    std::string add(std::string);
    std::string remove(std::string);
};