#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include "../request.h"
#include "../view/RequestView.h"
#include "../model/RequestModel.h"
#include "../controller/RequestController.h"

class RequestController
{
private:
    RequestModel requestModel;
    RequestView requestView;

public:
    RequestController(RequestModel requestModel, RequestView requestView);
    ~RequestController();

    // Add your member functions here
    int OperationsList();
    void onLoad();
    void selectAvailableFunction(int choice, RequestView requestView, RequestModel requestModel);
    void createRequestObject(map<string, string> userData);
    void listOrUnlist();
    // 1. List and unlist your own requests
    void list();
    void unlist();
    void lookForSupport();

private:
    // Add your member variables here
};

#endif // REQUEST_CONTROLLER_H
