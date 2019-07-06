#pragma once
#include <string>
#include <vector>
// Skeleton for all Entity items.

class Entity{
  const std::string entityName;
  const std::string placeName;
  const std::string className;
public:
  Entity(std::string, std::string, std::string);
  std::string name();
  std::string getPlaceName();
  std::string getClassName();
  virtual std::string observe();
  virtual std::string pickUp();
  virtual std::string targeted(Entity *entity);
  virtual std::string use();
  virtual std::string use(Entity *entity);
};