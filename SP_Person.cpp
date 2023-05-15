
#include "SP_Person.h"

SP_Person::SP_Person(std::string _n)
{
  this->class_name = "SP_Person";
  this->avatar_name = _n;
}

SP_Person::SP_Person()
{
  this->class_name = "SP_Person";
  this->avatar_name = "";
}

bool
SP_Person::operator==
(SP_Person& aSP_Person)
{
  return (this->avatar_name == aSP_Person.avatar_name);
}

Json::Value
SP_Person::dump2JSON
(void)
{
  Json::Value result { };

  result["class name"] = this->class_name;

  if (this->avatar_name != "")
    {
      result["avatar name"] = this->avatar_name;
    }

  return result;
}

bool
SP_Person::JSON2Object
(Json::Value arg_jv)
{
  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      if (arg_jv.isNull() != true)
	{
	  std::cout << arg_jv.toStyledString() << std::endl;
	}
      return false;
    }

  if (((arg_jv["class_name"]).isNull() == true) ||
      ((arg_jv["class_name"]).isString() == false) ||
      ((arg_jv["class_name"]).asString() != this->class_name))
    {
      return false;
    }
  
  if (((arg_jv["avatar name"]).isNull() == true) ||
      ((arg_jv["avatar name"]).isString() != true))
    {
      return false;
    }
  this->avatar_name = (arg_jv["avatar name"]).asString();

  return true;
}
