#pragma once

#include <qobject.h>
#include "Playground.h"

enum class Direction {
  Up,
  Down,
  Right,
  Left
};

class GameRules : public QObject {
  Q_OBJECT

public:
  GameRules(const Playground& a_playground) : m_playground(a_playground) {}
  void movePlayer(Direction a_direction);

  void setPlayground(const Playground& a_playground);
  Playground playground() { return m_playground; }

signals:
  void sglPlaygroundChanged();

private:
  Playground m_playground;
};
