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
    string hostId;

public:
    userRequest(string userId = "", int id = 0, bool availability = false, int pointsPerHour = 0, string timeFrom = "", string timeTo = "", string city = "", double minimumRatingForHost = 0, vector<string> skills = {}, double minimumRatingForSupporter = 0) : Request(userId, id)
    {
        this->skill = skills;
        this->availability = availability;
        this->pointsPerHour = pointsPerHour;
        this->timeFrom = timeFrom;
        this->timeTo = timeTo;
        this->city = city;
        this->minimumRatingForHost = minimumRatingForHost;
        this->minimumRatingForSupporter = minimumRatingForSupporter;
    };
    friend class fileUtility;
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;

    void printInfo();
};

#endif // USER_REQUEST_H
