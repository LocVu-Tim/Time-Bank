#include <iostream>
#include <string>
#include <cstring>
#include <vector>

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
    // Request* allRequests = new Request[100];
    bool isAccepted;
    vector<string> comments;
};