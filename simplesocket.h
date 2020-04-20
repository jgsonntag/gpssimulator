/***************************************************************************
                          simplesocket.h  -  description
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

#ifndef SIMPLESOCKET_H
#define SIMPLESOCKET_H

#include <qsocket.h>
#include <qtextstream.h>

/**
  *@author John Sonntag
  */

class SimpleSocket : public QSocket
{
  Q_OBJECT

  public:
    SimpleSocket(int socket, QObject *parent=0, const char *name=0);
    ~SimpleSocket();

  signals:
    void closingConnection();

  public slots:
    void slotSendText(QString text);

  private slots:
    void slotCloseConnection();

  private:
    QTextStream *out;

};

#endif
