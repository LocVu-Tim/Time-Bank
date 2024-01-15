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

void RequestModel::createRequest(map<string, string> userData)
{
    // This is just emulating the database (temporary solution)
    Request *request = new Request();
    // ID is generated automatically based on the current time
    int randomID = time(0);

    // since the data is string, some of them need to be converted to int
    int pointConsumedPerHour = stoi(userData["pointsPerHour"]);

    // store the data
    request->id = randomID;
    request->timeFrom = userData["timeFrom"];
    request->timeTo = userData["timeTo"];
    request->city = userData["city"];
    // request->skill = userData["skill"];
    // TODO: qq
    cout << "skill: " << userData["skill"] << endl;
    // push back the skill to the vector
    // count how many skills are there splitted by comma
    int numberOfSkills = count(userData["skill"].begin(), userData["skill"].end(), ',') + 1;
    cout << numberOfSkills << endl;
    for (int i = 0; i < numberOfSkills; i++)
    {
        // push back the skill to the vector
        request->skill.push_back(userData["skill"].substr(0, userData["skill"].find(",")));
        // remove the skill from the string
        userData["skill"].erase(0, userData["skill"].find(",") + 1);
        cout << "after erase: " << userData["skill"] << endl;
    }

    request->pointsPerHour = pointConsumedPerHour;
    // check the last element of the vector explicitly
    if (userData["requestOperation"] == "list")
    {
        request->availability = true;
        double minimumRatingForHost = stod(userData["minimumRatingForHost"]);
        cout << "minimumRatingForHost: " << minimumRatingForHost << endl;
        request->minimumRatingForHost = minimumRatingForHost;
    }
    else if (userData["requestOperation"] == "lookForSupport")
    {
        request->availability = false;
        double minimumRatingForSupporter = stod(userData["minimumRatingForSupporter"]);
        cout << "minimumRatingForSupporter: " << minimumRatingForSupporter << endl;
        request->minimumRatingForSupporter = minimumRatingForSupporter;
    }

    // add the request to the vector and write to file
    requests.push_back(request);
    writeToFile(request);
    // qq test
    load();
}

void RequestModel::writeToFile(Request *request)
{
    // Write to file
    ofstream fout;
    fout.open(FILENAME, ios::app);
    fout << "id: " << request->id << endl;
    fout << "timeFrom: " << request->timeFrom << endl;
    fout << "timeTo: " << request->timeTo << endl;
    fout << "skill:" << endl;
    for (string skill : request->skill)
    {
        // fill in the spaces before the skill
        fout << skill << endl;
    }
    fout << "End of skill" << endl;
    fout << "pointsPerHour: " << request->pointsPerHour << endl;
    if (request->availability)
    {
        fout << "availability: true" << endl;
        fout << "minimumRatingForHost: " << request->minimumRatingForHost << endl;
    }
    else
    {
        fout << "availability: false" << endl;
        fout << "minimumRatingForSupporter: " << request->minimumRatingForSupporter << endl;
    }
    fout << endl;
    fout.close();
}

void RequestModel::load()
{
    // Load data from file
    ifstream fin;
    // 1. read the file to count how much data are there
    // it's separated by empty line
    fin.open(FILENAME, ios::in);
    if (!fin.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    string line;
    int numberOfData = 0;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            numberOfData++;
        }
    }
    cout << "[debug] numberOfData: " << numberOfData << endl;
    fin.close();

    // 2. read the file again to store the data
    fin.open(FILENAME, ios::app);
    if (!fin.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    
    
    cout << "stopped" << endl;
    fin.close();
}

vector<Request *> RequestModel::getRequests()
{
    return requests;
}