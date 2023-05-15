
#ifndef _TEAM_H_
#define _TEAM_H_

// Team.h

#include "ecs36b_Common.h"
#include "Commutable.h"
#include "SP_Person.h"
#include "GPS.h"
#include "JvTime.h"

class Team : public Commutable
{
 private:
 protected:
 public:

  std::string name;
  std::vector<SP_Person>  members;
  
  Team(void);
  bool setName(const std::string&);
  bool addAMember(SP_Person&);
  virtual Json::Value dump2JSON(); // print the content of the object
  virtual bool JSON2Object(Json::Value);
};

#endif /* _TEAM_H_ */
