

// ecs36b mobility_client program

#include <iostream>
#include "ecs36b_Exception.h"

// JSON RPC part
#include "mobility_client.h"
#include "Message.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

int
main()
{
  SP_Person instructor { "whoever" };
  
  SP_Person student01  { "John" };    // modify to whatever AVATAR name, no real name, please
  SP_Person student02  { "Helen" };   // modify to whatever AVATAR name, no real name, please

  std::string my_team_name = "fire_ball"; // put your registered team name
  Team my_team;
  my_team.setName(my_team_name);      
  my_team.addAMember(student01);
  my_team.addAMember(student02);
  
  Message m {my_team, instructor};
  Json::Value jv_content;
  jv_content["header"] = "ecs36b participation on 05/01/2023";
  jv_content["body"] = "just a body"; // you can put whatever you like
  m.content = jv_content;

  Json::Value jv_message = m.dump2JSON();
  std::cout << jv_message.toStyledString() << std::endl;

  // okay, going for the server
  // HttpClient httpclient("https://40b8-2601-200-c000-39f0-616c-7ba7-6e23-e672.ngrok-free.app");
  // replace here with the ngrok link
  HttpClient httpclient("http://127.0.0.1:8384"); // replace here with the ngrok link
  mobility_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try {
    myv = myClient.send("send", "Message", jv_message, my_team_name);
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  return 0;
}
