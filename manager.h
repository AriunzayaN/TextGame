#pragma once

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
  std::string pickUp() override;
};

class Crate: public Entity{
  std::vector<std::string> contents;
public:
  Crate(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::vector<std::string> save() override;
};

class Key: public Entity{
public:
  Key(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string pickUp() override;
};

class Button: public Entity{
  std::string target;
  std::string targetState;
public:
  Button(std::vector<std::string> setup);
  std::string use() override;
  std::string targeted(Entity *entity) override;
  std::vector<std::string> save() override;
};

class Readable: public Entity{
public:
  Readable(std::vector<std::string> setup);
  std::string targeted(Entity *entity) override;
};

class Door: public Entity{
  std::string targetPlace;
  std::string keyName;
public:
  Door(std::vector<std::string> setup);
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::vector<std::string> save() override;
  std::string enter() override;
};


void loadTheGame(std::string);
std::string saveTheGame();
void loadAllPlaces(std::vector<std::string>&);
void loadAllEntities(std::vector<std::string>&);

std::string commandWithOne(std::string);
std::string commandWithTwo(std::string, std::string);
std::string commandWithFour(std::string, std::string, std::string);
std::string playerCommand(std::vector<std::string>);

Entity* getEntity(std::string);
Place* getPlace(std::string);
void changeCurrentPlace(std::string);
std::string pickEntityUp(std::string);

std::string log();