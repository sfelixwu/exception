//

#ifndef _ECS36B_EXCEPTION_
#define _ECS36B_EXCEPTION_

using namespace std;

class ecs36b_special // not to be caught
{
private:
  int x;
protected:
public:
};

// class ecs36b_Exception : public virtual ecs36b_special, std::exception
// class ecs36b_Exception : public ecs36b_special, public virtual std::exception
class ecs36b_Exception : public std::exception, ecs36b_special
{
private:
protected:
public:
  virtual ~ecs36b_Exception() throw () {};
  virtual const char* what() const throw () { return "ecs36b"; };
};

#endif /* _ECS36B_EXCEPTION_ */
