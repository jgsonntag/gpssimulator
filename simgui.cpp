//
// Simgui class implementation
//

#include <qapplication.h>
#include <qmessagebox.h>
#include <qhgroupbox.h>
#include <qvgroupbox.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qdialog.h>

#include "simgui.h"
#include "setupgui.h"

#include <iostream>
using namespace std;

double t0,lat0,lon0,ht0;

Simgui::Simgui()
{

  // Get starting info from user
  Setupgui *msg = new Setupgui(67.0,307.0,2000.0,this);
  while (msg->exec() == QDialog::Rejected)
  {
    QMessageBox::about(this,"Invalid\n",
                     "Starting values invalid\n"
                     "Check your lat/lon limits\n");
  }

  // Build the main menubar and make connections
  mainmenu = new QMenuBar(this);
  QPopupMenu *filemenu = new QPopupMenu(mainmenu);
  QPopupMenu *helpmenu = new QPopupMenu(mainmenu);
  filemenu->insertItem("Quit",qApp,SLOT(quit()));
  helpmenu->insertItem("About",this,SLOT(about()));
  mainmenu->insertItem("File",filemenu);
  mainmenu->insertItem("Help",helpmenu);

  // Build the flight controls
  QHGroupBox *controls = new QHGroupBox("Heading, speed and roc",this);
  heading = new QSpinBox(0,359,1,controls);
  heading->setValue(000);
  heading->setSuffix(" deg true");
  heading->setWrapping(true);
  speed   = new QSpinBox(0,2000,10,controls);
  speed->setValue(250);
  speed->setSuffix(" knots");
  roc     = new QSpinBox(-5000,5000,500,controls);
  roc->setValue(0);
  roc->setSuffix(" fpm");

  // Build the update interval controls
  QHGroupBox *netcontrols = new QHGroupBox("Update interval (sec)",this);
  interval = new QComboBox(netcontrols);
  interval->insertItem("1",0);
  interval->insertItem("0.5",1);
  interval->insertItem("0.1",2);
  interval->setCurrentItem(1);
  interval->setMaximumSize(70,30);
  dt = 0.5;
  connect(interval,SIGNAL(activated(int)),
          this,SLOT(intervalChanged(int)));

  // Build the current position display
  position = new Position(t0,lat0,lon0,ht0);
  QVGroupBox *currentpos = new QVGroupBox("Current position",this);
  poslabel = new QLabel(currentpos);

  // Build the network interface
  QVGroupBox *networkstuff = new QVGroupBox("Network server",this);
  gpsserver = new GenericServer(4040,networkstuff);

  // Build and start the timer
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),SLOT(update()));
  timer->start((int)(dt*1000));

}


Simgui::~Simgui()
{
  delete mainmenu;
  delete heading;
  delete speed;
  delete roc;
  delete interval;
  delete position;
  delete poslabel;
  delete timer;
  delete gpsserver;
}


void Simgui::update()
{
  hdg = (double)(heading->value());
  spd = (double)(speed->value());
  rc  = (double)(roc->value());
  //cout << hdg << ' ' << spd << ' ' << rc << '\n';
  position->update(dt,hdg,spd,rc);
  poslabel->setText(position->getPos());

  stemp1 = position->getNetworkString();
  stemp1.prepend("10,");
  stemp2.sprintf(",%8.2lf,%6.1lf,%5.0lf",hdg,spd,rc);
  stemp1.append(stemp2);
  gpsserver->broadcast_this(stemp1);
}

void Simgui::intervalChanged(int index)
{
  switch(index)
  {
    case 0:
    {
      dt = 1.0;
      break;
    }
    case 1:
    {
      dt = 0.5;
      break;
    }
    case 2:
    {
      dt = 0.1;
      break;
    }
  }
  timer->start((int)(dt*1000.0));

}


void Simgui::about()
{
  QMessageBox::about(this,"About GPSSIMULATOR",
                     "GPSSIMULATOR V1.00\n"
		     "GPS Network Server Simulator\n"
		     "Author: John G. Sonntag\n"
		     "Released: 5 February 2004\n");
}
