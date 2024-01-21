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
        viewAllRequests();
        break;
    case 4:
        hostViewAvailableRequest();
        break;
    case 5:
        incomingProcess();
        break;
    case 6:
        outgoingProcess();
        break;
    case 7:
        fileUtility.modifyFile(requestModel->requestList);
        // exit(0);
        break;
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
    vector<string> availableskills = user->getSkillList();
    requestView->userSkills = availableskills;
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

void RequestController::requestForSupporter()
{
    requestView->requestForSupporter();
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
}

// This is for finding all of the available request, excluding the current user and blocked user
vector<userRequest *> RequestController::filterRequestAvailable(vector<userRequest *> &requestList, int userId, vector<int> blocked)
{
    for (int i = 0; i < requestList.size();)
    {
        bool erased = false;
        // the user cannot see their own request
        if (requestList[i]->userId == (userId))
        {
            requestList.erase(requestList.begin() + i);
            erased = true;
        }
        // if not erased, continue checking
        if (!erased)
        {
            ++i;
        }
    }
    requestList = filterBasedOnBlocked(requestList, blocked);
    return requestList;
}

vector<userRequest *> RequestController::filterBasedOnBlocked(vector<userRequest *> &requestList, vector<int> blocked)
{
    for (int i = 0; i < requestList.size();)
    {
        bool erased = false;
        // if (requestList[i]->userId == blocked[])
        for (int j = 0; j < blocked.size(); j++)
        {
            if (requestList[i]->hostId == blocked[j])
            {
                requestList.erase(requestList.begin() + i);
                erased = true;
            }
        }
        if (!erased)
        {
            ++i;
        }
    }
    return requestList;
}

