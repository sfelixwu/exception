//

#ifndef _ECS36B_EXCEPTION_
#define _ECS36B_EXCEPTION_

#include "ecs36b_Common.h"

#define EXC_ERR_OUT_OF_RANGE        -1
#define EXC_ERR_INPUT_NULL          -2
#define EXC_ERR_INPUT_NOT_OBJECT    -3
#define EXC_ERR_MISSING_ATTRIBUTE   -4
#define EXC_ERR_DATA_TYPE           -5

using namespace std;

class ecs36b_Exception : public std::exception
{
private:
protected:
public:
  Json::Value data;
  virtual ~ecs36b_Exception() throw () {};
  virtual const char* what() const throw () { return "ecs36b exception"; };
};

#endif /* _ECS36B_EXCEPTION_ */
