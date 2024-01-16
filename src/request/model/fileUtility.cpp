#include "./fileUtility.h"
using namespace std;

void fileUtility::writeToFile(userRequest *request)
{
    ofstream fout;
    fout.open(FILENAME, ios::app);
    if (!fout.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    // TODO: implement user
    // fout << "user:" << request->user->getFullName() << endl;
    fout << "id:" << request->id << endl;
    fout << "timeFrom:" << request->timeFrom << endl;
    fout << "timeTo:" << request->timeTo << endl;
    fout << "city:" << request->city << endl;
    fout << "skill:" << endl;
    for (string skill : request->skill)
    {
        fout << skill << endl;
    }
    fout << "pointsPerHour:" << request->pointsPerHour << endl;
    if (request->availability)
    {
        fout << "availability:true" << endl;
        fout << "minimumRatingForHost:" << request->minimumRatingForHost << endl;
    }
    else
    {
        fout << "availability:false" << endl;
        fout << "minimumRatingForSupporter:" << request->minimumRatingForSupporter << endl;
    }
    fout << "isAccepted:" << (request->isAccepted == true ? "true" : "false") << endl;
    fout << "supporterName:" << request->supporterName << endl;
    fout << endl;
    fout.close();
};

void fileUtility::loadFromFile(vector<userRequest *> &requestList)
{
    // new request object
    userRequest *request = new userRequest();
    // open file
    // read line by line, separate by :
    // if there is multiple data, separate by newline
    // store the data to the request object based on the key name (before :)
    // if there is empty line, push the request object to the requestList

    ifstream fin;
    fin.open(FILENAME, ios::in);
    if (!fin.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(fin, line) && !fin.eof())
    {
        if (line.empty())
        {
            requestList.push_back(request);
            request = new userRequest();
        }
        else
        {
            string key = line.substr(0, line.find(":"));
            string value = line.substr(line.find(":") + 1);
            if (key == "user")
            {
                request->user = new User(value);
            }
            else if (key == "id")
            {
                request->id = stoi(value);
            }
            else if (key == "timeFrom")
            {
                request->timeFrom = value;
            }
            else if (key == "timeTo")
            {
                request->timeTo = value;
            }
            else if (key == "city")
            {
                request->city = value;
            }
            else if (key == "skill")
            {
                request->skill.push_back(value);
            }
            else if (key == "pointsPerHour")
            {
                request->pointsPerHour = stoi(value);
            }
            else if (key == "availability")
            {
                if (value == "true")
                {
                    request->availability = true;
                }
                else
                {
                    request->availability = false;
                }
            }
            else if (key == "minimumRatingForHost")
            {
                request->minimumRatingForHost = stod(value);
            }
            else if (key == "minimumRatingForSupporter")
            {
                request->minimumRatingForSupporter = stod(value);
            }
            else if (key == "isAccepted")
            {
                if (value == "true")
                {
                    request->isAccepted = true;
                }
                else
                {
                    request->isAccepted = false;
                }
            }
            else if (key == "supporterName")
            {
                request->supporterName = value;
            }
        }
    }
    fin.close();
}