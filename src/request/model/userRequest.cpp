#include "./userRequest.h"

using namespace std;

void userRequest::printInfo(vector<User *> &userList)
{
    cout << "Request ID: " << this->id << endl;
    User *creator = findById(userList, stoi(userId));
    cout << "user created this request: " << creator->getUsername() << endl;
    cout << "Availability: " << (this->availability == true ? "true" : "false") << endl;
    cout << "Points per hour: " << this->pointsPerHour << endl;
    cout << "Time from: " << this->timeFrom << endl;
    cout << "Time to: " << this->timeTo << endl;
    cout << "City: " << this->city << endl;
    if (this->minimumRatingForSupporter != -1)
    {
        cout << "Minimum rating for supporter: " << this->minimumRatingForSupporter << endl;
    }
    if (this->minimumRatingForHost != -1)
    {
        cout << "Minimum rating for host: " << this->minimumRatingForHost << endl;
    }
    cout << "Skills: ";
    for (int i = 0; i < this->skill.size(); i++)
    {
        // at the end dont print commaww
        if (i == this->skill.size() - 1)
        {
            cout << this->skill[i];
            break;
        }
        cout << this->skill[i] << ",";
    }
    cout << endl;
    // if (hostId != -1)
    // {
    //     User *host = findById(userList, stoi(userId));
    //     cout << "Host name: " << host->getUsername() << endl;
    //     cout << "Supporter name: none" << endl;
    // }
    // else
    // {
    //     User *supporter = findById(userList, stoi(userId));
    //     cout << "Host name: none" << endl;
    //     cout << "Supporter name: " << supporter->getUsername() << endl;
    // }
    if (hostId != -1)
    {
        User *host = findById(userList, hostId);
        cout << "Host name: " << host->getUsername() << endl;
    }
    else
    {
        cout << "Host name: none" << endl;
    }
    if (supporterId != -1)
    {
        User *supporter = findById(userList, supporterId);
        cout << "Supporter name: " << supporter->getUsername() << endl;
    }
    else
    {
        cout << "Supporter name: none" << endl;
    }
}