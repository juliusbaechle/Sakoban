#pragma once

#include "ILevelRepository.h"

class HardCodedLevelRepository : public ILevelRepository {
public:
  HardCodedLevelRepository();

  bool contains(int a_level) override;
  Playground get(int a_level) override;
  QList<Playground> getAll() override;

private:
  QMap<int, Playground> m_levels;
};
