#include "../request.h"
#include "RequestView.h"

// TODO list skill

RequestView::RequestView() {}

// RequestView::~RequestView(){};
// Get input from user
void RequestView::setInput(string inputField)
{
    string userInput;
    // cin >> userInput;
    getline(cin >> ws, userInput);
    userInputs[inputField] = userInput;
};

void RequestView::setOptionalInput(string inputField)
{
    string userinput;
    // can be empty -> optional
    getline(cin >> ws, userinput);
    // cin.ignore(1000, '\n');
    userInputs[inputField] = userinput;
};

bool RequestView::isValidDate(string date)
{
    tm tm;
    istringstream ss(date);
    ss >> get_time(&tm, "%d/%m/%Y");
    return !ss.fail();
};

// Might be improved with inserting the type of request as a parameter
void RequestView::checkBeforeSubmitting(string form)
{
    cout << isValidDate(userInputs["timeFrom"]) << endl;
    // validate date
    if (!isValidDate(userInputs["timeFrom"]) || !isValidDate(userInputs["timeTo"]))
    {
        errorHandling("Invalid date");
        if (form == "list")
        {
            return list();
        }
        else if (form == "requestForSupporter")
        {
            return requestForSupporter();
        }
    }

    // validate if the timeFrom is before timeTo
    tm dateFrom_tm;
    istringstream ss(userInputs["timeFrom"]);
    ss >> get_time(&dateFrom_tm, "%d/%m/%Y");
    tm dateTo_tm;
    istringstream ss2(userInputs["timeTo"]);
    ss2 >> get_time(&dateTo_tm, "%d/%m/%Y");
    if (difftime(mktime(&dateFrom_tm), mktime(&dateTo_tm)) >= 0)
    {
        errorHandling("Invalid date");
        if (form == "list")
        {
            return list();
        }
        else if (form == "requestForSupporter")
        {
            return requestForSupporter();
        }
    }

    // validate if the timeFrom is after the current date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (difftime(mktime(ltm), mktime(&dateFrom_tm)) >= 0)
    {
        errorHandling("Invalid date");
        if (form == "list")
        {
            return list();
        }
        else if (form == "requestForSupporter")
        {
            return requestForSupporter();
        }
    }

    // validate if the pointsPerHour is a number
    try
    {
        stod(userInputs["pointsPerHour"]);
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        errorHandling("Invalid argument");
        if (form == "list")
        {
            return list();
        }
        else if (form == "requestForSupporter")
        {
            return requestForSupporter();
        }
    }

    // validate if the minimumRatingForHost is a number
    try
    {
        stod(userInputs["minimumRatingForHost"]);
        // if the minimumRatingForHost is not empty, then it must be less than 5
        if (userInputs["minimumRatingForHost"] != "" && stod(userInputs["minimumRatingForHost"]) >= 5)
        {
            errorHandling("Invalid rating");
            if (form == "list")
            {
                return list();
            }
            else if (form == "requestForSupporter")
            {
                return requestForSupporter();
            }
        }
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        errorHandling("Invalid argument");
        if (form == "list")
        {
            return list();
        }
        else if (form == "requestForSupporter")
        {
            return requestForSupporter();
        }
    }
}

string RequestView::getInput(string inputField)
{
    return userInputs[inputField];
};

map<string, string> RequestView::getUserInputs()
{
    return userInputs;
}

// Get multiple inputs from user
void RequestView::setMultipleInputs(int numberOfInputs, string fieldName)
{
    for (int i = 0; i < numberOfInputs; i++)
    {
        string input;
        cin >> input;
        // make it a vector containing all the skills with delimiter
        userInputs[fieldName].append(input);
        if (i != numberOfInputs - 1)
        {
            userInputs[fieldName].append(",");
        }
    }
};

bool RequestView::errorHandling(string error)
{
    string userInput;
    cout << "==============================" << endl;
    cout << "Invalid choice" << endl;
    cout << "Reason: " << error << endl;
    cout << "Please try again" << endl;
    cout << "Press Enter key to continue..." << endl;
    getline(cin, userInput);
    // cin >> error;
    // cin >> error;
    // Clear the input buffer
    cin.ignore(10000, '\n');
    // cin.clear();
    cout << "==============================" << endl;
    return false;
}

void RequestView::viewAvailableFunctions()
{
    cout << "==============================" << endl;
    cout << "1. List or unlist a request" << endl;
    cout << "2. Request for a supporter" << endl;
    cout << "3. View all request" << endl;
    cout << "4. Exit" << endl;
    cout << "==============================" << endl;
};

void RequestView::listOrUnlist()
{
    cout << "==============================" << endl;
    cout << "1. List" << endl;
    cout << "2. Unlist" << endl;
    cout << "3. Back" << endl;
    cout << "==============================" << endl;
};

void RequestView::list()
{
    int numberOfSkills;
    cout << "Enter the time period you want to list yourself for request (In date and with format dd/mm/yyyy): "
         << endl;
    cout << "From: " << endl;
    setInput("timeFrom");
    cout << "To: " << endl;
    setInput("timeTo");
    // cout << "How many skill you want to request for: " << endl;
    // cin >> numberOfSkills;
    // cout << "Skill to perform " << endl;
    // setMultipleInputs(numberOfSkills, "skill");
    cout << "Point consumed / hour: " << endl;
    setInput("pointsPerHour");
    cout << "Minimum rating for host (Optional, press Enter if you want to skip): " << endl;
    setOptionalInput("minimumRatingForHost");
    userInputs["requestOperation"] = "list";
    checkBeforeSubmitting(userInputs["requestOperation"]);
};

