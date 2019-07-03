#include <string>
#include "entity.h"

class Axe: public Entity{
public:
  Axe(): Entity(){};
  std::string name() override;
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

class Crate: public Entity{
public:
  Crate(): Entity() {};
  std::string name() override;
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};

class Key: public Entity{
public:
  Key(): Entity() {};
  std::string name() override;
  std::string use() override;
  std::string use(Entity *entity) override;
  std::string targeted(Entity *entity) override;
  std::string observe() override;
  std::string pickUp() override;
};