#pragma once

#include "Playground.h"

class ILevelRepository {
public:
  virtual ~ILevelRepository() = default;

  virtual bool contains(int a_level) = 0;
  virtual Playground get(int a_level) = 0;
  virtual QList<Playground> getAll() = 0;
};
