#pragma once

#include <QMainWindow>
#include "Sakoban.h"
class QLabel;

namespace Ui {
  class SakobanUI;
}

class SakobanUI : public QMainWindow {
  Q_OBJECT

public:
  explicit SakobanUI(Sakoban& a_sakoban, QWidget *parent = nullptr);
  ~SakobanUI();

protected:
  void keyPressEvent(QKeyEvent* e) override;

private:
  void setupLabels();
  void onLevelChanged(int a_level);
  void onPlaygroundChanged(const Playground& a_playground);
  QString toString(QFlags<FieldValue> a_value);

private:
  Sakoban& m_sakoban;
  QMap<QPoint, QLabel*> m_labels;
  Ui::SakobanUI *ui;
};
