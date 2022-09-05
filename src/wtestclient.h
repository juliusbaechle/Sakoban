#pragma once

#include <QMainWindow>
#include "testclient.h"

namespace Ui {
  class WTestClient;
}

class WTestClient : public QMainWindow {
  Q_OBJECT

public:
  explicit WTestClient(TestClient& a_client);
  ~WTestClient();

private:
  void onConnectClient();
  void onClientState(bool a_connected);

  void onConnectSubscriber();
  void onSubscriberState(bool a_connected);

  void onNotify();
  void onRequest();

  void onSubscribe();
  void onUnsubscribe();

private:
  void updateButtons();

private:
  TestClient& m_client;
  Ui::WTestClient *ui;
};
