

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
  std::string my_team_name = "fire_ball"; // put your registered team name

  // okay, going for the server
  HttpClient httpclient("http://127.0.0.1:8384"); // replace here with the ngrok link
  mobility_Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  // below was the code I presented during OH
#ifdef _OH_MODIFICATION_
  
  myv["class_name"] = "ecs36b";
  myv["concern"] = "hw4";
  myv["numberofst"] = 9;
  Record r; // record object
  myv = r.dump2JSON(); // dump the content of the obejct into JSON format
  
  std::cout << myv.toStyledString() << std::endl;  
  char buff[128];
  snprintf(buff, strlen("./office_hour.json") + 1, "./office_hour.json");
  int rc = myJSON2File(buff, &myv); // save the JSON (content) into a file

  char c;
  scanf("%c", &c);
  
  Json::Value another_myv;
  rc = myFile2JSON(buff, &another_myv); // reload the content of the object from file (in JSON)
  std::cout << another_myv.toStyledString() << std::endl;  

  Record r_another;
  bool b = r_another.JSON2Object(another_myv); //

  Json:::Value jv2 = r_another.dump2JSON();

#endif /* _OH_MODIFICATION_ */

  try {
    myv = myClient.dump2JSON("dump2JSON", "Message", my_team_name);
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;  

  GPS_DD g1 { 0.0, 0.0 };
  try {
    myv = g1.dump2JSON();
  } catch (ecs36b_Exception& eE) {
    cerr << eE.what() << endl;
  }

  GPS_DD g2 { 91.0, 0.0 };
  try {
    myv = g2.dump2JSON();
  } catch (exception& eE) {
    cerr << eE.what() << endl;
  }
    
  return 0;
}
