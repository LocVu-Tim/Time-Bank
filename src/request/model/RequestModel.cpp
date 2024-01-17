#include "RequestModel.h"
#include "../request.h"
using namespace std;

// Constructor
RequestModel::RequestModel(vector<userRequest *> requests)
{
    this->requestList = requests;
}

RequestModel::~RequestModel()
{
    for (Request *request : requestList)
    {
        delete request;
    }
}

void RequestModel::createRequest(map<string, string> userData)
{
    // create a new request object
    userRequest *request = new userRequest();
    // store the data to the request object
    // request->user = new User(userData["user"]);
    request->id = time(0);
    request->timeFrom = userData["timeFrom"];
    request->timeTo = userData["timeTo"];
    request->city = userData["city"];
    // split the skill string by comma
    int numberOfSkills = count(userData["skill"].begin(), userData["skill"].end(), ',') + 1;
    for (int i = 0; i < numberOfSkills; i++)
    {
        // push back the skill to the vector
        request->skill.push_back(userData["skill"].substr(0, userData["skill"].find(",")));
        // remove the skill from the string
        userData["skill"].erase(0, userData["skill"].find(",") + 1);
    }
    request->pointsPerHour = stod(userData["pointsPerHour"]);
    request->availability = true;
    // exception if the number is -1
    if (userData["requestOperation"] == "list")
    {
        request->minimumRatingForHost = stod(userData["minimumRatingForHost"]);
        request->minimumRatingForSupporter = 0;
        request->hostName = "";
    }
    else if (userData["requestOperation"] == "requestForSupporter")
    {
        request->minimumRatingForHost = 0;
        request->minimumRatingForSupporter = stod(userData["minimumRatingForSupporter"]);
        // TODO: hostName is the current user qq
        // request->hostName = userData["hostName"];
    }
    // push the request object to the requestList
    requestList.push_back(request);
    // write to file
    fileUtility fileUtility;
    fileUtility.writeToFile(request);
}

vector<userRequest *> RequestModel::getRequests()
{
    return requestList;
}

void RequestModel::load()
{
    fileUtility fileUtility;
    fileUtility.loadFromFile(requestList);
}