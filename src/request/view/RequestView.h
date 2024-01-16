#ifndef REQUEST_VIEW_H
#define REQUEST_VIEW_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
// Time handling
#include <ctime>
#include <sstream>
#include <iomanip>

#include "../model/RequestModel.h"

using namespace std;

class RequestView
{
private:
    // vector<string> userInputs;
    map<string, string> userInputs;

public:
    RequestView();
    // ~RequestView();
    // method supporting gettting input from user
    void setInput(string inputField);
    void setOptionalInput(string inputField);
    void checkBeforeSubmitting(string form);
    bool isValidDate(string date);
    string getInput(string field);
    map<string, string> getUserInputs();

    void setMultipleInputs(int numberOfInputs, string fieldName);

    // Error handling for error controller
    bool errorHandling(string error);

    // Validate user input
    // 1. Validate the date
    // bool validateDate(string date);

    // Add your member functions here
    void viewAvailableFunctions();
    void listOrUnlist();
    // 1. list and unlist your own requests
    void list();
    void unlist();

    // 2. lookForSupport a new request
    void lookForSupport(vector<userRequest *> &requestList);
    vector<userRequest *> dateFilter(vector<userRequest *> &dataToFilter);
};

#endif // REQUEST_VIEW_H
