#pragma once

#include "place.h"
#include "entity.h"
#include "parser.h"
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
  std::vector<std::string> contents;
  std::string state;
public:
  Crate(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
  std::vector<std::string> save() override;
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
  std::string state;
  std::string targetPlace;
  std::string keyName;
public:
  Door(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::vector<std::string> save() override;
};
std::string saveTheGame();
void loadAllPlaces(std::vector<std::string> places);
void loadAllEntities(std::vector<std::vector<std::string>>);

std::string commandWithOne(std::string);
std::string commandWithTwo(std::string, std::string);
std::string commandWithFour(std::string, std::string, std::string);
std::string playerCommand(std::vector<std::string>);

Entity* getEntity(std::string);
Place* getPlace(std::string);
void changeCurrentPlace(std::string);
std::string pickEntityUp(std::string);

std::string log();