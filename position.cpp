//
// Position class implementation
//

#include "position.h"

#include <iostream>
using namespace std;


Position::Position(double d1, double d2, double d3, double d4)
{
  wks = d1;
  lat = d2;
  lon = d3;
  ht  = d4;
}


Position::~Position()
{
}


QString Position::getPos()
{
  stemp.sprintf("Time: %8.1lf sec\n",wks);
  stemp1.sprintf("Latitude: %10.6lf deg\n",lat);
  stemp.append(stemp1);
  stemp1.sprintf("Longitude: %10.6lf deg\n",lon);
  stemp.append(stemp1);
  stemp1.sprintf("Height: %8.2lf",ht);
  stemp.append(stemp1);
  return(stemp);
}


QString Position::getNetworkString()
{
  stemp.sprintf("%8.1lf,%10.6lf,%10.6lf,%8.2lf",wks,lat,lon,ht);
  return(stemp);
}


void Position::update(double dt, double hdg, double spd, double rc)
{

  // Update the time
  wks += dt;

  // Update the lat and lon
  distrad = dt*spd/3600.0/RAD2NM;
  hdgrad = hdg*PI/180.0;
  lon1rad = -lon*PI/180.0;
  lat1rad = lat*PI/180.0;
  lat2rad = asin(sin(lat1rad)*cos(distrad)+cos(lat1rad)
            *sin(distrad)*cos(hdgrad));
  lon2temp = atan2(sin(hdgrad)*sin(distrad)*cos(lat1rad),
                          cos(distrad)-sin(lat1rad)*sin(lat2rad));
  lon2rad = -(lon1rad-lon2temp);
  lat = lat2rad*180.0/PI;
  lon = lon2rad*180.0/PI;
  if (lon<0) lon+=360.0;
  else if (lon>360.0) lon -= 360.0;
  //if (lon>180.0) lon-=360.0;
  //else if (lon<-180.0) lon+=360.0;
  //cout << lon << endl;

  // Update the height
  ht += dt*rc/60.0;

}
