#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include "../Request.h"
#include "../view/RequestView.h"
#include "../model/RequestModel.h"
#include "../controller/RequestController.h"

class RequestController
{
public:
    RequestController();
    ~RequestController();

    // Add your member functions here
    int OperationsList();
    void selectAvailableFunction(int choice, RequestView requestView, RequestModel requestModel);
    void createRequestObject(vector<string> userData);
    void listOrUnlist();
    // 1. List and unlist your own requests
    void list();
    void unlist();

private:
    // Add your member variables here
};

#endif // REQUEST_CONTROLLER_H
