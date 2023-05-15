#include "Team.h"

Team::Team
(void)
{
  this->class_name = "Team";
}

bool
Team::setName
(const std::string& _n)
{
  this->name = _n;
  return true;
}

bool
Team::addAMember
(SP_Person& _p)
{
  this->members.push_back(_p);
  return true;
}

Json::Value
Team::dump2JSON
(void)
{
  Json::Value result { };

  result["class name"] = this->class_name;
  result["name"] = this->name;

  Json::Value an_jv_array;
  int i = 0;
  for (i = 0; i < (this->members).size(); i++)
    {
      an_jv_array[i] = ((this->members)[i]).dump2JSON();
    }
  result["members"] = an_jv_array;
  
  return result;
}

bool
Team::JSON2Object
(Json::Value input_json)
{
  bool br;
  
  if ((input_json.isNull() == true) ||
      (input_json.isObject() != true))
    {
      return false;
    }

  if (((input_json["class_name"]).isNull() == true) ||
      ((input_json["class_name"]).isString() == false) ||
      ((input_json["class_name"]).asString() != this->class_name))
    {
      return false;
    }
  

  
  if (((input_json["name"]).isNull() == true) ||
      ((input_json["members"]).isNull() == true) ||
      ((input_json["name"]).isString() == false) ||
      ((input_json["members"]).isArray() == false))
    {
      return false;
    }

  this->name = (input_json["name"]).asString();

  int i;
  for (i = 0; i < (input_json["members"]).size(); i++)
    {
      Json::Value l_jv = input_json["members"][i];
      SP_Person *sp_ptr = new SP_Person();
      bool bc = sp_ptr->JSON2Object(l_jv);
      if (bc == false) return bc;
      (this->members).push_back(*sp_ptr);
    }

  return true;
}

