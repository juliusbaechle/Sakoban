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
  QObject::connect(&m_gameRules, &GameRules::sglPlaygroundChanged, this, &MainWindow::update);
  update();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setupLabels() {
  for(int x = 0; x < 9; x++) {
    for(int y = 0; y < 9; y++) {
      QLabel* label = new QLabel();
      label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      m_labels.insert(QPoint(x, y), label);
      ui->gridLayout->addWidget(label, y, x, 1, 1);
    }
  }
}

QString toString(QFlags<FieldValue> a_value) {
  if(a_value.testFlag(FieldValue::Player))
    return "player";
  if(a_value.testFlag(FieldValue::Box) && a_value.testFlag(FieldValue::Target))
    return "box on target";
  if(a_value.testFlag(FieldValue::Box))
    return "box";
  if(a_value.testFlag(FieldValue::Target))
    return "target";
  if(a_value.testFlag(FieldValue::Space))
    return "space";
  if(a_value.testFlag(FieldValue::Wall))
    return "wall";
  return "background";
}

void MainWindow::update() {
  Playground playground = m_gameRules.playground();
  for(int x = 0; x < 9; x++) {
    for(int y = 0; y < 9; y++) {
      QPoint p (x, y);
      QString oldProperty = m_labels[p]->property("value").toString();
      QString newProperty = toString(playground[p]);
      if(oldProperty == newProperty) continue;

      m_labels[p]->setProperty("value", newProperty);
      style()->unpolish(m_labels[p]);
      style()->polish(m_labels[p]);
      m_labels[p]->repaint();
    }
  }
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
  if(e->key() == Qt::Key::Key_Up)
    m_gameRules.movePlayer(Direction::Up);
  if(e->key() == Qt::Key::Key_Right)
    m_gameRules.movePlayer(Direction::Right);
  if(e->key() == Qt::Key::Key_Down)
    m_gameRules.movePlayer(Direction::Down);
  if(e->key() == Qt::Key::Key_Left)
    m_gameRules.movePlayer(Direction::Left);
  QMainWindow::keyPressEvent(e);
}
