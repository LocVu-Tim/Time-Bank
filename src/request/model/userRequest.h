#ifndef USER_REQUEST_H
#define USER_REQUEST_H
#include "../request.h"
// #include "./fileUtility.h"

using namespace std;

class userRequest : public Request
{
private:
    // Information about the request
    bool availability;
    int pointsPerHour;
    string timeFrom;
    string timeTo;
    string city;
    vector<string> skill;
    double minimumRatingForHost;
    double minimumRatingForSupporter;
    bool isAccepted;
    string supporterName;

public:
    userRequest(User *user = nullptr, int id = 0, bool availability = false, int pointsPerHour = 0, string timeFrom = "", string timeTo = "", string city = "", double minimumRatingForHost = 0, double minimumRatingForSupporter = 0, bool isAccepted = false, vector<string> skills = {}) : Request(user, id)
    {
        this->skill = skills;
        this->availability = availability;
        this->pointsPerHour = pointsPerHour;
        this->timeFrom = timeFrom;
        this->timeTo = timeTo;
        this->city = city;
        this->minimumRatingForHost = minimumRatingForHost;
        this->minimumRatingForSupporter = minimumRatingForSupporter;
        this->isAccepted = isAccepted;
    };
    friend class fileUtility;
    void printInfo();

    friend class RequestModel;
};

#endif // USER_REQUEST_H
