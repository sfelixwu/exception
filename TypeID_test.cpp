#include <iostream>
#include <string>
#include <typeinfo>
 
class np_Base {}; // non-polymorphic
class np_Derived : public np_Base {};
 
class pl_Base { virtual void foo() {} }; // polymorphic
class pl_Derived : public pl_Base {};
 
int main(void)
{

  // Non-polymorphic lvalue is a static type
  np_Derived np_d;
  np_Base& np_b = np_d;
  std::cout << "reference to non-polymorphic base: " << typeid(np_b).name() << '\n';
 
  pl_Derived pl_d;
  pl_Base& pl_b = pl_d;
  std::cout << "reference to polymorphic base: " << typeid(pl_b).name() << '\n';
 
  try
    {
      // dereferencing a null pointer: okay for a non-polymorphic expression
      np_Derived * np_bad_ptr = NULL;
      std::cout << "bad_ptr points to... ";
      std::cout << typeid(*np_bad_ptr).name() << '\n';
      // dereferencing a null pointer: not okay for a polymorphic lvalue
      pl_Derived * pl_bad_ptr = NULL;
      std::cout << "bad_ptr points to... ";
      std::cout << typeid(*pl_bad_ptr).name() << '\n';
    }
  // catch (const std::bad_typeid& e)
    catch (const std::exception& e)
    {
         std::cout << " caught " << e.what() << '\n';
    }
}
