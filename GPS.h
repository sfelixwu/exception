
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include "ecs36b_Common.h"

class GPS_DD
{
 private:
  double latitude;
  double longitude;
 public:
  explicit GPS_DD();
  explicit GPS_DD(double, double);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  bool operator==(GPS_DD&);
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif /* _GPS_H_ */
