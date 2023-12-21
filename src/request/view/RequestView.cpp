#include <iostream>
#include "request.h"
#include "RequestView.h"

using namespace std;

class RequestView
{
public:
  RequestView() {}
  // View the available functions
  void viewAvailableFunctions()
  {
    cout << "1. List/Unlist" << endl;

    cout << "6. Back" << endl;
  }

  // List or unlist a request
  void listOrUnlist()
  {
    cout << "Choose an option: ";
    cout << "1. List" << endl;
    cout << "2. Unlist" << endl;
  }

  // LIST
  void list()
  {
    string periodFrom;
    string periodTo;
    cout << "Enter the following information: " << endl;
    // In some cases, the view can return a vector containing the information
    // that the controller needs to create a new request
    cout << "Period: From: ";
    cin >> periodFrom;
    cout << "Period: To: ";
    cin >> periodTo;
  }
};