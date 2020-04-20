#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <qserversocket.h>
#include <simplesocket.h>


class SimpleServer : public QServerSocket
{
  Q_OBJECT

  public:
    SimpleServer(Q_UINT16 port,QObject *parent);
    ~SimpleServer();
    void newConnection(int socket);
    void sendText(QString text);

  signals:
    void newConnect();
    void sendToClient(QString text);
    void disConnect();

  private slots:
    void slotDisConnect();
    
};

#endif
