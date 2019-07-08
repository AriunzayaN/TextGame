#pragma once
#include <string>
#include <vector>

#include "place.h"
// Skeleton for all Entity items.

class Entity{
  const std::string entityName;
  const std::string className;
  std::string placeName;
  std::string state;
public:
  Entity(std::string, std::string, std::string, std::string);
  std::string name();
  std::string getPlaceName();
  std::string getClassName();
  std::vector<std::string> baseSave();
  void setPlaceName(std::string);
  virtual std::string shoot();
  virtual std::string hit();
  virtual std::string observe();
  virtual std::string pickUp();
  virtual std::string enter();
  virtual std::string targeted(Entity *entity);
  virtual std::string use();
  virtual std::string use(Entity *entity);
  virtual std::vector<std::string> save();
};