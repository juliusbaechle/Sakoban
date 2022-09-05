#include "wtestclient.h"
#include "ui_wtestclient.h"
#include <qscrollbar.h>
#include <qfiledialog.h>

WTestClient::WTestClient(TestClient& a_client)
  : QMainWindow(nullptr)
  , ui(new Ui::WTestClient)
  , m_client(a_client)
{
  ui->setupUi(this);
  QObject::connect(ui->btnClientConnect, &QPushButton::clicked, this, &WTestClient::onConnectClient);
  QObject::connect(ui->btnSubscriberConnect, &QPushButton::clicked, this, &WTestClient::onConnectSubscriber);
  QObject::connect(ui->btnRequest, &QPushButton::clicked, this, &WTestClient::onRequest);
  QObject::connect(ui->btnNotify, &QPushButton::clicked, this, &WTestClient::onNotify);
  QObject::connect(ui->btnSubscribe, &QPushButton::clicked, this, &WTestClient::onSubscribe);
  QObject::connect(ui->btnUnsubscribe, &QPushButton::clicked, this, &WTestClient::onUnsubscribe);
  QObject::connect(ui->btnClear, &QPushButton::clicked, this, [this](){ ui->log->setText(""); });
  QObject::connect(&m_client, &TestClient::sigClientState, this, &WTestClient::onClientState);
  QObject::connect(&m_client, &TestClient::sigSubscriberState, this, &WTestClient::onSubscriberState);
  updateButtons();
}

WTestClient::~WTestClient() {
  delete ui;
}

void WTestClient::onConnectClient() {
  ui->rbtnClientPort->setChecked(false);
  m_client.connectClient(ui->edtIP->text(), ui->edtClientPort->value());
}

void WTestClient::onConnectSubscriber() {
  ui->rbtnSubscriberPort->setChecked(false);
  m_client.connectSubscriber(ui->edtIP->text(), ui->edtSubscriberPort->value());
}

void WTestClient::onClientState(bool a_connected) {
  ui->rbtnClientPort->setChecked(a_connected);
  updateButtons();
}

void WTestClient::onSubscriberState(bool a_connected) {
  ui->rbtnSubscriberPort->setChecked(a_connected);
  updateButtons();
}

void WTestClient::updateButtons() {
  ui->btnRequest->setEnabled(m_client.isClientConnected());
  ui->btnNotify->setEnabled(m_client.isClientConnected());
  ui->btnSubscribe->setEnabled(m_client.isClientConnected() && m_client.isSubscriberConnected());
  ui->btnUnsubscribe->setEnabled(m_client.isClientConnected() && m_client.isSubscriberConnected());
}

void WTestClient::onNotify() {
  try {
    m_client.notify(ui->edtMethod->text(), ui->edtParams->text());
  } catch(const std::exception& ex) {
  }
}

void WTestClient::onRequest() {
  try {
    m_client.request(ui->edtMethod->text(), ui->edtParams->text());
  } catch(const std::exception& ex) {
  }
}

void WTestClient::onSubscribe() {
  try {
    m_client.subscribe(ui->edtSubscription->text());
  } catch(const std::exception& ex) {
  }
}

void WTestClient::onUnsubscribe() {
  try {
    m_client.unsubscribe(ui->edtSubscription->text());
  } catch(const std::exception& ex) {
  }
}
