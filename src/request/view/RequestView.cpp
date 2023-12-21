#include <iostream>
#include "request.h"
using namespace std;

class RequestView
{
public:
  RequestView() {}
  // View the available functions
  void viewAvailableFunctions()
  {
    cout << "1. Create a new request" << endl;
    cout << "2. View all requests" << endl;
    cout << "3. View a request" << endl;
    cout << "4. Update a request" << endl;
    cout << "5. Delete a request" << endl;
    cout << "6. Back" << endl;
  }

  // View all requests
  void viewAllRequests()
  {
  }

  // view information of a request
  void showInfo(Request *request)
  {
  }
};