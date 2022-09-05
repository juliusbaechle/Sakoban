#include "testclient.h"

TestClient::~TestClient() {
}

void TestClient::connectClient(const QString& a_ip, int a_port){
}

void TestClient::connectSubscriber(const QString& a_ip, int a_port){
}

void TestClient::notify(const QString& a_method, const QString& a_params) {
}

void TestClient::request(const QString& a_method, const QString& a_params) {
}

void TestClient::subscribe(const QString& a_subscription) {
}

void TestClient::unsubscribe(const QString& a_subscription) {
}

bool TestClient::isClientConnected() {
  return false;
}

bool TestClient::isSubscriberConnected() {
  return false;
}
