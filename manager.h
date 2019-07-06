#pragma once

#include "place.h"
#include "entity.h"
#include <map>
#include <vector>
#include <string>

class Axe: public Entity{
public:
  Axe(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

class Crate: public Entity{
public:
  Crate(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

class Key: public Entity{
public:
  Key(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

class Door: public Entity{
  std::string targetPlace;
  std::string state;
  std::string keyName;
public:
  Door(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

void loadTheGame(std::string);
void loadAllPlaces(std::vector<std::string> places);

Entity* getEntity(std::string);
Place* getPlace(std::string);
void changeCurrentPlace(std::string);
std::string pickEntityUp(std::string);

std::string log();