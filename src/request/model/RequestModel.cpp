#include <iostream>
#include <vector>

#include "RequestModel.h"
#include "../request.h"
using namespace std;

// Constructor
RequestModel::RequestModel(vector<Request *> requests)
{
    this->requests = requests;
}

RequestModel::~RequestModel()
{
    for (Request *request : requests)
    {
        delete request;
    }
}

void RequestModel::createRequest(vector<string> userData)
{
    // This is just emulating the database (temporary solution)
    Request *request = new Request();
    // ID is generated automatically
    int randomID = 93; // random number between 1 and 1000

    // since the data is string, some of them need to be converted to int
    int pointConsumedPerHour = stoi(userData[3]);
    double minimumRatingForHost = stod(userData[4]);

    // store the data
    request->id = randomID;
    request->timeFrom = userData[0];
    request->timeTo = userData[1];
    request->skill = userData[2];
    request->pointsPerHour = pointConsumedPerHour;
    request->minimumRatingForHost = minimumRatingForHost;

    // add the request to the vector
    requests.push_back(request);
}

vector<Request *> RequestModel::getRequests()
{
    // test if the request is added to the vector
    cout << "[DEBUG] Request info: " << endl;
    requests[0]->printInfo();
    cout << "=============================" << endl;
    return requests;
}