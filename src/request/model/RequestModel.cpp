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

void RequestModel::createRequest(map<string, string> userData, int userId)
{
    try
    { // convert int to string
        string id = to_string(userId);
        // create a new request object
        userRequest *request = new userRequest();
        // store the data to the request object
        request->userId = id;
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
            request->hostId = "0";
        }
        else if (userData["requestOperation"] == "requestForSupporter")
        {
            request->minimumRatingForSupporter = stod(userData["minimumRatingForSupporter"]);
            request->hostId = id;
        }
        // push the request object to the requestList
        requestList.push_back(request);
        // write to file
        fileUtility fileUtility;
        fileUtility.writeToFile(request);
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
        // show where the exception is
        cout << "Exception occured at: " << typeid(e).name() << endl;
    }
    // catch segmentation fault
    catch (...)
    {
        cout << "Segmentation fault" << endl;
        // show where the exception is
        cout << "Exception occured at: " << typeid(*this).name() << endl;
    }
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