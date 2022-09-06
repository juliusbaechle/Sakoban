#include "HardCodedLevelRepository.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "Level7.h"
#include "Level8.h"
#include "Level9.h"
#include "Level10.h"
#include "Level11.h"
#include "Level12.h"
#include "Level13.h"
#include "Level14.h"
#include "Level15.h"

HardCodedLevelRepository::HardCodedLevelRepository() {
  m_levels = {
    { 1, level1 },
    { 2, level2 },
    { 3, level3 },
    { 4, level4 },
    { 5, level5 },
    { 6, level6 },
    { 7, level7 },
    { 8, level8 },
    { 9, level9 },
    { 10, level10 },
    { 11, level11 },
    { 12, level12 },
    { 13, level13 },
    { 14, level14 },
    { 15, level15 }
  };
}

bool HardCodedLevelRepository::contains(int a_level) {
  return m_levels.contains(a_level);
}

Playground HardCodedLevelRepository::get(int a_level) {
  if(m_levels.contains(a_level))
    return m_levels[a_level];
  return m_levels.first();
}
