#include <iostream>
#include "RequestController.h"
using namespace std;

RequestController::RequestController(){};
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
        RequestController::listOrUnlist();
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
        Request request;
        // ID is generated automatically
        int randomID = rand() % 1000 + 1; // random number between 1 and 1000

        // since the data is string, some of them need to be converted to int

        int pointConsumedPerHour = stoi(userData[3]);
        double minimumRatingForHost = stod(userData[4]);

        // store the data
        request.id = randomID;
        request.timeFrom = userData[0];
        request.timeTo = userData[1];
        request.skill = userData[2];
        request.pointsPerHour = pointConsumedPerHour;
        request.minimumRatingForHost = minimumRatingForHost;
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
};
