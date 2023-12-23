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
    int randomID = (rand() % 1000) + 1; // random number between 1 and 1000

    // since the data is string, some of them need to be converted to int
    int pointConsumedPerHour = stoi(userData[3]);

    // store the data
    request->id = randomID;
    request->timeFrom = userData[0];
    request->timeTo = userData[1];
    request->skill = userData[2];
    request->pointsPerHour = pointConsumedPerHour;
    // check the last element of the vector explicitly
    if (userData[userData.size() - 1] == "list")
    {
        request->availability = true;
        double minimumRatingForHost = stod(userData[4]);
        request->minimumRatingForHost = minimumRatingForHost;
    }
    else if (userData[userData.size() - 1] == "lookForSupport")
    {
        request->availability = false;
        double minimumRatingForSupporter = stod(userData[4]);
        request->minimumRatingForSupporter = minimumRatingForSupporter;
    }

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