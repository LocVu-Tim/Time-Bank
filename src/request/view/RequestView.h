#ifndef REQUEST_VIEW_H
#define REQUEST_VIEW_H

#include <vector>
#include <string>
using namespace std;

class RequestView
{
private:
    vector<string> userInputs;

public:
    RequestView();
    // ~RequestView();
    // method supporting gettting input from user
    void setInput();
    void setOptionalInput();
    void checkOptionalInput();
    string getInput(int index);
    vector<string> getUserInputs();

    // Error handling for error controller
    void errorHandling(string error);

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
    void lookForSupport();

private:
    // Add your member variables here
};

#endif // REQUEST_VIEW_H
