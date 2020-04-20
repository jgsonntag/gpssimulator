
#include <stdlib.h>

#include "simpleserver.h"
#include "simplesocket.h"

SimpleServer::SimpleServer(Q_UINT16 port,QObject *parent=0)
            : QServerSocket(port,1,parent)
{
  if (!ok())
  {
    qWarning("Failed to bind to specified - exiting\n");
    exit(1);
  }
}

SimpleServer::~SimpleServer()
{
}

void SimpleServer::newConnection(int socket)
{
  SimpleSocket *client = new SimpleSocket(socket,this);
  connect(client,SIGNAL(closingConnection()),this,SLOT(slotDisConnect()));
  connect(this,SIGNAL(sendToClient(QString)),
          client,SLOT(slotSendText(QString)));
  emit newConnect();
}

void SimpleServer::sendText(QString text)
{
  emit sendToClient(text);
}

void SimpleServer::slotDisConnect()
{
  emit disConnect();
}
