#include "RESTApi.h"
//add definition of your processing function here

void RESTApi::get(const HttpRequestPtr &req,
		  std::function<void (const HttpResponsePtr &)> &&callback,
		  std::string &&action)
{
    LOG_DEBUG << "Action (Get):" << action;
    Json::Value ret;
    ret["result"] = "ok";							//Message 1
    ret["message"] = "Hello World";		//Message 2

		std::string command{"echo HELO"};	//The command you would like to run

		if ( "Autoware.command.code1" == action ){
				command = "echo Command A";
		} else if ( "Autoware.command.code2" == action ){
				command = "echo Command B";
		} else {
				command = "echo Command C";
		}

    ret["exitcode"] = std::system(command.c_str());	//Store the exit code

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
