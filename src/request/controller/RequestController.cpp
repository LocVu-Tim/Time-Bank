#include <iostream>
#include "RequestController.h"
using namespace std;

RequestController::RequestController(RequestModel requestModel, RequestView requestView)
{
    // initialize the model
    this->requestModel = requestModel;
    this->requestView = requestView;
}
RequestController::~RequestController(){};

int RequestController::OperationsList()
{
    int choice;
    RequestView requestView;
    RequestModel requestModel;
    requestView.viewAvailableFunctions();
    cin >> choice;
    return choice;
}

void RequestController::selectAvailableFunction(int choice, RequestView requestView, RequestModel requestModel)
{
    switch (choice)
    {
    case 1:
        listOrUnlist();
        break;
    case 2:
        // create();
        break;
    case 6:
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

void RequestController::createRequestObject(vector<string> userData)
{
    // TODO: add type data validation
    try
    {
        requestModel.createRequest(userData);
        vector<Request *> Test = requestModel.getRequests();
        Test[0]->printInfo();
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
}

void RequestController::listOrUnlist()
{
    int choice;
    RequestView requestView;
    requestView.listOrUnlist();
    cin >> choice;
    switch (choice)
    {
    case 1:
        list();
        break;
    case 2:
        // unlist();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
};

void RequestController::list()
{
    RequestView requestView;
    requestView.list();
    vector<string> userData = requestView.getUserInputs();
    if (userData.size() == 5)
    {
        // create Request object to store data
        createRequestObject(userData);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
};

void RequestController::unlist()
{
    RequestView requestView;
    requestView.unlist();
    // Without the model, we cannot implement this function
    // FIXME: implement this function
}

void RequestController::create()
{
    RequestView requestView;
    requestView.create();
    vector<string> userData = requestView.getUserInputs();
    if (userData.size() == 5)
    {
        // create Request object to store data
        createRequestObject(userData);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
};
