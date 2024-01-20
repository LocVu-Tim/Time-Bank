#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "welcomeInterface.h"

using namespace std;

void menu();

void Guest();

void Member();

void Admin();

void adminLogin();

void memberLogin();

void welcomeInterface()
{
    int choice;

    // Welcome Interface//
    cout << "" << endl;
    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "''Time BANK'' APPLICATION" << endl;
    cout << "" << endl;
    cout << "Instructor: Mr. Tran Duc Linh" << endl;
    cout << "Group: 18" << endl;
    cout << "s3891483 | Vu Loc" << endl;
    cout << "s3927082 | Van Hong Lam " << endl;
    cout << "s3979199 | Luong Anh Huy" << endl;
    cout << "s3978609 | Tran Tuan Minh" << endl;
    cout << "" << endl;
    menu();
}

void menu()
{
    int choice;
    bool running = true;

    while (running)
    {
        cout << "" << endl;
        cout << "**************************************************" << endl;
        cout << "************ WELCOME TO TIME BANK ****************" << endl;
        cout << "Use the app as: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Member" << endl;
        cout << "3. Guest" << endl;
        cout << "Enter Your Choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input! Please enter a number."
                 << "\n";
            continue;
            continue;
        }

        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            memberLogin();
            break;
        case 3:
            Guest();
            break;
        case 0:
            running = false;
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

void Admin()
{
    int choice;
    bool running = true;

    while (running)
    {
        cout << "\nAdmin menu\n";
        cout << "1.View admin information\n";
        cout << "2.Reset member password\n";
        cout << "3.Back to main menu\n";
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menu();
            break;
        case 2:
            menu();
            break;
        case 3:
            menu();
            break;

        case 0:
            running = false;
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice!"
                 << "\n";
            break;
        }
    }
}

void adminLogin()
{
    string aName, aPass, aN, aP;

    cout << "Enter username: ";
    cin >> aName;

    cout << "Enter password: ";
    cin >> aPass;

    ifstream adminFile("./welcomeInterface/adminDetail.dat");
    int found = 0;

    while (adminFile >> aN >> aP)
    {
        if (aName == aN && aPass == aP)
        {
            found = 1;
            break;
        }
    }

    adminFile.close();

    if (found)
    {
        cout << "Login Successful\n";
        Admin();
    }
    else
    {
        cout << "Login Error\n";
        adminLogin();
    }
}

void Member()
{
    // database
    RequestModel rm;
    RequestView rv;
    RequestController rc(rm, rv);

    // TODO: Request Test data - should be removed when user is implemented
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
    // TODO: finish this
//    testUser->();
    // Another one
    User *testUser2 = new User();
    testUser2->setUsername("usefalcuty2");
    testUser2->setUserId(13);

    testUser->setBlocked(jao->getUserId());
    // set skills
    testUser->setSkills({"C++", "Java", "Python"});
    testUser2->setSkills({"C++", "Java", "Python"});
    jao->setSkills({"C++", "Java", "Python"});
    vector<User *> userList = {testUser, testUser2, jao};

    int choice;
    cout << "enter 0 to 2 to test the user in function:" << endl;
    cin >> choice;
    rc.setUser(userList[choice]);
    rc.setUserList(userList);

    bool running = true;

    while (running)
    {
        cout << "\nMember Menu" << endl;
        cout << "1. View Information" << endl;
        cout << "2. Add Skills" << endl;
        cout << "3. List as Supporter" << endl;
        cout << "4. View Supporters" << endl;
        cout << "5. View Requests" << endl;
        cout << "6. Block Member" << endl;
        cout << "7. Back to Main Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menu();
            break;
        case 2:
            menu();
            break;
        case 3:
            menu();
            break;
        case 5:
            rc.selectAvailableFunction();
            break;

        case 0:
            running = false;
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice!"
                 << "\n";
            break;
        }
    }
}

void memberLogin()
{
    string mName, mPass, mN, mP;

    cout << "Enter username: ";
    cin >> mName;

    cout << "Enter password: ";
    cin >> mPass;

    ifstream memberFile("./welcomeInterface/memberDetail.dat");
    int found = 0;

    while (memberFile >> mN >> mP)
    {
        if (mName == mN && mPass == mP)
        {
            found = 1;
            break;
        }
    }

    memberFile.close();

    if (found)
    {
        cout << "Login Successful\n";
        Member();
    }
    else
    {
        cout << "Login Error\n";
        memberLogin();
    }
}

void Guest()
{

    int choice;
    cout << "1. View supporters\n";
    cout << "2. Register member\n";
    cout << "3. Back to main menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        menu();
        break;
    case 2:
        menu();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "Invalid choice!"
             << "\n";
        break;
    }
}
bool defaultData = false;

int main()
{
   vector<User *> users;
   User currentUser;
  // Vector to store user objects
    vector<User*> users;

    // Create and add two admin users
    User *admin1 = new User("admin1", "admin123", "Admin One", "admin1@example.com", "HO CHI MINH", "0987654321", {}, {"c++", "python", "java"}, 100, 3, 1, 4.5, 4.6, 4.7, {});
    User *admin2 = new User("admin2", "admin456", "Admin Two", "admin2@example.com", "HA NOI", "0123456789", {}, {"c", "python", "java"}, 150, 3, 2, 4.6, 4.7, 4.8, {});

    // Add admin users to the vector
    users.push_back(admin1);
    users.push_back(admin2);

    // Create and add seven regular users
    User *user1 = new User("user1", "user123", "User One", "user1@example.com", "Ho Chi Minh", "0765987325", {}, {"c#",  "java"}, 50, 2, 3, 3.3, 4.4, 5.5, {});
    User *user2 = new User("user2", "user456", "User Two", "user2@example.com", "Ha Noi", "0234456098", {}, {"c++", "python"}, 30, 2, 4, 1.1, 2.2, 3.3, {});
    User *user3 = new User("user3", "user789", "User Three", "user3@example.com", "hochiminh", "0234987098", {}, {"c",  "java"}, 75, 2, 5, 3.0, 4.0, 5.0, {});
    User *user4 = new User("user4", "user101", "User Four", "user4@example.com", "hanoi", "0876543321", {}, {"python", "java"}, 40, 2, 6, 4.9, 3.9, 2.9, {});
    User *user5 = new User("user5", "user111", "User Five", "user5@example.com", "hcm", "0321345890", {}, {"c", "java"}, 60, 2, 7, 3.8, 4.5, 3.9, {});
    User *user6 = new User("user6", "user121", "User Six", "user6@example.com", "hOcHiMinh", "0123780923", {}, {"c#"}, 20, 2, 8, 2.3, 3.5, 4.5, {});
    User *user7 = new User("user7", "user131", "User Seven", "user7@example.com", "HA Noi", "0678345123", {}, {"c"}, 90, 2, 9, 1.9, 2.8, 4.9, {});

    // Add regular users to the vector
    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);
    users.push_back(user4);
    users.push_back(user5);
    users.push_back(user6);
    users.push_back(user7);

    User currentUser;
    welcomeInterface();
    // currentUser = registerMember(users, currentUser);
    // currentUser.showInfoWithoutRating(users);
    // memberLogin(users, currentUser);
   return 0;
}