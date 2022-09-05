#include <qapplication.h>
#include <qwidget.h>

#include "testclient.h"
#include "wtestclient.h"

#include <qdir.h>
#include <qfile.h>
#include <qtextstream.h>

inline QString loadAll(QString a_path) {
  QDir::setCurrent(QApplication::applicationDirPath());
  QFile file(a_path);
  if(!file.open(QIODevice::ReadOnly))
    return "";
  QTextStream stream(&file);
  return stream.readAll();
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  TestClient client;
  WTestClient w(client);
  w.setStyleSheet(loadAll(STYLESHEET_PATH));
  w.show();
  return app.exec();
}
