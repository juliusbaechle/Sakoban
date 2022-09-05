#include "GameRules.h"
#include <qdebug.h>

inline QPoint getPlayerPos(const Playground& a_playground) {
  for(int x = 0; x < 9; x++)
    for(int y = 0; y < 9; y++)
      if(a_playground[QPoint(x, y)].testFlag(FieldValue::Player))
        return QPoint(x, y);
  return QPoint();
}

inline QPoint getNextPos1(const QPoint& a_point, Direction a_direction) {
  if(a_direction == Direction::Up)
    return QPoint(a_point.x(), a_point.y() - 1);
  if(a_direction == Direction::Right)
    return QPoint(a_point.x() + 1, a_point.y());
  if(a_direction == Direction::Down)
    return QPoint(a_point.x(), a_point.y() + 1);
  return QPoint(a_point.x() - 1, a_point.y());
}

inline QPoint getNextPos2(const QPoint& a_point, Direction a_direction) {
  if(a_direction == Direction::Up)
    return QPoint(a_point.x(), a_point.y() - 2);
  if(a_direction == Direction::Right)
    return QPoint(a_point.x() + 2, a_point.y());
  if(a_direction == Direction::Down)
    return QPoint(a_point.x(), a_point.y() + 2);
  return QPoint(a_point.x() - 2, a_point.y());
}

inline bool isLevelFinished(const Playground& a_playground) {
  for(auto& val : a_playground)
    if(val.testFlag(FieldValue::Box) && !val.testFlag(FieldValue::Target))
      return false;
  return true;
}

void GameRules::movePlayer(Direction a_direction) {
  QPoint playerPos = getPlayerPos(m_playground);
  QPoint nextPos1 = getNextPos1(playerPos, a_direction);
  QPoint nextPos2 = getNextPos2(playerPos, a_direction);

  if (m_playground[nextPos1].testFlag(FieldValue::Space) && !m_playground[nextPos1].testFlag(FieldValue::Box)) {
    m_playground[playerPos].setFlag(FieldValue::Player, false);
    m_playground[nextPos1].setFlag(FieldValue::Player, true);
    emit sglPlaygroundChanged();
  }

  if (m_playground[nextPos1].testFlag(FieldValue::Box) && m_playground[nextPos2].testFlag(FieldValue::Space)) {
    m_playground[playerPos].setFlag(FieldValue::Player, false);
    m_playground[nextPos1].setFlag(FieldValue::Player, true);
    m_playground[nextPos1].setFlag(FieldValue::Box, false);
    m_playground[nextPos2].setFlag(FieldValue::Box, true);
    emit sglPlaygroundChanged();

    if(isLevelFinished(m_playground))
      qDebug() << "level finished!";
  }
}

void GameRules::setPlayground(const Playground& a_playground) {
  m_playground = a_playground;
  emit sglPlaygroundChanged();
}
