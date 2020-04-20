/***************************************************************************
                          simplesocket.cpp  -  description
                             -------------------
    begin                : Wed Sep 10 2003
    copyright            : (C) 2003 by John Sonntag
    email                :
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

//#include <qtextstream.h>

#include <iostream>
using namespace std;

#include "simplesocket.h"

SimpleSocket::SimpleSocket(int socket, QObject *parent, const char *name)
            : QSocket(parent,name)
{
  connect(this,SIGNAL(connectionClosed()),this,SLOT(slotCloseConnection()));
  setSocket(socket);
  out = new QTextStream(this);
  cout << peerAddress().toString() << '\n';
}

SimpleSocket::~SimpleSocket()
{
}

void SimpleSocket::slotCloseConnection()
{
  emit closingConnection();
  delete this;
}

void SimpleSocket::slotSendText(QString text)
{
//  QTextStream out(this);
  *out << text << endl;
}
