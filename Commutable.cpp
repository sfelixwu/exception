
#include "Commutable.h"

Commutable::Commutable()
{
}

Json::Value
Commutable::dump2JSON
(void)
{
  Json::Value result;
  result["base"] = "Commutable";
  return result;
}

bool
Commutable::JSON2Object
(Json::Value arg_jv)
{
  return true;
}

