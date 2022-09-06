#include "SakobanUI.h"
#include "ui_SakobanUI.h"
#include <qpushbutton.h>
#include <QKeyEvent>
#include <qlabel.h>
#include <qstyle.h>

SakobanUI::SakobanUI(Sakoban& a_sakoban, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SakobanUI),
  m_sakoban(a_sakoban)
{
  ui->setupUi(this);
  setupLabels();
  QObject::connect(&m_sakoban, &Sakoban::sglPlaygroundChanged, this, &SakobanUI::onPlaygroundChanged);
  QObject::connect(&m_sakoban, &Sakoban::sglLevelChanged, this, &SakobanUI::onLevelChanged);
  onPlaygroundChanged(m_sakoban.playground());
  onLevelChanged(m_sakoban.level());
}

SakobanUI::~SakobanUI() {
  delete ui;
}

void SakobanUI::setupLabels() {
  for(int x = 0; x < 9; x++) {
    for(int y = 0; y < 9; y++) {
      QLabel* label = new QLabel(this);
      label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      m_labels.insert(QPoint(x, y), label);
      ui->gridLayout->addWidget(label, y, x, 1, 1);
    }
  }
}

void SakobanUI::onLevelChanged(int a_level) {
  setWindowTitle(QString("Sakoban - Level %1").arg(a_level));
  onPlaygroundChanged(m_sakoban.playground());
}

void SakobanUI::onPlaygroundChanged(const Playground& a_playground) {
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

QString SakobanUI::toString(QFlags<FieldValue> a_value) {
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

void SakobanUI::keyPressEvent(QKeyEvent* e) {
  if(e->key() == Qt::Key::Key_Up)
    m_sakoban.move(Direction::Up);
  if(e->key() == Qt::Key::Key_Right)
    m_sakoban.move(Direction::Right);
  if(e->key() == Qt::Key::Key_Down)
    m_sakoban.move(Direction::Down);
  if(e->key() == Qt::Key::Key_Left)
    m_sakoban.move(Direction::Left);
  if(e->key() == Qt::Key::Key_R)
    m_sakoban.resetLevel();
  QMainWindow::keyPressEvent(e);
}
