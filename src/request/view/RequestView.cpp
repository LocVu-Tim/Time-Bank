#include <iostream>
#include "../request.h"
#include "RequestView.h"

RequestView::RequestView() {}

// RequestView::~RequestView(){};
// Get input from user
void RequestView::setInput(string inputField)
{
  string userInput;
  // cin >> userInput;
  getline(cin >> ws, userInput);
  userInputs[inputField] = userInput;
};

void RequestView::setOptionalInput(string inputField)
{
  string userinput;
  // can be empty -> optional
  getline(cin >> ws, userinput);
  // cin.ignore(1000, '\n');
  userInputs[inputField] = userinput;
};

// Might be improved with inserting the type of request as a parameter
void RequestView::checkOptionalInput()
{
  if (userInputs["minimumRatingForHost"].empty())
  {
    userInputs["minimumRatingForHost"] = "0";
  }
  //   else if (userInputs["minimumRatingForSupporter"].empty())
  //   {
  //     userInputs["minimumRatingForSupporter"] = "0";
  //   }
}

string RequestView::getInput(string inputField)
{
  return userInputs[inputField];
};

map<string, string> RequestView::getUserInputs()
{
  return userInputs;
}

// Get multiple inputs from user
void RequestView::setMultipleInputs(int numberOfInputs, string fieldName)
{
  for (int i = 0; i < numberOfInputs; i++)
  {
    string input;
    cin >> input;
    // userInputs[fieldName].append(input);
    // make it a vector containing all the skills with delimiter
    userInputs[fieldName].append(input);
    if (i != numberOfInputs - 1)
    {
      userInputs[fieldName].append(",");
    }
  }
};

bool RequestView::errorHandling(string error)
{
  cout << "==============================" << endl;
  cout << "Invalid choice" << endl;
  cout << "Reason: " << error << endl;
  cout << "Please try again" << endl;
  cout << "Press Enter key to continue..." << endl;
  getline(cin >> ws, error);
  // cin >> error;
  // Clear the input buffer
  cin.ignore(10000, '\n');
  // cin.clear();
  cout << "==============================" << endl;
  return true;
}

void RequestView::viewAvailableFunctions()
{
  cout << "==============================" << endl;
  cout << "1. List or unlist a request" << endl;
  cout << "2. Request for supporter" << endl;
  cout << "3. Delete a request" << endl;
  cout << "4. View all requests" << endl;
  cout << "5. View a request" << endl;
  cout << "6. Exit" << endl;
  cout << "==============================" << endl;
};

void RequestView::listOrUnlist()
{
  cout << "1. List" << endl;
  cout << "2. Unlist" << endl;
};

void RequestView::list()
{
  int numberOfSkills;

  cout << "Enter the time period you want to list yourself for request (In date and with format dd/mm/yyyy): " << endl;
  cout << "From: " << endl;
  setInput("timeFrom");
  cout << "To: " << endl;
  setInput("timeTo");
  cout << "City: " << endl;
  setInput("city");
  cout << "How many skill you want to list yourself for: " << endl;
  cin >> numberOfSkills;
  cout << "Skill to perform " << endl;
  setMultipleInputs(numberOfSkills, "skill");
  cout << "Point consumed / hour: " << endl;
  setInput("pointsPerHour");
  cout << "Minimum rating for host (Optional, press Enter if you want to skip): " << endl;
  setOptionalInput("minimumRatingForHost");
  // checkOptionalInput();
  userInputs["requestOperation"] = "list";
};

void RequestView::unlist()
{
  cout << "Unlist" << endl;
  // get all of the user's own the list of requests
};

void RequestView ::lookForSupport()
{
  // 1. Look for external support
  // 2. Create a request
  cout << "Enter the time period you want to look for support (In date and with format dd/mm/yyyy): " << endl;
  cout << "From: " << endl;
  string input;
  setInput("timeFrom");
  cout << "To: " << endl;
  setInput("timeTo");
  cout << "City: " << endl;
  setInput("city");
  cout << "Enter the nynver of skill you want to look for support: " << endl;
  int numberOfSkills;
  cin >> numberOfSkills;
  cout << "Skill you want to help with: " << endl;
  setMultipleInputs(numberOfSkills, "skill");
  cout << "Point that you are willing to pay per hour: " << endl;
  setInput("pointsPerHour");
  cout << "Minimum rating for supporter: (Optional, press Enter if you want to skip) " << endl;
  setOptionalInput("minimumRatingForSupporter");
  checkOptionalInput();
  userInputs["requestOperation"] = "lookForSupport";
};