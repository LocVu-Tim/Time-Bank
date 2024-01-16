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

    void createRequest(map<string, string> userData);
    // void writeToFile(Request *request);
    void load();
    vector<userRequest *> getRequests();
};

#endif // REQUEST_MODEL_H
