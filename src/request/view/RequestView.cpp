#include <iostream>
#include "../request.h"
#include "RequestView.h"

using namespace std;

RequestView::RequestView() {}

// RequestView::~RequestView(){};
// Get input from user
void RequestView::setInput()
{
  string input;
  cin >> input;
  userInputs.push_back(input);
};

void RequestView::setOptionalInput()
{
  string input;
  // can be empty -> optional
  getline(cin, input);
  cin.ignore(1000, '\n');
  userInputs.push_back(input);
};

// Might be improved with inserting the type of request as a parameter
void RequestView::checkOptionalInput()
{
  // since the 4th element is optional, check if it is empty
  // do check if there is any whitespace
  if (userInputs[4].empty())
  {
    // replace the empty string with 0
    userInputs[4] = "0";
  }
}

string RequestView::getInput(int index)
{
  return userInputs[index];
};

vector<string> RequestView::getUserInputs()
{
  return userInputs;
}

void RequestView::viewAvailableFunctions()
{
  cout << "1. List or unlist a request" << endl;
  cout << "2. Request for supporter" << endl;
  cout << "3. Delete a request" << endl;
  cout << "4. View all requests" << endl;
  cout << "5. View a request" << endl;
  cout << "6. Exit" << endl;
};

void RequestView::listOrUnlist()
{
  cout << "1. List" << endl;
  cout << "2. Unlist" << endl;
};

void RequestView::list()
{
  // sometimes views can also return values just like
  // user input in HTML forms
  cout << "Enter the time period you want to list yourself for request (In date and with format dd/mm/yyyy): " << endl;
  cout << "From: " << endl;
  string input;
  setInput();
  cout << "To: " << endl;
  setInput();
  cout << "Skill to perform: " << endl;
  setInput();
  cout << "Point consumed / hour: " << endl;
  setInput();
  cout << "Minimum rating for host (Optional, press Enter if you want to skip): " << endl;
  setOptionalInput();
  checkOptionalInput();
  // append at the end of the vector the type of request
  userInputs.push_back("list");
};

void RequestView::unlist()
{
  cout << "Unlist" << endl;
};

void RequestView ::lookForSupport()
{
  // 1. Look for external support
  // 2. Create a request
  cout << "Enter the time period you want to look for support (In date and with format dd/mm/yyyy): " << endl;
  cout << "From: " << endl;
  string input;
  setInput();
  cout << "To: " << endl;
  setInput();
  cout << "Skill to perform: " << endl;
  setInput();
  cout << "Point that you are willing to pay per hour: " << endl;
  setInput();
  cout << "Minimum rating for supporter: (Optional, press Enter if you want to skip) " << endl;
  setOptionalInput();
  checkOptionalInput();
  userInputs.push_back("lookForSupport");
};