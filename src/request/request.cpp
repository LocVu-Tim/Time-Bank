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

void Request::printInfo()
{
    cout << "ID: " << id << endl;
    // convert bool to string
    cout << "Availability: " << (availability ? "true" : "false") << endl;
    cout << "Points per hour: " << pointsPerHour << endl;
    cout << "Skill: " << skill << endl;
    cout << "Skill rating score: " << skillRatingScore << endl;
    cout << "Supporter rating score: " << supporterRatingScore << endl;
    cout << "Host rating score: " << hostRatingScore << endl;
    cout << "Time from: " << timeFrom << endl;
    cout << "Time to: " << timeTo << endl;
    cout << "City: " << city << endl;
    cout << "Minimum rating for host: " << minimumRatingForHost << endl;
    cout << "Minimum rating for supporter: " << minimumRatingForSupporter << endl;
    cout << "Is accepted: " << (isAccepted ? "true" : "false") << endl;
    cout << "Comments: " << endl;
    for (int i = 0; i < comments.size(); i++)
    {
        cout << comments[i] << endl;
    }
}

//int main()
//{
//    // Request r;
//    RequestView rv;
//    RequestModel rm;
//    RequestController rc(rm, rv);
//    int selectedChoice;
//
//    int operationNum = rc.OperationsList();
//    rc.selectAvailableFunction(operationNum, rv, rm);
//    return 0;
//}
