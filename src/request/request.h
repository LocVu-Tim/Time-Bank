#ifndef REQUEST_H
#define REQUEST_H

// Include any necessary headers here
#include <iostream>
#include <vector>
#include <ctime>

// Declare your classes, functions, and variables here
class Request
{
private:
    int id;
    bool availability;
    int pointsPerHour;
    std::vector<std::string> skill;
    int skillRatingScore;
    int supporterRatingScore;
    int hostRatingScore;
    std::string timePeriod;
    std::string city;
    // Not implemented yet
    // std::vector<Request*> allRequests;
    bool isAccepted;
    std::vector<std::string> comments;

public:
    Request(int id, bool availability, int pointsPerHour, vector<string> skill, int skillRatingScore, int supporterRatingScore, int hostRatingScore, string timePeriod, string city, bool isAccepted, vector<string> comments){};

    // Friend classes
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;
};

#endif // REQUEST_H
