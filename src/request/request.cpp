#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>

// Main components
#include "request.h"
#include "./view/RequestView.h"
#include "./controller/RequestController.h"
#include "./model/RequestModel.h"

using namespace std;

void Request::printInfo()
{
}

int main()
{
    // Request r;
    RequestView rv;
    RequestModel rm;
    RequestController rc(rm, rv);
    int selectedChoice;

    // Create a test user
    // User user();
    // load data from file
    rm.load();
    rc.selectAvailableFunction();
    return 0;
}
