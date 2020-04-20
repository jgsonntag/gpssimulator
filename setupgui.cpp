//
// Setupgui class implementation
//

//#include <qapplication.h>
#include <qlineedit.h>
#include <qhbox.h>
#include <qvbox.h>
#include <qlabel.h>
#include <qwidget.h>
#include <qstring.h>
#include <qpushbutton.h>
#include <qgrid.h>
#include <qvalidator.h>

#include "setupgui.h"
#include "simgui.h"

#include <iostream>
using namespace std;

extern double t0,lat0,lon0,ht0;

Setupgui::Setupgui(double lat0, double lon0, double ht0,
                   QWidget *parent, const char *name)
	: QDialog(parent,name)
{

  // Set up defaults
  QString lats,lons,hts;
  QString latss;
  lats.setNum(lat0);
  lons.setNum(lon0);
  hts.setNum(ht0);

  // Set the overall layout
  QVBox *all = new QVBox(this);
  all->setMinimumSize(400,200);
  QGrid *grid = new QGrid(2,all);

  // Starting lat
  latval = new QDoubleValidator(-90,90,99,this);
  startlat = new QLineEdit(grid);
  startlat->setText(lats);
  startlat->setValidator(latval);
  new QLabel(" Starting latitude in decimal deg",grid);

  // Starting lon
  lonval = new QDoubleValidator(-180,360,99,this);
  startlon = new QLineEdit(grid);
  startlon->setText(lons);
  startlon->setValidator(lonval);
  new QLabel(" Starting longitude in decimal deg",grid);

  // Starting height
  startht = new QLineEdit(grid);
  startht->setText(hts);
  new QLabel(" Starting height in ft",grid);

  // Continue button
  QPushButton *cont = new QPushButton("Continue",all);
  connect(cont,SIGNAL(clicked()),SLOT(testInputs()));

}


Setupgui::~Setupgui()
{
}


void Setupgui::testInputs()
{
  int pos;
  QString stemp = startlat->text();
  bool latisvalid = (latval->validate(stemp,pos)==QValidator::Acceptable);
  stemp = startlon->text();
  bool lonisvalid = (lonval->validate(stemp,pos)==QValidator::Acceptable);
  if (latisvalid&&lonisvalid)
  {
    t0   = 0.0;
    stemp = startlat->text();  lat0 = stemp.toDouble();
    stemp = startlon->text();  lon0 = stemp.toDouble();
    stemp = startht->text();   ht0  = stemp.toDouble();
    accept();
  }
  else
    reject();
}
