#include "RESTApi.h"
//add definition of your processing function here

void RESTApi::get(const HttpRequestPtr &req,
		  std::function<void (const HttpResponsePtr &)> &&callback,
		  std::string &&action)
{
    LOG_DEBUG << "Action (Get):" << action;
    Json::Value ret;
    ret["result"]="ok";
    ret["message"]="Hello World";
    std::string command{"echo HELO"};
    
    ret["exitcode"]=std::system(command.c_str());

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void RESTApi::post(const HttpRequestPtr &req,
                  std::function<void (const HttpResponsePtr &)> &&callback,
                  std::string &&action)
{
    LOG_DEBUG << "Action (POST):" << action;
    Json::Value ret;
    ret["result"]="ok";
    ret["message"]="Hello World";
    std::string command{"echo HELO"};
  
    int rs = std::system(command.c_str());
    ret["exitcode"]=rs;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);

}
