#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include "request.h"

using namespace std;

class Request
{
private:
    int id;
    bool availability;
    int pointsPerHour;
    vector<string> skill;
    int skillRatingScore;
    int supporterRatingScore;
    int hostRatingScore;
    string timePeriod;
    string city;
    // Not implemented yet
    // vector<Request*> allRequests;
    bool isAccepted;
    vector<string> comments;

public:
    // Constructors
    Request(int id = 0, bool availability = false, int pointsPerHour = 0, vector<string> skill = {}, int skillRatingScore = 0, int supporterRatingScore = 0, int hostRatingScore = 0, string timePeriod = "", string city = "", bool isAccepted = false, vector<string> comments = {}){};

    // Friend classes
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;
};