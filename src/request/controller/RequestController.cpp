#include <iostream>
#include "Request.h"
#include "RequestView.h"
#include "RequestModel.h"
using namespace std;

class RequestController
{
    // display list of operations
    void OperationsList()
    {
        int choice;
        RequestView requestView;
        requestView.viewAvailableFunctions();
        cin >> choice;
    }

    // Navigate to the selected operation
    void navigateFunction(int choice, RequestView requestView, RequestModel requestModel)
    {
        switch (choice)
        {
        case 1:
            listOrUnlist();
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    void listOrUnlist() {
        int choice;
        RequestView requestView;
        requestView.listOrUnlist();
        cin >> choice;
        switch (choice)
        {
        case 1:
            // RequestController.list();
            break;
        case 2:
            // RequestController.unlist();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    //
    void createRequest()
    {
    }
};