#ifndef REQUEST_MODEL_H
#define REQUEST_MODEL_H

#include "../request.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#define FILENAME "request.dat"
using namespace std;

class RequestModel
{
    // serves for later file storage
private:
    vector<Request *> requests;

public:
    RequestModel(vector<Request *> requests = {});
    ~RequestModel();

    void createRequest(map<string, string> userData);
    void writeToFile(Request *request);
    void load();
    vector<Request *> getRequests();

    // Load data from file
    // void load();

    // CRUD functions
    // void createRequest();
    // void readRequest();
    // void updateRequest();
    // void deleteRequest();

private:
    // Add your member variables here
};

#endif // REQUEST_MODEL_H
