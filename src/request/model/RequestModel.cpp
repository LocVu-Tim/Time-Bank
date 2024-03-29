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

void RequestModel::createRequest(map<string, string> userData, int userid, vector<string> skills)
{
    // create a new request object
    userRequest *request = new userRequest();
    // convert int to string
    string id = to_string(userid);
    // store the data to the request object
    request->userId = id;
    request->id = time(0);
    request->timeFrom = userData["timeFrom"];
    request->timeTo = userData["timeTo"];
    request->city = userData["city"];
    // split the skill string by comma
    // int numberOfSkills = count(skills.begin(), skills.end(), ',') + 1;
    for (int i = 0; i < skills.size(); i++)
    {
        request->skill.push_back(skills[i]);
        // // push back the skill to the vector
        // request->skill.push_back(skills.substr(0, skills.find(",")));
        // // remove the skill from the string
        // skills.erase(0, skills.find(",") + 1);
    }
    request->pointsPerHour = stod(userData["pointsPerHour"]);
    request->availability = true;
    // exception if the number is -1
    if (userData["requestOperation"] == "list")
    {
        request->minimumRatingForHost = stod(userData["minimumRatingForHost"]);
        request->minimumRatingForSupporter = 0;
        request->hostId = "0";
    }
    else if (userData["requestOperation"] == "requestForSupporter")
    {
        request->minimumRatingForHost = 0;
        request->minimumRatingForSupporter = stod(userData["minimumRatingForSupporter"]);
        request->hostId = id;
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

int RequestModel::getPositionOfRequest(int id)
{
    cout << "The request ID: " << id << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        if (requestList[i]->id == id)
        {
            cout << "The request is found!" << endl;
            return i;
        }
    }
    return -1;
}

void RequestModel::load()
{
    fileUtility fileUtility;
    fileUtility.loadFromFile(requestList);
}