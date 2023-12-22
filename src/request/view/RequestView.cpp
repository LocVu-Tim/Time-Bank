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
  cout << "2. Create a request" << endl;
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
  vector<string> data;
  // sometimes views can also return values just like
  // user input in HTML forms
  cout << "Enter the time period you want to list your requests for: " << endl;
  cout << "From: " << endl;
  string input;
  setInput();
  cout << "To: " << endl;
  setInput();
  cout << "Skill to perform: " << endl;
  setInput();
  cout << "Point consumed / hour: " << endl;
  setInput();
  cout << "Minimum rating for host: " << endl;
  setInput();
};

void RequestView::unlist()
{
  cout << "Unlist" << endl;
};