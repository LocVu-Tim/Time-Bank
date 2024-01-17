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
    int supporterRatingScore;
    int hostRatingScore;

public:
    Request(User *user = nullptr, int id = 0, int supporterRatingScore = 0, int hostRatingScore = 0)
    {
        this->user = user;
        this->supporterRatingScore = supporterRatingScore;
        this->hostRatingScore = hostRatingScore;
    };

    // Friend classes
    friend class RequestModel;
    friend class RequestController;
    friend class RequestView;
    friend class fileUtility;
    friend class userRequest;

    void printInfo();
};

#endif // REQUEST_H
