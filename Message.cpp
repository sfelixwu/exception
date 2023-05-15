
#include "Message.h"

// Message::Message
// (Commutable& _f, Commutable& _t)
// {
//   from = _f;
//  to = _t;
// }

Json::Value
Message::dump2JSON
(void)
{
  Json::Value result;
  result["from"] = from.dump2JSON();
  result["to"] = to.dump2JSON();
  result["content"] = content;
  return result;
}

bool 
Message::JSON2Object
(Json::Value input_json)
{
  bool br;
  
  if ((input_json.isNull() == true) ||
      (input_json.isObject() != true))
    {
      return false;
    }

  if (((input_json["from"]).isNull() == true) ||
      (((input_json["from"])["class name"]).isNull() == true) ||
      ((input_json["to"]).isNull() == true) ||
      (((input_json["to"])["class name"]).isNull() == true) ||
      ((input_json["content"]).isNull() == true) ||
      ((input_json["from"]).isObject() == false) ||
      ((input_json["to"]).isObject() == false) ||
      ((input_json["content"]).isObject() == false))
    {
      return false;
    }

  if ((((input_json["from"])["class name"]).asString() == "Team") &&
      ((this->from).class_name == "Team"))
    {
      // this was a Team Object
      Team *lv_t_ptr = new Team();
      br = lv_t_ptr->JSON2Object(input_json["from"]);
      if (br == false) return false;
      ((Team&) this->from) = *lv_t_ptr;

      // create an empty TEAM object
      // call JSON2Object on the TEAM object (pass the "from" portion of JSON into the TEAM)
      // copy the TEAM object (its content) into this->from

      // "who" :
      // {
      //  "person1": {..},
      //  "person2": {...}
      // } 

      // Person p1, p2;
      // (this->who1).JSON2Object(arg_jv[who]["person1"]);
      
      //  who1 = p1;
      //  p2.JSON2Object(arg_jv[who]["person2"]);
      //  who2 = p2;
      //  (this->thing1).type = (arg_jv["thing1"]["type"]).asString();
    }
  else
    {
      if ((((input_json["from"])["class name"]).asString() == "SP_Person") &&
	  ((this->from).class_name == "SP_Person"))
	{
	  // this was a Person Object
	  SP_Person *lv_p_ptr = new SP_Person();
	  br = lv_p_ptr->JSON2Object(input_json["from"]);
	  if (br == false) return false;
	  ((SP_Person&) this->from) = *lv_p_ptr;
	}
      else
	{
	  return false;
	}
    }

  if ((((input_json["to"])["class name"]).asString() == "Team") &&
      ((this->to).class_name == "Team"))
    {
      // this was a Team Object
      Team *lv_t_ptr = new Team();
      br = lv_t_ptr->JSON2Object(input_json["to"]);

      if (br == false) return false;
      ((Team&) this->to) = *lv_t_ptr;
    }
  else
    {
      if ((((input_json["to"])["class name"]).asString() == "SP_Person") &&
	  ((this->to).class_name == "SP_Person"))
	{
	  // this was a Person Object
	  SP_Person *lv_p_ptr = new SP_Person();
	  br = lv_p_ptr->JSON2Object(input_json["to"]);
	  if (br == false) return false;
	  ((SP_Person&) this->to) = *lv_p_ptr;
	}
      else
	{
	  return false;
	}
    }

  this->content = input_json["content"];

  return true; // if successful
}
