#pragma once

#include "entities.h"
#include "place.h"
#include <map>
#include <vector>
#include <string>

void loadTheGame(std::vector<std::string>);

Entity* getEntity(std::string);
Place* getPlace(std::string);