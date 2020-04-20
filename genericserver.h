//
// GenericServer class definition
//

#ifndef GENERICSERVER_H
#define GENERICSERVER_H

#include <qvbox.h>
#include <qlabel.h>
#include <qstring.h>
#include <qlabel.h>

#include "simpleserver.h"

class GenericServer : public QVBox
{

  Q_OBJECT

  public:
    GenericServer(Q_UINT16 port, QWidget *parent=0, const char *name=0);  // Constructor
    ~GenericServer();  // Destructor
    void broadcast_this(QString text);

  private:
    int connections;
    SimpleServer *myserver;
    QLabel *connectlabel;
    QLabel *outtext;

  private slots:
    void slotNewConnect();
    void slotDisConnect();

};

#endif // GENERICSERVER_H
