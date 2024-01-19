#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include "../request.h"
#include "../view/RequestView.h"
#include "../model/RequestModel.h"
#include "../controller/RequestController.h"

class RequestController
{
private:
    RequestModel *requestModel;
    RequestView *requestView;
    User *user;
    vector<User *> userList;

public:
    RequestController(RequestModel &requestModel, RequestView &requestView);

    ~RequestController();

    int OperationsList();

    void selectAvailableFunction();

    void createRequestObject(map<string, string> userData);

    void listOrUnlist();

    // 1. List and unlist your own requests
    void list();

    void unlist();

    void viewAllRequests();

    void GuestViewAllRequests(RequestModel &rm);

    void adminViewAllRequests(RequestModel &rm);
    void hostViewAvailableRequest();
    userRequest *findARequest(int position, vector<userRequest *> requestList);

    void requestForSupporter();

    // for view available request
    vector<userRequest *>
    filterRequestAvailable(vector<userRequest *> &requestList, int userId, vector<int> blocked);

    // For looking for supporter
    vector<userRequest *> filterBasedOnHostRating(vector<userRequest *> &requestList, double hostRating);
    vector<userRequest *> filterBasedOnSupporterRating(vector<userRequest *> &requestList, double supporterRating);
    vector<userRequest *> filterBasedOnSkills(vector<userRequest *> &requestList, string skill);
    vector<userRequest *> filterRatedRequest(vector<userRequest *> &requestList);

    void incomingProcess();
    void outgoingProcess();
    void calculatePointsConsumedForHost(userRequest *request);
    void calculatePointsConsumedForSupporter(userRequest *request);

    vector<userRequest *> filterUserList(vector<userRequest *> &requestList);

    void setUser(User *user);
    vector<userRequest *> filterIncomingRequest();
    vector<userRequest *> filterOutgoingRequest();
    void setUserList(vector<User *> &userList);
    bool handleRating(vector<userRequest *> &requestList);

    friend class RequestView;

    friend class RequestModel;

    friend class Request;
};

// Buffer functions for moving to the cpp file
// It's faster to do it this way instead of coding straight in the cpp file

#endif // REQUEST_CONTROLLER_H
