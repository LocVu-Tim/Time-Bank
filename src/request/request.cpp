#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>

// Main components
#include "request.h"
#include "view/RequestView.h"
#include "controller/RequestController.h"
#include "model/RequestModel.h"

using namespace std;

int main()
{
    // Request r;
    RequestController rc;
    RequestView rv;
    RequestModel rm;
    int selectedChoice;

    int operationNum = rc.OperationsList();
    rc.selectAvailableFunction(operationNum, rv, rm);
    return 0;
}

void Request::printInfo()
{
    cout << "ID: " << id << endl;
    cout << "Availability: " << availability << endl;
    cout << "Points per hour: " << pointsPerHour << endl;
    cout << "Skill: " << skill << endl;
    cout << "Skill rating score: " << skillRatingScore << endl;
    cout << "Supporter rating score: " << supporterRatingScore << endl;
    cout << "Host rating score: " << hostRatingScore << endl;
    cout << "Time from: " << timeFrom << endl;
    cout << "Time to: " << timeTo << endl;
    cout << "City: " << city << endl;
    cout << "Minimum rating for host: " << minimumRatingForHost << endl;
    cout << "Is accepted: " << isAccepted << endl;
    cout << "Comments: " << endl;
    for (int i = 0; i < comments.size(); i++)
    {
        cout << comments[i] << endl;
    }
}
