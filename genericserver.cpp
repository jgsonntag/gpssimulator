//
// GenericServer class implementation
//

#include "genericserver.h"
#include "simpleserver.h"

#include <iostream>
using namespace std;

GenericServer::GenericServer(Q_UINT16 port, QWidget *parent, const char *name)
	: QVBox(parent,name)
{

  // Initialize connections counter
  connections = 0;

  // Create the server and connect its slots
  myserver = new SimpleServer(port,this);
  connect(myserver,SIGNAL(newConnect()),this,SLOT(slotNewConnect()));
  connect(myserver,SIGNAL(disConnect()),this,SLOT(slotDisConnect()));

  // Build the GUI
  QString stemp;
  stemp.sprintf("Serving on port %d",port);
  new QLabel(stemp,this);
  connectlabel = new QLabel("Active network listeners: 00",this);
  new QLabel("Current broadcast text:",this);
  outtext = new QLabel(this);
  QFont outfont("Courier",8);
  outtext->setFont(outfont);
  //outtext->setFrameShape(QFrame::LineEditPanel);
  //delete stemp;

}

GenericServer::~GenericServer()
{
}

void GenericServer::slotNewConnect()
{
  QString stemp;

  ++connections;
  stemp.sprintf("Active network listeners: %02d",connections);
  connectlabel->setText(stemp);
}

void GenericServer::slotDisConnect()
{
  QString stemp;

  --connections;
  stemp.sprintf("Active network listeners: %02d",connections);
  connectlabel->setText(stemp);
}

void GenericServer::broadcast_this(QString text)
{
  myserver->sendText(text);
  outtext->setText(text);
}

