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

// Testing purpose
#include "../user/User.h"

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

    // load data from file
    rm.load();
    // Create a test user
    // User usertoTest = registerMember(userList);

    // User *relUser = &usertoTest;
    // rc.setUser(relUser);
    User *user = new User();
    User *toBeBlocked = new User();
    User *jao = *&toBeBlocked;
    jao->setUsername("jao");
    jao->setUserId(11);
    // Normal one
    User *testUser = *&user;
    testUser->setUsername("usefalcuty");
    testUser->setUserId(12);
    // Another one
    User *testUser2 = new User();
    testUser2->setUsername("usefalcuty2");
    testUser2->setUserId(13);

    testUser->setBlocked(to_string(jao->getUserId()));
    vector<User *> userList = {testUser, testUser2, jao};

    rc.setUser(testUser);
    rc.setUserList(userList);
    // cout << "User ID: " << testUser->getUserId() << endl;
    // cout << "You are logged in as: " << user->getUsername() << endl;

    rc.selectAvailableFunction();

    return 0;
}
