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
    string getInput(int index);
    vector<string> getUserInputs();

    // Add your member functions here
    void viewAvailableFunctions();
    void listOrUnlist();
    // 1. list and unlist your own requests

    void list();
    void unlist();

private:
    // Add your member variables here
};

#endif // REQUEST_VIEW_H