void RequestView::unlist(vector<userRequest *> &availableRequests, vector<User *> &allUsers)
{
    cout << "Your current request for working: " << endl;
    cout << string(50, '=') << endl;
    for (int i = 0; i < availableRequests.size(); i++)
    {
        cout << "Request no. " << i + 1 << endl;
        cout << string(50, '=') << endl;
        availableRequests[i]->printInfo(allUsers);
        cout << string(50, '=') << endl;
    }
    cout << "Which request do you want to remove?" << endl;
};

// TODO - the data now need to be filtered by the rating of the request user to the current user.
void RequestView::viewAllRequests(vector<userRequest *> &availableRequests, vector<User *> &allUsers)
{
    // qq change in the implementation - display all available reqyests
    cout << "Available requests for you to join: " << endl;
    for (int i = 0; i < availableRequests.size(); i++)
    {
        cout << "Request no. " << i + 1 << endl;
        cout << string(50, '=') << endl;
        availableRequests[i]->printInfo(allUsers);
        cout << string(50, '=') << endl;
    }
    cout << "Would you like to support any of the above requests? (y/n)" << endl;
}

vector<userRequest *> RequestView::dateFilter(vector<userRequest *> &dataToFilter)
{
    time_t now = time(0);
    // get the current date
    tm *ltm = localtime(&now);
    vector<userRequest *> filteredData;
    // if the time is between timeTo and timeFrom, then return the request
    // else return empty vector
    for (int i = 0; i < dataToFilter.size(); i++)
    {
        // convert string to date first
        string dateFrom = dataToFilter[i]->timeFrom;
        tm dateFrom_tm;
        istringstream ss(dateFrom);
        ss >> get_time(&dateFrom_tm, "%d/%m/%Y");
        // same with dateTo
        string dateTo = dataToFilter[i]->timeTo;
        tm dateTo_tm;
        istringstream ss2(dateTo);
        ss2 >> get_time(&dateTo_tm, "%d/%m/%Y");
        // Filter based on date and availability
        if (difftime(mktime(ltm), mktime(&dateFrom_tm)) >= 0 && difftime(mktime(&dateTo_tm), mktime(ltm)) >= 0 &&
            dataToFilter[i]->availability)
        {
            // return dataToFilter;
            filteredData.push_back(dataToFilter[i]);
        }
    }
    // return vector<userRequest *>();
    return filteredData;
}

void RequestView::GuestViewAllRequests(vector<userRequest *> &requestList, vector<User *> &userList)
{
    cout << "Available requests: " << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        cout << "Request no. " << i + 1 << endl;
        cout << string(50, '=') << endl;
        requestList[i]->printInfo(userList);
        cout << string(50, '=') << endl;
    }
}

void RequestView::adminViewAllRequests(vector<userRequest *> &requestList, vector<User *> &userList)
{
    cout << "All requests: " << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        cout << "Request no. " << i + 1 << endl;
        cout << string(50, '=') << endl;
        requestList[i]->printInfo(userList);
        cout << string(50, '=') << endl;
    }
};

void RequestView::viewAllHostRequests(vector<userRequest *> &requestList, vector<User *> &userList)
{
    cout << "Your current requests: " << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        cout << "Request no. " << i + 1 << endl;
        cout << string(50, '=') << endl;
        requestList[i]->printInfo(userList);
        cout << string(50, '=') << endl;
    }
    cout << "Would you like to apply for any of the above requests? (y/n)" << endl;
};

void RequestView::requestForSupporter()
{
    int numberOfSkills;
    cout << "==============================" << endl;
    cout << "Enter the time period you want to request another people (In date and with format dd/mm/yyyy): " << endl;
    cout << "From: " << endl;
    setInput("timeFrom");
    cout << "To: " << endl;
    setInput("timeTo");
    cout << "==============================" << endl;

    // cout << "How many skill you want to list yourself for: " << endl;
    // cin >> numberOfSkills;
    // cout << "==============================" << endl;

    // cout << "Skill to perform " << endl;
    // setMultipleInputs(numberOfSkills, "skill");
    // cout << "==============================" << endl;

    cout << "Points to be paid / hour: " << endl;
    setInput("pointsPerHour");
    cout << "==============================" << endl;

    cout << "Minimum rating for supporter (Optional, press Enter if you want to skip): " << endl;
    setOptionalInput("minimumRatingForSupporter");
    cout << "==============================" << endl;

    userInputs["requestOperation"] = "requestForSupporter";
    checkBeforeSubmitting(userInputs["requestOperation"]);
}

//bool RequestView::requestConfirmation(string msg){};

void RequestView::viewIncomingRequests(vector<userRequest *> &requestList, vector<User *> &userList)
{
    cout << "==============================" << endl;
    cout << "=== Incoming Requests ===" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        cout << "Request " << i + 1 << endl;
        requestList[i]->printInfo(userList);
        cout << "==============================" << endl;
    }
    cout << "Do you want to accept any of the requests above(Y/n)?" << endl;
}

void RequestView::viewOutgoingRequests(vector<userRequest *> &requestList, vector<User *> &userList)
{
    cout << "==============================" << endl;
    cout << "=== Outgoing Requests ===" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < requestList.size(); i++)
    {
        cout << "Request " << i + 1 << endl;
        requestList[i]->printInfo(userList);
        cout << "==============================" << endl;
    }
    cout << "Do you want to accept any of the requests above(Y/n)?" << endl;
}
