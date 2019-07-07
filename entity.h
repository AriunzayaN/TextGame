#pragma once
#include <string>
#include <vector>
// Skeleton for all Entity items.

class Entity{
  const std::string entityName;
  const std::string className;
  std::string placeName;
public:
  Entity(std::string, std::string, std::string);
  std::string name();
  std::string getPlaceName();
  std::string getClassName();
  void setPlaceName(std::string);
  virtual std::string shoot();
  virtual std::string hit();
  virtual std::string observe();
  virtual std::string pickUp();
  virtual std::string targeted(Entity *entity);
  virtual std::string use();
  virtual std::string use(Entity *entity);
};