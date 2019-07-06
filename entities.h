#include <string>
#include "entity.h"

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