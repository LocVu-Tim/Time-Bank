#include <iostream>
#include "Request.h"
#include "RequestView.h"
#include "RequestModel.h"
using namespace std;

class RequestController
{
    // display list of operations
    void displayOperations()
    {
        RequestView requestView;
        requestView.viewAvailableFunctions();
    }

    //
    void createRequest()
    {
    }

};