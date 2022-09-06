#pragma once

#include <qmap.h>
#include <qpoint.h>
#include <qobject.h>

enum class FieldValue {
  Background = 0x00,
  Space      = 0x01,
  Wall       = 0x02,
  Box        = 0x04,
  Player     = 0x08,
  Target     = 0x10
};

inline bool operator<(const QPoint& p1, const QPoint& p2) {
  if(p1.y() != p2.y())
    return p1.y() < p2.y();
  return p1.x() < p2.x();
}

typedef QMap<QPoint, QFlags<FieldValue>> Playground;
