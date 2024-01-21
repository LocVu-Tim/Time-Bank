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
    // qq: implement user
    fout << "userId:" << request->userId << endl;
    fout << "id:" << request->id << endl;
    fout << "timeFrom:" << request->timeFrom << endl;
    fout << "timeTo:" << request->timeTo << endl;
    fout << "city:" << request->city << endl;
    fout << "skill:";
    for (string skill : request->skill)
    {
        // If at the last skill, don't add comma
        if (skill == request->skill.back())
        {
            fout << skill;
            break;
        }
        fout << skill << ",";
    }
    fout << endl;
    fout << "pointsPerHour:" << request->pointsPerHour << endl;
    if (request->availability)
    {
        fout << "availability:true" << endl;
    }
    else
    {
        fout << "availability:false" << endl;
    }
    fout << "minimumRatingForHost:" << request->minimumRatingForHost << endl;
    fout << "minimumRatingForSupporter:" << request->minimumRatingForSupporter << endl;
    fout << "hostId:" << request->hostId << endl;
    fout << "supporterId:" << request->supporterId << endl;
    fout << "pointsConsumed:" << request->pointsConsumed << endl;
    fout << "isCompleted:" << (request->isCompleted == true ? "true" : "false") << endl;
    fout << "isRated:" << (request->isRated == true ? "true" : "false") << endl;
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
            if (key == "userId")
            {
                request->userId = stoi(value);
            }
            if (key == "id")
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
                // request->skill.push_back(value);
                int numberOfSkills = count(value.begin(), value.end(), ',') + 1;
                string temp = value;
                for (int i = 0; i < numberOfSkills; i++)
                {
                    // push back the skill to the vector
                    request->skill.push_back(temp.substr(0, value.find(",")));
                    // remove the skill from the string
                    temp.erase(0, value.find(",") + 1);
                    // log the process
                    // cout << "Skill: " << request->skill[i] << endl;
                }
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
            else if (key == "hostId")
            {
                request->hostId = stoi(value);
            }
            else if (key == "pointsConsumed")
            {
                request->pointsConsumed = stoi(value);
            }
            else if (key == "isCompleted")
            {
                if (value == "true")
                {
                    request->isCompleted = true;
                }
                else
                {
                    request->isCompleted = false;
                }
            }
            else if (key == "isRated")
            {
                if (value == "true")
                {
                    request->isRated = true;
                }
                else
                {
                    request->isRated = false;
                }
            }
            else if (key == "supporterId")
            {
                request->supporterId = stoi(value);
            }
        }
    }
    fin.close();
    cout << "Number of requests: " << requestList.size() << endl;
}

void fileUtility::modifyFile(vector<userRequest *> &requestList)
{
    cout << "===============" << endl;
    cout << "modifying the file..." << endl;
    ofstream fout;
    // clear the file first
    fout.open(FILENAME, ios::trunc);
    fout.close();

    fout.open(FILENAME, ios::out);
    if (!fout.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    for (userRequest *request : requestList)
    {
        // rewrite all the data to the file
        writeToFile(request);
    }
    fout.close();
    cout << "Session saved sucessfully!" << endl;
}
