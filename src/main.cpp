#include <qapplication.h>
#include <qwidget.h>
#include <qdebug.h>
#include <qdir>

#include "GameRules.h"
#include "MainWindow.h"
#include "levels/HardCodedLevelRepository.h"

inline QString loadAll(QString a_path) {
  QDir::setCurrent(QApplication::applicationDirPath());
  QFile file(a_path);
  if(!file.open(QIODevice::ReadOnly))
    qWarning() << "Not able to find '" << a_path << "' in '" << QDir::currentPath() << '\'';
  QTextStream stream(&file);
  return stream.readAll();
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  HardCodedLevelRepository repo;
  GameRules gameRules(repo, 5);
  MainWindow window (gameRules);
  window.setStyleSheet(loadAll(STYLESHEET_PATH));
  window.show();
  return app.exec();
}
