#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <qpushbutton.h>
#include <QKeyEvent>
#include <qlabel.h>
#include <qstyle.h>

MainWindow::MainWindow(GameRules& a_gameRules, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_gameRules(a_gameRules)
{
  ui->setupUi(this);
  setupLabels();
  QObject::connect(&m_gameRules, &GameRules::sglPlaygroundChanged, this, &MainWindow::onPlaygroundChanged);
  QObject::connect(&m_gameRules, &GameRules::sglLevelChanged, this, &MainWindow::onLevelChanged);
  onPlaygroundChanged(m_gameRules.playground());
  onLevelChanged(m_gameRules.level());
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setupLabels() {
  for(int x = 0; x < 9; x++) {
    for(int y = 0; y < 9; y++) {
      QLabel* label = new QLabel(this);
      label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      m_labels.insert(QPoint(x, y), label);
      ui->gridLayout->addWidget(label, y, x, 1, 1);
    }
  }
}

void MainWindow::onLevelChanged(int a_level) {
  setWindowTitle(QString("Sakoban - Level %1").arg(a_level));
  onPlaygroundChanged(m_gameRules.playground());
}

void MainWindow::onPlaygroundChanged(const Playground& a_playground) {
  for(int x = 0; x < 9; x++) {
    for(int y = 0; y < 9; y++) {
      QPoint p (x, y);
      QString oldProperty = m_labels[p]->property("value").toString();
      QString newProperty = toString(a_playground[p]);
      if(oldProperty == newProperty) continue;

      m_labels[p]->setProperty("value", newProperty);
      style()->unpolish(m_labels[p]);
      style()->polish(m_labels[p]);
      m_labels[p]->repaint();
    }
  }
}

QString MainWindow::toString(QFlags<FieldValue> a_value) {
  if(a_value.testFlag(FieldValue::Space) && a_value.testFlag(FieldValue::Target))
    return "target";
  if(a_value.testFlag(FieldValue::Box) && a_value.testFlag(FieldValue::Target))
    return "box on target";
  if(a_value.testFlag(FieldValue::Player))
    return "player";
  if(a_value.testFlag(FieldValue::Box))
    return "box";
  if(a_value.testFlag(FieldValue::Space))
    return "space";
  if(a_value.testFlag(FieldValue::Wall))
    return "wall";
  return "background";
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
  if(e->key() == Qt::Key::Key_Up)
    m_gameRules.move(Direction::Up);
  if(e->key() == Qt::Key::Key_Right)
    m_gameRules.move(Direction::Right);
  if(e->key() == Qt::Key::Key_Down)
    m_gameRules.move(Direction::Down);
  if(e->key() == Qt::Key::Key_Left)
    m_gameRules.move(Direction::Left);
  if(e->key() == Qt::Key::Key_R)
    m_gameRules.resetLevel();
  QMainWindow::keyPressEvent(e);
}
