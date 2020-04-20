//
// Simgui class definition
//

#ifndef SIMGUI_H
#define SIMGUI_H

#include <qmenubar.h>
#include <qvbox.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qtimer.h>

#include "position.h"
#include "genericserver.h"

class Simgui : public QVBox
{

  Q_OBJECT

  public:
    Simgui();  // Constructor
    ~Simgui();  // Destructor

  private:
    //double t0;
    //double lat0;
    //double lon0;
    //double ht0;
    double dt;
    QMenuBar *mainmenu;
    QSpinBox *heading;
    QSpinBox *speed;
    QSpinBox *roc;
    QComboBox *interval;
    QLabel *poslabel;
    Position *position;
    QTimer *timer;
    GenericServer *gpsserver;
    QString stemp1,stemp2;

  private slots:
    void about();
    void update();
    void intervalChanged(int);

  private:
    double hdg;
    double spd;
    double rc;

};

#endif // SIMGUI_H
