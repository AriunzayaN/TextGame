#pragma once
#include <string>
#include <vector>
// Skeleton for all Entity items.

class Entity{
  std::string eName;
public:
  Entity(std::string);
  std::string name();
  virtual std::string observe();
  virtual std::string pickUp();
  virtual std::string targeted(Entity *entity);
  virtual std::string use();
  virtual std::string use(Entity *entity);
};