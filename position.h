//
// Position class definition
//

#ifndef POSITION_H
#define POSITION_H

#include <qstring.h>
#include <math.h>

#define PI (4.0*atan((double)(1.0)))
#define RAD2NM (180.0*60.0/PI)

class Position
{

  //Q_OBJECT

  public:
    Position(double,double, double, double);  // Constructor
    ~Position();  // Destructor

  public:
    QString getPos();
    QString getNetworkString();
    void update(double,double,double,double);

  private:
    double wks;
    double lat;
    double lon;
    double ht;
    QString stemp;
    QString stemp1;
    double distrad;
    double hdgrad;
    double lon1rad;
    double lat1rad;
    double lat2rad;
    double lon2rad;
    double lon2temp;

};

#endif // POSITION_H
