
#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

int
main(int _argc, char *_argv[])
{
  if (_argc != 2) return -1;
  long MSize = atoi(_argv[1]);
  
  try
    {
      std::cout << "MSize = " << MSize << std::endl;

      long int * m1 = (long int *) new long int[MSize * MSize];
      throw ecs36b_Exception {};
      long int * m2 = (long int *) new long int[MSize * MSize];

      std::cout << "memory allocated\n";
      fflush(stdout);
    }
  catch (ecs36b_Exception& e)
    {
      std::cout << "inside the ecs36b_Exception\n";
      std::cout << "standard exception: " << e.what() << endl;
      std::cout << typeid(e).name() << std::endl;
    }
  catch (exception& e)
    {
      std::cout << "inside the exception\n";
      std::cout << "standard exception: " << e.what() << endl;
      std::cout << typeid(e).name() << std::endl;
    }

  return 0;
}
