// MyTroubles.h Exception class definition

#ifndef _TROUBLE_H_
#define _TROUBLE_H_

#include <string>

using std::string;

class Trouble
{
private:
  string message;
public:
 Trouble(string str = "This is a default ecs36b trouble") : message {str} {}
  string what() const { return message; }
};

#endif
