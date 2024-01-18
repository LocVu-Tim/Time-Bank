#ifndef REQUEST_MODEL_H
#define REQUEST_MODEL_H

#include "../request.h"
#include "./userRequest.h"
#include "./fileUtility.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class RequestModel
{
    // serves for later file storage
private:
    vector<userRequest *> requestList;

public:
    RequestModel(vector<userRequest *> requests = {});
    ~RequestModel();

    void createRequest(map<string, string> userData, User &user);
    // void writeToFile(Request *request);
    void load();
    vector<userRequest *> getRequests();

    friend class RequestController;
    friend class RequestView;
    friend class fileUtility;
    friend class userRequest;
    friend class Request;
};

#endif // REQUEST_MODEL_H
