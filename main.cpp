//
//  Main program for GPSSIMULATOR
//

#include <qapplication.h>
#include "simgui.h"
//#include "setupgui.h"


int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );

  // Transfer control to the simulator GUI
  Simgui gui;
  app.setMainWidget( &gui );
  gui.show();
  return app.exec();

}