vector<userRequest *>
RequestController::filterBasedOnHostRating(vector<userRequest *> &requestList, double hostRating)
{
    bool erased = false;
    for (int i = 0; i < requestList.size();)
    {
        if (hostRating < requestList[i]->minimumRatingForHost && requestList[i]->availability == true && requestList[i]->hostId == -1)
        {
            requestList.erase(requestList.begin() + i);
            erased = true;
        }
        if (!erased)
        {
            ++i;
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
        if ((requestList[i]->userId) == this->user->getUserId())
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

void RequestController::setUserList(vector<User *> &userList)
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
        string continueFlag;
        requestView.unlist(filteredList, this->userList);
        cout << "Do you want to unlisten any of the request? (Y/n)" << endl;
        cin >> continueFlag;
        if (continueFlag == "n" || continueFlag == "N")
        {
            return selectAvailableFunction();
        }
        else if (continueFlag != "Y" && continueFlag != "y")
        {
            requestView.errorHandling("Invalid choice");
            return selectAvailableFunction();
        }
        cout << "Which request do you want to remove?" << endl;
        string unlistenChoice;
        cin >> unlistenChoice;
        // return the object that user had selected
        userRequest *foundRequest = findARequest(stoi(unlistenChoice) - 1, filteredList);
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

// support the host to view all of the available request
void RequestController::viewAllRequests()
{
    RequestView requestView;
    bool choice = true;
    string input;
    // filter by date first
    vector<userRequest *> dataToPass = requestModel->getRequests();
    vector<userRequest *> filteredData = requestView.dateFilter(dataToPass);

    // continue filtering by availability, excluding current user and blocked user
    int userId = this->user->getUserId();
    vector<int> blocked = this->user->getBlocked();
    vector<userRequest *> availableData = filterRequestAvailable(filteredData, userId, blocked);
    // Now filter by rating
    availableData = filterBasedOnHostRating(availableData, this->user->getHostRating());
    // and skills too (for compatibility job for them instead of all of the skills)
    string skill = this->user->getSkillList()[0];

    if (availableData.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    while (choice)
    {
        vector<userRequest *> requestList = requestModel->getRequests();
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
                User *user = findById(this->userList, (request->userId));
                user->showInfoWithRating();
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

// view all the request for supporter
void RequestController::hostViewAvailableRequest()
{
    // filter by date and availability
    vector<userRequest *> dataToPass = requestModel->getRequests();
    vector<userRequest *> filteredData = requestView->dateFilter(dataToPass);
    int userId = this->user->getUserId();
    vector<int> blocked = this->user->getBlocked();
    vector<userRequest *> availableData = filterRequestAvailable(filteredData, userId, blocked);
    availableData = filterBasedOnSupporterRating(availableData, this->user->getSupporterRating());
    if (availableData.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    requestView->viewAllHostRequests(availableData, this->userList);
    string choice;
    cin >> choice;
    if (choice == "n" || choice == "N")
    {
        return selectAvailableFunction();
    }
    else if (choice != "Y" && choice != "y")
    {
        requestView->errorHandling("Invalid choice");
        return selectAvailableFunction();
    }
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
            user->showInfoWithRating();
            cout << "Would you like to return to the previous page? (Y/n)" << endl;
            cin >> input;
            if (input == "Y" || input == "y")
            {
                return selectAvailableFunction();
            }
        }
    }
};

// assist the supporter to find the host
vector<userRequest *> RequestController::filterBasedOnSupporterRating(vector<userRequest *> &requestList, double supporterRating)
{
    bool erased = false;
    for (int i = 0; i < requestList.size();)
    {
        bool erased = false;
        if (supporterRating < requestList[i]->minimumRatingForSupporter && requestList[i]->availability == true && requestList[i]->hostId == -1)
        {
            requestList.erase(requestList.begin() + i);
            erased = true;
        }
        if (!erased)
        {
            ++i;
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
        if ((requestList[i]->userId) != user->getUserId() && requestList[i]->availability == false && (requestList[i]->supporterId != user->getUserId() || requestList[i]->hostId != user->getUserId()))
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
        if ((requestList[i]->supporterId == this->user->getUserId() || requestList[i]->hostId == this->user->getUserId()) && requestList[i]->availability == false && requestList[i]->userId == this->user->getUserId())
        {
            filteredRequestList.push_back(requestList[i]);
        }
    }
    return filteredRequestList;
};

// Functions that unrelated to the class
void RequestController::createRequestObject(map<string, string> userData)
{
    // maybe: add type data validation
    try
    {
        bool continueCreate = true;
        while (continueCreate)
        {
            cout << "Creating request..." << endl;
            string skill = userData["skill"];
            requestModel->createRequest(userData, this->user->getUserId(), skill, this->user);
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

void RequestController::incomingProcess()
{
    vector<userRequest *> incomingRequest = filterIncomingRequest();
    if (incomingRequest.size() == 0)
    {
        cout << "No data found" << endl;
        return selectAvailableFunction();
    }
    else
    {
        while (true)
        {
            string choice;
            requestView->viewIncomingRequests(incomingRequest, this->userList);
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                cout << "Type in the option you want to choose: " << endl;
                // get the request to modify
                cin >> choice;
                userRequest *request = findARequest(stoi(choice) - 1, incomingRequest);
                // check if the requester is the host or supporter
                if (request->hostId == this->user->getUserId())
                {
                    // if the requester is the host
                    // calculate the points consumed
                    if (!calculatePointsConsumedForHost(request))
                    {
                        break;
                    };
                }
                else
                {
                    // if the requester is the supporter
                    // calculate the points consumed
                    calculatePointsConsumedForSupporter(request);
                }
                request->isCompleted = true;
                cout << "Optional: Do you want to rate the user? (Y/n)" << endl;
                cin >> choice;
                if (choice == "Y" || choice == "y")
                {
                    handleRating(incomingRequest);
                }
                else
                {
                    cout << "Do you want to continue? (Y/n)" << endl;
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
            else
            {
                return selectAvailableFunction();
            }
        }
    }
}

void RequestController::outgoingProcess()
{
    {
        vector<userRequest *> outgoingProcess = filterOutgoingRequest();
        if (outgoingProcess.size() == 0)
        {
            cout << "No data found" << endl;
            return selectAvailableFunction();
        }
        else
        {
            while (true)
            {
                string choice;
                requestView->viewOutgoingRequests(outgoingProcess, this->userList);
                cin >> choice;
                if (choice == "Y" || choice == "y")
                {
                    // check if the list has any completed request
                    bool hasCompletedRequest = false;
                    for (int i = 0; i < outgoingProcess.size(); i++)
                    {
                        if (outgoingProcess[i]->isCompleted == true)
                        {
                            hasCompletedRequest = true;
                        }
                    }
                    if (hasCompletedRequest == false)
                    {
                        cout << "No completed request found" << endl;
                        return selectAvailableFunction();
                    }
                    else if (hasCompletedRequest == true)
                    {
                        handleRating(outgoingProcess);
                    }
                    {
                    }
                    // TODO rating
                    handleRating(outgoingProcess);
                    cout << "Do you want to continue? (Y/n)" << endl;
                }
                else
                {
                    return selectAvailableFunction();
                }
            }
        }
    }
}

bool RequestController::handleRating(vector<userRequest *> &requestList)
{
    string input;
    vector<userRequest *> filteredRequestList = filterRatedRequest(requestList);
    cout << "There is one or more completed request found" << endl;
    cout << "Request that you can rate: ";
    for (int i = 0; i < filteredRequestList.size(); i++)
    {
        cout << "Request " << i + 1 << ":" << endl;
        filteredRequestList[i]->printInfo(this->userList);
        cout << endl;
    }
    cout << "Please enter the option you want to choose: " << endl;
    cin >> input;
    // Before rating, check if the request is completed
    userRequest *request = findARequest(stoi(input) - 1, filteredRequestList);
    if (request->isCompleted == false)
    {
        cout << "The request is not completed yet" << endl;
        return false;
    }
    else if (request->isCompleted == true)
    {
        User *host = findById(this->userList, request->hostId);
        User *supporter = findById(this->userList, request->supporterId);
        // check if the user is the host or supporter
        if (request->hostId == this->user->getUserId())
        {
            // if the user is the host
            // check if the supporter has rated the host
            // if not, continue creating rating
            rateSupporter(host, supporter);
        }
        else
        {
            // if the user is the supporter
            // check if the host has rated the supporter
            // if not, continue creating rating
            rateHost(supporter, host);
        }
    }
    return true;
};

bool RequestController::calculatePointsConsumedForHost(userRequest *request)
{
    // get the duration of the request

    cout << "Enter the duration of the request (in hour): " << endl;
    int duration;
    cin >> duration;
    // points consumed = duration * pointsPerHour
    // store the points consumed in the request
    request->pointsConsumed = duration * request->pointsPerHour;
    // check if the user has enough points
    if (user->getCreds() < request->pointsConsumed)
    {
        cout << "You do not have enough points to complete the request" << endl;
        // return selectAvailableFunction();
        return false;
    }
    // modify the user
    user->setCreds(user->getCreds() - request->pointsConsumed);
    cout << "Points consumed: " << request->pointsConsumed << endl;
    // also add the points to the supporter
    User *supporter = findById(this->userList, request->supporterId);
    supporter->setCreds(supporter->getCreds() + request->pointsConsumed);
    return true;
}

// qq might not needed
void RequestController::calculatePointsConsumedForSupporter(userRequest *request)
{
    // get the duration of the request
    cout << "Enter the duration of the request: " << endl;
    int duration;
    cin >> duration;
    // points consumed = duration * pointsPerHour
    // store the points consumed in the request
    request->pointsConsumed = duration * request->pointsPerHour;
    // modify the user points
    user->setCreds(user->getCreds() + request->pointsConsumed);
    cout << "Points added to the supporter: " << request->pointsConsumed << endl;
    // also add the points to the supporter
    User *host = findById(this->userList, request->hostId);
    host->setCreds(host->getCreds() - request->pointsConsumed);
}

vector<userRequest *> RequestController::filterBasedOnSkills(vector<userRequest *> &requestList, string skill)
{
    bool erased = false;
    for (int i = 0; i < requestList.size();)
    {
        if (requestList[i]->skill[0] != skill)
        {
            requestList.erase(requestList.begin() + i);
            erased = true;
        }
        if (!erased)
        {
            ++i;
        }
    }
    return requestList;
}

vector<userRequest *> RequestController::filterRatedRequest(vector<userRequest *> &requestList)
{
    bool erased = false;
    for (int i = 0; i < requestList.size(); i++)
    {
        if (requestList[i]->isRated == true)
        {
            requestList.erase(requestList.begin() + i);
            erased = true;
        }
        if (!erased)
        {
            ++i;
        }
    }
    return requestList;
}
