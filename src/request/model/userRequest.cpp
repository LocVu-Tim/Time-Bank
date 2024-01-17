#include "./userRequest.h"

using namespace std;

void userRequest::printInfo()
{
    cout << "Request ID: " << this->id << endl;
    cout << "userId created this request: " << this->userId << endl;
    cout << "Availability: " << (this->availability == true ? "true" : "false") << endl;
    cout << "Points per hour: " << this->pointsPerHour << endl;
    cout << "Time from: " << this->timeFrom << endl;
    cout << "Time to: " << this->timeTo << endl;
    cout << "City: " << this->city << endl;
    cout << "Minimum rating for host: " << this->minimumRatingForHost << endl;
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
    cout << "Host ID: " << (this->hostId == "0" ? "none" : this->hostId) << endl;
}