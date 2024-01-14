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

    // add the request to the vector and write to file
    requests.push_back(request);
    writeToFile(request);
}

void RequestModel::writeToFile(Request *request)
{
    // Write to file
    ofstream fout;
    fout.open(FILENAME, ios::app);
    fout << "==============================" << endl;
    fout << "Request ID: " << request->id << endl;
    fout << "Time from: " << request->timeFrom << endl;
    fout << "Time to: " << request->timeTo << endl;
    fout << "Skill: " << request->skill << endl;
    fout << "Points per hour: " << request->pointsPerHour << endl;
    if (request->availability)
    {
        fout << "Availability: true" << endl;
        fout << "Minimum rating for host: " << request->minimumRatingForHost << endl;
    }
    else
    {
        fout << "Availability: false" << endl;
        fout << "Minimum rating for supporter: " << request->minimumRatingForSupporter << endl;
    }
    fout << "==============================" << endl;
    fout.close();
}

void RequestModel::load()
{
    // Load data from file
    ifstream fin;
    fin.open(FILENAME, ios::in);
    string line;
    while (getline(fin, line))
    {
        // cout << line << endl;
        if (line != "==============================")
        {
            continue;
        }
        else
        {
            // read the data
            Request *request = new Request();
            getline(fin, line);
            request->id = stoi(line.substr(12));
            getline(fin, line);
            request->timeFrom = line.substr(11);
            getline(fin, line);
            request->timeTo = line.substr(9);
            getline(fin, line);
            request->skill = line.substr(7);
            getline(fin, line);
            request->pointsPerHour = stoi(line.substr(17));
            getline(fin, line);
            if (line.substr(14) == "true")
            {
                request->availability = true;
                getline(fin, line);
                request->minimumRatingForHost = stod(line.substr(25));
            }
            else
            {
                request->availability = false;
                getline(fin, line);
                request->minimumRatingForSupporter = stod(line.substr(31));
            }
            getline(fin, line);
            requests.push_back(request);
        
        }
    }
    fin.close();
}

vector<Request *> RequestModel::getRequests()
{
    // test if the request is added to the vector
    cout << "[DEBUG] Request info: " << endl;
    requests[0]->printInfo();
    cout << "==============================" << endl;
    return requests;
}