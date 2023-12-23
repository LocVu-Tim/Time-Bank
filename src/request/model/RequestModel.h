#ifndef REQUEST_MODEL_H
#define REQUEST_MODEL_H

#include "../request.h"

#include <vector>
using namespace std;

class RequestModel
{
    // serves for later file storage
private:
    vector<Request *> requests;

public:
    RequestModel(vector<Request *> requests = {});
    ~RequestModel();

    void createRequest(vector<string> userData);
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
