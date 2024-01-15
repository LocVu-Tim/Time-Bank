#ifndef REQUEST_H
#define REQUEST_H

// Include any necessary headers here
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
// Declare your classes, functions, and variables here
class Request
{
private:
    int id;
    bool availability;
    int pointsPerHour;
    string skill;
    int skillRatingScore;
    int supporterRatingScore;
    int hostRatingScore;
    string timeFrom;
    string timeTo;
    string city;
    double minimumRatingForHost;
    double minimumRatingForSupporter;
    // Not implemented yet
    // vector<Request*> allRequests;
    bool isAccepted;
    vector<string> comments;

public:
    Request(int id = 0, bool availability = false, int pointsPerHour = 0, vector<string> skill = {}, int skillRatingScore = 0, int supporterRatingScore = 0, int hostRatingScore = 0, string timeFrom = "", string timeTo = "", string city = "", bool isAccepted = false, vector<string> comments = {}, double minimumRatingForSupporter = 0){};
    Request();
    // Friend classes
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;

    void printInfo();
};

#endif // REQUEST_H
