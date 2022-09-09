#include "Sakoban.h"
#include <qdebug.h>

Sakoban::Sakoban(ILevelRepository& a_repo, int a_level)
  : m_repo(a_repo)
{
  assert(m_repo.contains(a_level));
  m_level = a_level;
  m_playground = m_repo.get(a_level);
}

void Sakoban::move(Direction a_direction) {
  QPoint playerPos = getPlayerPos(m_playground);
  QPoint nextPos1 = getNextPos1(playerPos, a_direction);
  QPoint nextPos2 = getNextPos2(playerPos, a_direction);

  if(isLevelFinished(m_playground))
    incrementLevel();
  else if (m_playground[nextPos1].testFlag(FieldValue::Space))
    movePlayer(playerPos, nextPos1);
  else if (m_playground[nextPos1].testFlag(FieldValue::Box) && m_playground[nextPos2].testFlag(FieldValue::Space))
    moveBox(playerPos, nextPos1, nextPos2);
}

QPoint Sakoban::getPlayerPos(const Playground& a_playground) {
  for(int x = 0; x < 9; x++)
    for(int y = 0; y < 9; y++)
      if(a_playground[QPoint(x, y)].testFlag(FieldValue::Player))
        return QPoint(x, y);
  return QPoint();
}

QPoint Sakoban::getNextPos1(const QPoint& a_point, Direction a_direction) {
  if(a_direction == Direction::Up)
    return QPoint(a_point.x(), a_point.y() - 1);
  if(a_direction == Direction::Right)
    return QPoint(a_point.x() + 1, a_point.y());
  if(a_direction == Direction::Down)
    return QPoint(a_point.x(), a_point.y() + 1);
  if(a_direction == Direction::Left)
    return QPoint(a_point.x() - 1, a_point.y());
  return a_point;
}

QPoint Sakoban::getNextPos2(const QPoint& a_point, Direction a_direction) {
  if(a_direction == Direction::Up)
    return QPoint(a_point.x(), a_point.y() - 2);
  if(a_direction == Direction::Right)
    return QPoint(a_point.x() + 2, a_point.y());
  if(a_direction == Direction::Down)
    return QPoint(a_point.x(), a_point.y() + 2);
  if(a_direction == Direction::Left)
    return QPoint(a_point.x() - 2, a_point.y());
  return a_point;
}

bool Sakoban::isLevelFinished(const Playground& a_playground) {
  for(auto& val : a_playground)
    if(val.testFlag(FieldValue::Box) && !val.testFlag(FieldValue::Target))
      return false;
  return true;
}

void Sakoban::incrementLevel() {
  m_level++;
  if(!m_repo.contains(m_level))
    m_level = 1;
  emit sglLevelChanged(m_level);

  m_playground = m_repo.get(m_level);
  emit sglPlaygroundChanged(m_playground);
}

void Sakoban::movePlayer(QPoint a_playerPos, QPoint a_nextPos1) {
  m_playground[a_playerPos].setFlag(FieldValue::Player, false);
  m_playground[a_playerPos].setFlag(FieldValue::Space, true);
  m_playground[a_nextPos1].setFlag(FieldValue::Space, false);
  m_playground[a_nextPos1].setFlag(FieldValue::Player, true);
  emit sglPlaygroundChanged(m_playground);
}

void Sakoban::moveBox(QPoint a_playerPos, QPoint a_nextPos1, QPoint a_nextPos2) {
  m_playground[a_playerPos].setFlag(FieldValue::Player, false);
  m_playground[a_playerPos].setFlag(FieldValue::Space, true);
  m_playground[a_nextPos1].setFlag(FieldValue::Box, false);
  m_playground[a_nextPos1].setFlag(FieldValue::Player, true);
  m_playground[a_nextPos2].setFlag(FieldValue::Space, false);
  m_playground[a_nextPos2].setFlag(FieldValue::Box, true);
  emit sglPlaygroundChanged(m_playground);
}

void Sakoban::resetLevel() {
  m_playground = m_repo.get(m_level);
  emit sglPlaygroundChanged(m_playground);
}
