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

bool RequestView::isValidDate(string date)
{
  tm tm;
  istringstream ss(date);
  ss >> get_time(&tm, "%d/%m/%Y");
  return ss.fail() ? false : true;
};

// Might be improved with inserting the type of request as a parameter
void RequestView::checkBeforeSubmitting(string form)
{
  // validate date
  if (!isValidDate(userInputs["timeFrom"]) || !isValidDate(userInputs["timeTo"]))
  {
    errorHandling("Invalid date");
    if (form == "list")
    {
      return list();
    }
    else if (form == "requestForSupporter")
    {
      return requestForSupporter();
    }
  }

  // Validate if city is Ha Noi or Ho Chi Minh
  if (userInputs["city"] != "Ha Noi" && userInputs["city"] != "Ho Chi Minh")
  {
    errorHandling("Invalid city");
    if (form == "list")
    {
      return list();
    }
    else if (form == "requestForSupporter")
    {
      return requestForSupporter();
    }
  }

  // validate if the pointsPerHour is a number
  try
  {
    stod(userInputs["pointsPerHour"]);
  }
  catch (const std::invalid_argument &ia)
  {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
    errorHandling("Invalid argument");
    if (form == "list")
    {
      return list();
    }
    else if (form == "requestForSupporter")
    {
      return requestForSupporter();
    }
  }

  // validate if the minimumRatingForHost is a number
  try
  {
    stod(userInputs["minimumRatingForHost"]);
    // if the minimumRatingForHost is not empty, then it must be less than 5
    if (userInputs["minimumRatingForHost"] != "" && stod(userInputs["minimumRatingForHost"]) >= 5)
    {
      errorHandling("Invalid rating");
      if (form == "list")
      {
        return list();
      }
      else if (form == "requestForSupporter")
      {
        return requestForSupporter();
      }
    }
  }
  catch (const std::invalid_argument &ia)
  {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
    errorHandling("Invalid argument");
    if (form == "list")
    {
      return list();
    }
    else if (form == "requestForSupporter")
    {
      return requestForSupporter();
    }
  }

  // validate if skills not empty
  if (userInputs["skill"] == "")
  {
    errorHandling("Invalid skill");
    if (form == "list")
    {
      return list();
    }
    else if (form == "requestForSupporter")
    {
      return requestForSupporter();
    }
  }
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
  getline(cin, error);
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
  cout << "2. Request for a supporter" << endl;
  cout << "3. View all request" << endl;
  cout << "4. View all active requests" << endl;
  cout << "5. Search for a request" << endl;
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
  cout << "City (Only Ha Noi or Ho Chi Minh): " << endl;
  setInput("city");
  cout << "How many skill you want to request for: " << endl;
  cin >> numberOfSkills;
  cout << "Skill to perform " << endl;
  setMultipleInputs(numberOfSkills, "skill");
  cout << "Point consumed / hour: " << endl;
  setInput("pointsPerHour");
  cout << "Minimum rating for host (Optional, press Enter if you want to skip): " << endl;
  setOptionalInput("minimumRatingForHost");
  userInputs["requestOperation"] = "list";
  checkBeforeSubmitting(userInputs["requestOperation"]);
};

void RequestView::unlist()
{
  cout << "Your current requests: " << endl;
  cout << string(50, '=') << endl;
  // get all of the user's own the list of requests
  cout << "Which request do you want to remove?" << endl;
};

void RequestView::viewAllRequests(vector<userRequest *> &availableRequests)
{
  // qq change in the implementation - display all available reqyests
  vector<userRequest *> filteredData = dateFilter(availableRequests);
  cout << "Available requests: " << endl;
  for (int i = 0; i < filteredData.size(); i++)
  {
    cout << "Request no. " << i + 1 << endl;
    cout << string(50, '=') << endl;
    filteredData[i]->printInfo();
    cout << string(50, '=') << endl;
  }
  cout << "Would you like to look for support for any of the above requests? (y/n)" << endl;
}

vector<userRequest *> RequestView::dateFilter(vector<userRequest *> &dataToFilter)
{
  time_t now = time(0);
  // get the current date
  tm *ltm = localtime(&now);
  vector<userRequest *> filteredData;
  // if the time is between timeTo and timeFrom, then return the request
  // else return empty vector
  for (int i = 0; i < dataToFilter.size(); i++)
  {
    // convert string to date first
    string dateFrom = dataToFilter[i]->timeFrom;
    tm dateFrom_tm;
    istringstream ss(dateFrom);
    ss >> get_time(&dateFrom_tm, "%d/%m/%Y");
    // same with dateTo
    string dateTo = dataToFilter[i]->timeTo;
    tm dateTo_tm;
    istringstream ss2(dateTo);
    ss2 >> get_time(&dateTo_tm, "%d/%m/%Y");
    // Filter based on date and availability
    if (difftime(mktime(ltm), mktime(&dateFrom_tm)) >= 0 && difftime(mktime(&dateTo_tm), mktime(ltm)) >= 0 && dataToFilter[i]->availability == true)
    {
      // return dataToFilter;
      filteredData.push_back(dataToFilter[i]);
    }
  }
  // return vector<userRequest *>();
  return filteredData;
};

void RequestView::requestForSupporter()
{
  int numberOfSkills;
  cout << "==============================" << endl;
  cout << "Enter the time period you want to request another people (In date and with format dd/mm/yyyy): " << endl;
  cout << "From: " << endl;
  setInput("timeFrom");
  cout << "To: " << endl;
  setInput("timeTo");
  cout << "==============================" << endl;
  cout << "City (Only Ha Noi or Ho Chi Minh): " << endl;
  setInput("city");
  cout << "==============================" << endl;

  cout << "How many skill you want to list yourself for: " << endl;
  cin >> numberOfSkills;
  cout << "==============================" << endl;

  cout << "Skill to perform " << endl;
  setMultipleInputs(numberOfSkills, "skill");
  cout << "==============================" << endl;

  cout << "Point consumed / hour: " << endl;
  setInput("pointsPerHour");
  cout << "==============================" << endl;

  cout << "Minimum rating for supporter (Optional, press Enter if you want to skip): " << endl;
  setOptionalInput("minimumRatingForSupporter");
  cout << "==============================" << endl;

  userInputs["requestOperation"] = "requestForSupporter";
  checkBeforeSubmitting(userInputs["requestOperation"]);
};