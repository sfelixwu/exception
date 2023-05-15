// Ex15_03.cpp
// Throw an exception object
#include <iostream>
#include "Trouble.h"

int main()
{
  for (int i {}; i < 2; ++i)
    {
      try
	{
	  if (i == 0)
	    throw Trouble {}; // i == 0
	  else                // i == 1
	    throw Trouble {"Nobody on Piaaza knows the trouble I've experienced..."};
	}
      catch(const Trouble& t)
	{
	  std::cout << "Exception: " << t.what() << std::endl;
	}
    }
}
