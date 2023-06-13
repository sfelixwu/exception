
#ifndef _THING_H_
#define _THING_H_

// Thing.h

#include "ecs36b_Common.h"
#include "Core.h"
#include "SP_Person.h"
#include "GPS.h"
#include "JvTime.h"

class Thing : public virtual Core
{
 private:
 protected:
 public:
  
  std::string model;
  std::string sequence_num;
  std::string description;
  SP_Person   owner;
  JvTime      purchased;
  JvTime      sold;

  GPS_DD      location;
  
  Thing(void);
  Thing(SP_Person);
  virtual void setClassName(void) { this->class_name = "Thing"; }
  virtual Json::Value dump2JSON(void);
  virtual bool JSON2Object(Json::Value);
};

#endif /* _THING_H_ */
