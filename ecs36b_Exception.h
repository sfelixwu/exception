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

// case (1) -- all these are okay
// class ecs36b_Exception : public std::exception, ecs36b_special
// class ecs36b_Exception : public std::exception, public ecs36b_special
// class ecs36b_Exception : public ecs36b_special, public std::exception
// class ecs36b_Exception : public ecs36b_special, public virtual std::exception

// case (2) -- this won't catch
// class ecs36b_Exception : std::exception, ecs36b_special
// class ecs36b_Exception : ecs36b_special, std::exception
// class ecs36b_Exception : public ecs36b_special, std::exception
// class ecs36b_Exception : public ecs36b_special, virtual std::exception

class ecs36b_Exception : public std::exception, public ecs36b_special
{
private:
protected:
public:
  virtual ~ecs36b_Exception() throw () {};
  virtual const char* what() const throw () { return "ecs36b"; };
};

#endif /* _ECS36B_EXCEPTION_ */
