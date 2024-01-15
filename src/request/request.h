#ifndef REQUEST_H
#define REQUEST_H

// Include any necessary headers here
#include "../user/User.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Request
{
private:
    User *user;
    int id;
    bool availability;
    int pointsPerHour;
    vector<string> skill;
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
    Request(User *user = nullptr, int id = 0, bool availability = false, int pointsPerHour = 0, vector<string> skill = {}, int skillRatingScore = 0, int supporterRatingScore = 0, int hostRatingScore = 0, string timeFrom = "", string timeTo = "", string city = "", bool isAccepted = false, vector<string> comments = {}, double minimumRatingForSupporter = 0)
    {
        this->user = user;
        this->id = id;
        this->availability = availability;
        this->pointsPerHour = pointsPerHour;
        this->skill = skill;
        this->skillRatingScore = skillRatingScore;
        this->supporterRatingScore = supporterRatingScore;
        this->hostRatingScore = hostRatingScore;
        this->timeFrom = timeFrom;
        this->timeTo = timeTo;
        this->city = city;
        this->isAccepted = isAccepted;
        this->comments = comments;
        this->minimumRatingForSupporter = minimumRatingForSupporter;
    };

    // Friend classes
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;

    void printInfo();
};

#endif // REQUEST_H
