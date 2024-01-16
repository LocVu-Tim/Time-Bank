#include <iostream>
#include "RequestController.h"
using namespace std;

RequestController::RequestController(RequestModel &requestModel, RequestView &requestView)
{
    // initialize the model
    this->requestModel = &requestModel;
    this->requestView = &requestView;
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

void RequestController::selectAvailableFunction()
{
    int choice = OperationsList();
    fileUtility fileUtility;
    switch (choice)
    {
    case 1:
        listOrUnlist();
        break;
    case 2:
        lookForSupport(*requestModel);
        break;
    case 6:
        fileUtility.modifyFile(requestModel->requestList);
        exit(0);
    default:
        requestView->errorHandling("Invalid choice");
        cin.clear();
        // Rerun again
        selectAvailableFunction();
        break;
    }
}

void RequestController::listOrUnlist()
{
    int choice;
    // RequestView requestView;
    requestView->listOrUnlist();
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
        requestView->errorHandling("Invalid choice");
        // Rerun again
        listOrUnlist();
        break;
    }
};

void RequestController::list()
{
    requestView->list();
    map<string, string> userData = requestView->getUserInputs();

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
}

void RequestController::lookForSupport(RequestModel &rm)
{
    RequestView requestView;
    bool choice = true;
    string input;
    // filter by date first
    vector<userRequest *> dataToPass = rm.getRequests();
    vector<userRequest *> filteredData = requestView.dateFilter(dataToPass);
    if (filteredData.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    while (choice)
    {
        vector<userRequest *> requestList = rm.getRequests();
        cout << "Request list size: " << requestList.size() << endl;
        requestView.lookForSupport(requestList);
        cin >> input;
        if (input == "Y" || input == "y")
        {
            cout << "Please enter the option you want to request: " << endl;
            cin >> input;
            // look for the data (-1 because of display)
            userRequest *request = findARequest(stoi(input) - 1, filteredData);
            cout << "Data found! Now modifying the data" << endl;
            // edit the data
            // TODO: get the current user name as the host name
            request->hostName = "test";
            cout << "Data modified!" << endl;
            cout << "The current host name is: " << request->hostName << endl;
            cout << "Would you like to try again? (Y/n)" << endl;
            cin >> input;
            if (input == "Y" || input == "y")
            {
                choice = true;
            }
            else
            {
                choice = false;
                return selectAvailableFunction();
            }
        }
        else
        {
            choice = false;
            return selectAvailableFunction();
        }
    }
};

userRequest *RequestController::findARequest(int position, vector<userRequest *> requestList)
{
    cout << "Finding the data at position: " << position << endl;
    try
    {
        return requestList.at(position);
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return NULL;
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
            requestModel->createRequest(userData);
            vector<userRequest *> Test = requestModel->getRequests();
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
        return selectAvailableFunction();
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        bool continueFlag = requestView->errorHandling("Invalid argument");
        if (continueFlag)
        {
            listOrUnlist();
        }
    }
}

void RequestController::onLoad()
{
    // load data from file
    requestModel->load();
}
