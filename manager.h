#pragma once

#include "entities.h"
#include <vector>
#include <string>

// Manages all item entities.
// Gives unique Id's
// allitems is static/local

Entity* gen(std::string entityName, int& id);
std::string log();
void free(int id);