#pragma once
#include <string>

// Skeleton for all Entity items.

class Entity{
public:
  virtual std::string use();
  virtual std::string name();
  virtual std::string use(Entity *entity);
  virtual std::string targeted(Entity *entity);
  virtual std::string observe();
  virtual std::string pickUp();
};