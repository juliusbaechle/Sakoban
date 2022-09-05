#pragma once

#include <qobject.h>

class TestClient : public QObject {
  Q_OBJECT;

public:
  ~TestClient();

  void connectClient(const QString& a_ip, int a_port);
  void connectSubscriber(const QString& a_ip, int a_port);

  void notify(const QString& a_method, const QString& a_params);
  void request(const QString& a_method, const QString& a_params);

  void subscribe(const QString& a_subscription);
  void unsubscribe(const QString& a_subscription);

  bool isClientConnected();
  bool isSubscriberConnected();

signals:
  void sigClientState(bool);
  void sigSubscriberState(bool);

private:
  int m_lastRequestId = 0;
};
