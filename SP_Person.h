
#ifndef _SP_PERSON_H_
#define _SP_PERSON_H_

// SP_Person.h

#include "ecs36b_Common.h"
#include "Commutable.h"
#include "GPS.h"
#include "JvTime.h"

class SP_Person : public Commutable
{
private:
public:

  std::string avatar_name;
  
  SP_Person(std::string);
  SP_Person();

  bool operator==(SP_Person& aPerson);
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* SP_PERSON_H_ */
