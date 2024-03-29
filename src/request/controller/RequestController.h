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
    void viewAllRequests(RequestModel &rm);
    void GuestViewAllRequests(RequestModel &rm);
    void adminViewAllRequests(RequestModel &rm);
    userRequest *findARequest(int position, vector<userRequest *> requestList);
    void requestForSupporter();
    // for view available request
    vector<userRequest *> filterRequestAvailable(vector<userRequest *> &requestList, string username, vector<int> blocked);
    // For looking for supporter
    vector<userRequest *> filterBasedOnHostRating(vector<userRequest *> &requestList, double hostRating);

    vector<userRequest *> filterUserList(vector<userRequest *> &requestList);
    void setUser(User *user);
    void setUserList(vector<User *> userList);

    friend class RequestView;
    friend class RequestModel;
    friend class Request;
};

#endif // REQUEST_CONTROLLER_H
