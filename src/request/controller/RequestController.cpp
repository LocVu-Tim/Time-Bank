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
        lookForSupport();
        break;
    case 6:
        break;
    default:
        requestView.errorHandling("Invalid choice");
        cin.clear();
        // Rerun again
        int choice = OperationsList();
        selectAvailableFunction(choice, requestView, requestModel);
        break;
    }
}

void RequestController::listOrUnlist()
{
    int choice;
    // RequestView requestView;
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
        requestView.errorHandling("Invalid choice");
        // Rerun again
        listOrUnlist();
        break;
    }
};

void RequestController::list()
{
    requestView.list();
    map<string, string> userData = requestView.getUserInputs();
    cout << "UserData:" << userData.size() << endl;

    if (userData.size() == 7)
    {
        // lookForSupport Request object to store data
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
    // FIXME: implement this function
}

void RequestController::lookForSupport()
{
    RequestView requestView;
    requestView.lookForSupport();
    map<string, string> userData = requestView.getUserInputs();
    if (userData.size() == 6)
    {
        // create Request object to store data
        createRequestObject(userData);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
};

// Functions that unrelated to the class
void RequestController::createRequestObject(map<string, string> userData)
{
    // TODO: add type data validation
    try
    {
        bool continueCreate = true;
        while (continueCreate)
        {
            requestModel.createRequest(userData);
            vector<userRequest *> Test = requestModel.getRequests();
            // write to file
            // requestModel.createRequest(request);

            cout << "Do you want to continue create request? (Y/N)" << endl;
            string choice;
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                continueCreate = true;
            }
            else
            {
                continueCreate = false;
            }
        }
        // redirect user back to the main menu
        OperationsList();
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        bool continueFlag = requestView.errorHandling("Invalid argument");
        if (continueFlag)
        {
            listOrUnlist();
        }
    }
}

void RequestController::onLoad()
{
    // load data from file
    requestModel.load();
}
