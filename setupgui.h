//
// Setupgui class definition
//

#ifndef SETUPGUI_H
#define SETUPGUI_H

#include <qdialog.h>
#include <qvalidator.h>
#include <qlineedit.h>
#include <qlabel.h>

class Setupgui : public QDialog
{

  Q_OBJECT

  public:
    Setupgui(double lat0, double lon0, double ht0, QWidget *parent,
             const char *name=0);  // Constructor
    ~Setupgui();  // Destructor

  private slots:
    void testInputs();

  private:
    QDoubleValidator *latval;
    QDoubleValidator *lonval;
    QLineEdit *startlat;
    QLineEdit *startlon;
    QLineEdit *startht;

};

#endif // SETUPGUI_H
