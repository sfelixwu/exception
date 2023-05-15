
#ifndef _COMMUTABLE_H_
#define _COMMUTABLE_H_

// Commutable.h

#include "ecs36b_Common.h"
#include "GPS.h"
#include "JvTime.h"

class Commutable
{
private:
public:
  std::string class_name; // this should never be "Commutable", kind of a hack
  Commutable();
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _COMMUTABLE_H_ */
