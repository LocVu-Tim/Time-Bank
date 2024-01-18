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
        requestForSupporter();
        break;
    case 3:
        viewAllRequests(*requestModel);
        break;
    case 4:
        fileUtility.modifyFile(requestModel->requestList);
        // exit(0);
        return;
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
        unlist();
        break;
    case 3:
        return selectAvailableFunction();
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
    cout << "Current data size: " << userData.size() << endl;
    if (userData.size() == 5)
    {
        // lookForSupport Request object to store data
        createRequestObject(userData);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
};

void RequestController::requestForSupporter()
{
    requestView->requestForSupporter();
    map<string, string> userData = requestView->getUserInputs();

    // TODO 6 is the real one
    // TODO fix the supporter field input from host -> supporter + host name
    if (userData.size() == 5)
    {
        // lookForSupport Request object to store data
        createRequestObject(userData);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}

// This is for finding all of the available request, excluding the current user and blocked user
vector<userRequest *> RequestController::filterRequestAvailable(vector<userRequest *> &requestList, string userId, vector<int> blocked)
{
    for (int i = 0; i < requestList.size(); i++)
    {
        // the user cannot see their own request
        if (requestList[i]->hostId == stoi(userId))
        {
            requestList.erase(requestList.begin() + i);
        }
        for (int j = 0; j < blocked.size(); j++)
        {
            if (requestList[i]->hostId == blocked[j])
            {
                requestList.erase(requestList.begin() + i);
            }
        }
    }
    return requestList;
}

vector<userRequest *>
RequestController::filterBasedOnHostRating(vector<userRequest *> &requestList, double hostRating)
{
    for (int i = 0; i < requestList.size(); i++)
    {
        if (hostRating < requestList[i]->minimumRatingForHost && requestList[i]->availability == false && requestList[i]->hostId != this->user->getUserId())
        {
            requestList.erase(requestList.begin() + i);
        }
    }
    return requestList;
}

// Filter the requests made by the user
vector<userRequest *> RequestController::filterUserList(vector<userRequest *> &requestList)
{
    vector<userRequest *> filteredList;
    for (int i = 0; i < requestList.size(); i++)
    {
        if (stoi(requestList[i]->userId) == this->user->getUserId())
        {
            filteredList.push_back(requestList[i]);
        }
    }
    // return vector<userRequest *>();
    return filteredList;
};

void RequestController::setUser(User *user)
{
    this->user = user;
};

void RequestController::setUserList(vector<User *> userList)
{
    this->userList = userList;
};

void RequestController::unlist()
{
    RequestView requestView;
    // filter out the request that user had created
    vector<userRequest *> filteredList = filterUserList(requestModel->requestList);
    if (filteredList.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    while (true)
    {
        requestView.unlist(filteredList, this->userList);
        string unlistChoice;
        cin >> unlistChoice;
        // return the object that user had selected
        userRequest *foundRequest = findARequest(stoi(unlistChoice) - 1, filteredList);
        int id = foundRequest->id;
        // pass the object to the requestModel
        int pos = requestModel->getPositionOfRequest(id);
        // if not found - display error and return to the main menu
        if (pos == -1)
        {
            cout << "No data found" << endl;
            return selectAvailableFunction();
        }
        // pop the object out of the requestModel vector
        requestModel->requestList.erase(requestModel->requestList.begin() + pos);
        // ask user if they want to continue
        cout << "Do you want to continue? (Y/n)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Y" || choice == "y")
        {
            continue;
        }
        else
        {
            return selectAvailableFunction();
        }
    }
}

void RequestController::viewAllRequests(RequestModel &rm)
{
    RequestView requestView;
    bool choice = true;
    string input;
    // filter by date first
    vector<userRequest *> dataToPass = rm.getRequests();
    vector<userRequest *> filteredData = requestView.dateFilter(dataToPass);

    // continue filtering by availability, excluding current user and blocked user
    vector<userRequest *> availableData = filterRequestAvailable(filteredData, this->user->getUsername(), this->user->getBlocked());
    // TODO qqTam thoi gan mock function vao day (this->user->getHostRating())
    availableData = filterBasedOnHostRating(availableData, 2.0);

    if (availableData.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    while (choice)
    {
        vector<userRequest *> requestList = rm.getRequests();
        cout << "Request list size: " << requestList.size() << endl;
        requestView.viewAllRequests(requestList, this->userList);
        cin >> input;
        if (input == "Y" || input == "y")
        {
            cout << "Please enter the option you want to request: " << endl;
            cin >> input;
            // look for the data (-1 because of display)
            userRequest *request = findARequest(stoi(input) - 1, filteredData);
            cout << "Data found! What do you want to do with the data?" << endl;
            cout << "1. Request" << endl;
            cout << "2. View user profile" << endl;
            cin >> input;
            if (input == "1")
            {
                cout << "Data found! Now modifying the data" << endl;
                // edit the data
                request->availability = false;
                request->supporterId = this->user->getUserId();
                cout << "Data modified!" << endl;
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
            else if (input == "2")
            {
                // view user profile
                User *user = findById(this->userList, stoi(request->userId));
                user->showInfoMember();
                cout << "Would you like to return to the previous page? (Y/n)" << endl;
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
        }
        else
        {
            choice = false;
            return selectAvailableFunction();
        }
    }
}

void RequestController::GuestViewAllRequests(RequestModel &rm)
{
    // filter by date and availability
    vector<userRequest *> dataToPass = rm.getRequests();
    vector<userRequest *> filteredData = requestView->dateFilter(dataToPass);
    requestView->GuestViewAllRequests(filteredData, this->userList);
    return;
    // return to the main interface qq
}

void RequestController::adminViewAllRequests(RequestModel &rm)
{
    // filter by date and availability
    vector<userRequest *> dataToPass = rm.getRequests();
    requestView->adminViewAllRequests(dataToPass, this->userList);
    return;
    // return to the main interface qq
}

// view all the request - user to join
void RequestController::hostViewAvailableRequest(RequestModel &rm)
{
    // filter by date and availability
    vector<userRequest *> dataToPass = rm.getRequests();
    vector<userRequest *> filteredData = requestView->dateFilter(dataToPass);
    vector<userRequest *> availableData = filterRequestAvailable(filteredData, this->user->getUsername(), this->user->getBlocked());
    // TODO qq find function to get user supporter rating, temporary mock function
    availableData = filterBasedOnSupporterRating(availableData, 2.0);
    requestView->viewAllHostRequests(availableData, this->userList);
    // apply -> find the request, available->false, supporterId = current user
    bool continueFlag = true;
    while (continueFlag)
    {
        cout << "Please enter the option you want to request: " << endl;
        string input;
        cin >> input;
        // look for the data (-1 because of display)
        userRequest *request = findARequest(stoi(input) - 1, filteredData);
        cout << "Data found! What do you want to do with the data?" << endl;
        cout << "1. Join" << endl;
        cout << "2. View host profile" << endl;
        cin >> input;
        if (input == "1")
        {
            cout << "Data found! Now modifying the data" << endl;
            // edit the data
            request->availability = false;
            request->hostId = this->user->getUserId();
            cout << "Data modified!" << endl;
        }
        else if (input == "2")
        {
            // view user profile
            User *user = findById(this->userList, request->hostId);
            user->showInfoMember();
            cout << "Would you like to return to the previous page? (Y/n)" << endl;
            cin >> input;
            if (input == "Y" || input == "y")
            {
                return selectAvailableFunction();
            }
        }
    }
};

vector<userRequest *> RequestController::filterBasedOnSupporterRating(vector<userRequest *> &requestList, double supporterRating)
{
    for (int i = 0; i < requestList.size(); i++)
    {
        if (supporterRating < requestList[i]->minimumRatingForSupporter && requestList[i]->availability == false && requestList[i]->hostId == this->user->getUserId())
        {
            requestList.erase(requestList.begin() + i);
        }
    }
    return requestList;
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

vector<userRequest *> RequestController::filterIncomingRequest()
{
    // get the current user id
    // get all the requests
    vector<userRequest *> requestList = requestModel->getRequests();
    // filter requests based on the current user id
    vector<userRequest *> filteredRequestList = {};
    for (int i = 0; i < requestList.size(); i++)
    {
        if (requestList[i]->hostId == user->getUserId() && requestList[i]->availability == false)
        {
            filteredRequestList.push_back(requestList[i]);
        }
    }
    return filteredRequestList;
};

vector<userRequest *> RequestController::filterOutgoingRequest()
{
    // get the current user id
    // get all the requests
    vector<userRequest *> requestList = requestModel->getRequests();
    // filter requests based on the current user id
    vector<userRequest *> filteredRequestList = {};
    for (int i = 0; i < requestList.size(); i++)
    {
        if (requestList[i]->supporterId == user->getUserId() && requestList[i]->availability == false)
        {
            filteredRequestList.push_back(requestList[i]);
        }
    }
    return filteredRequestList;
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
            cout << "Creating request..." << endl;
            cout << "User ID: " << this->user->getUserId() << endl;
            requestModel->createRequest(userData, this->user->getUserId(), {});
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
