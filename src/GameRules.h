#pragma once

#include <qobject.h>
#include "Playground.h"
#include "ILevelRepository.h"

enum class Direction {
  Up,
  Down,
  Right,
  Left
};

class GameRules : public QObject {
  Q_OBJECT

public:
  GameRules(ILevelRepository& a_repo, int a_level = 1);
  void move(Direction a_direction);
  void resetLevel();

  Playground playground() const { return m_playground; }
  int level() const { return m_level; }

signals:
  void sglPlaygroundChanged(const Playground& a_playground);
  void sglLevelChanged(int a_level);

private:
  void movePlayer(QPoint a_playerPos, QPoint a_nextPos1);
  void moveBox(QPoint a_playerPos, QPoint a_nextPos1, QPoint a_nextPos2);
  void incrementLevel();

  QPoint getPlayerPos(const Playground& a_playground);
  QPoint getNextPos1(const QPoint& a_point, Direction a_direction);
  QPoint getNextPos2(const QPoint& a_point, Direction a_direction);
  bool isLevelFinished(const Playground& a_playground);

private:
  int m_level = 1;
  Playground m_playground;
  ILevelRepository& m_repo;
};
