#pragma once

#include <QMainWindow>
#include "GameRules.h"
class QLabel;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(GameRules& a_gameRules, QWidget *parent = nullptr);
  ~MainWindow();

protected:
  void keyPressEvent(QKeyEvent* e) override;

private:
  void setupLabels();
  void onLevelChanged(int a_level);
  void onPlaygroundChanged(const Playground& a_playground);
  QString toString(QFlags<FieldValue> a_value);

private:
  GameRules& m_gameRules;
  QMap<QPoint, QLabel*> m_labels;
  Ui::MainWindow *ui;
};
