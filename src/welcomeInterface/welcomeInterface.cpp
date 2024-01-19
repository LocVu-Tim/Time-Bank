#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "../user/Admin/Admin.cpp"
#include "../user/Member/Member.cpp"
#include "../user/Guest/Guest.cpp"
#include "../user/User.h"
#include "../user/Tools/Tool.h"
#include "../user/Tools/Tool.cpp"
#include "../user/User.cpp"
#include "../rating/rating.h"
#include "../rating/rating.cpp"

using namespace std;

void menu(vector<User *> users, User currentUser);
void Guest(vector<User *> users, User currentUser);
void Member(vector<User *> users, User currentUser);
void Admin(vector<User *> users, User currentUser);
void adminLogin(vector<User *> users, User currentUser);
void memberLogin(vector<User *> users, User currentUser);

void welcomeInterface(vector<User *> &users, User currentUser)
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
    menu(users, currentUser);
}

void menu(vector<User *> users, User currentUser)
{
    int role;
    bool running = true;

    while (running)
    {
        cout << "" << endl;
        cout << "**************************************************" << endl;
        cout << "************ WELCOME TO TIME BANK ****************" << endl;
        cout << "Use the app as: " << endl;
        cout << "1. Guest" << endl;
        cout << "2. Member" << endl;
        cout << "3. Admin" << endl;
        cout << "Enter Your Choice: ";

        cin >> role;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input! Please enter a number."
                 << "\n";
            continue;
        }

        switch (role)
        {
        case 1:
            Guest(users, currentUser);
            break;
        case 2:
            memberLogin(users, currentUser);
            break;
        case 3:
            adminLogin(users, currentUser);
            break;
        case 0:
            running = false;
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        // running = false;
    }
}

void Admin(vector<User *> users, User currentUser)
{
    int choice;
    bool running = true;

    while (running)
    {
        cout << "\nAdmin menu\n";
        cout << "1.Reset Member password\n";
        cout << "2.Back to main menu\n";
        cout << "3.Show information of all users\n";
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        string username;
        switch (choice)
        {
        case 1: // Reset Member password
            
            cout << "\nChoose a Member to reset password \n";
            // View all Member information
            for(auto &user: users) {
                if(user->getRole() == 2) {
                    user->showAllInfo();
                }
                
                cout << endl;
            }
            cout << "Enter username for changing password: ";
            cin >> username;
            currentUser.changePwdAdmin(users, username);
            (findByUsername(users, username))->showAllInfo();
            break;
        case 2:
            menu(users, currentUser);
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

void adminLogin(vector<User *> users, User currentUser)
{
    string aName;
    if(currentUser.loginAdmin(users, aName) == true) {
        Admin(users, currentUser);
    }
    else{
        menu(users, currentUser);
    }
}

void Member(vector<User *> users, User currentUser)
{
    int choice;
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
        case 1: // View Information
            findMemberByUsername(users, currentUser.getUsername())->showAllInfo();
            break;

        case 2: // add skill
            // menu();
            break;

        case 3: // list as supporter
            // menu();
            break;

        case 4: // view request
            switch (choice)
            {
            // choose host
            case 1: // host 1
                // menu();
                break;
            case 2: // host 2..
                // menu(); //your booking is received
                // previous booked request
                break;
            case 3:
                // menu();
                break;
            case 4:
                // menu();
                break;
            }
            // menu();
            break;
        case 5:
            // menu();
            break;
        case 6:
            // menu();
            break;
        case 7:
            menu(users, currentUser);
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

void memberLogin(vector<User *> users, User currentUser)
{
    string mName, mPass;
    if (currentUser.loginMember(users, mName) == true)
    {
        Member(users, currentUser);
        currentUser.setUsername(mName);
        cout << currentUser.getUsername();
    }
    else
    {
        memberLogin(users, currentUser);
    }
}

void Guest(vector<User *> users, User currentUser)
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
        currentUser.showInfoWithoutRating(users);
        break;
    case 2:
        registerMember(users, currentUser);
        // currentUser.showInfoWithoutRating(users);
        // users.push_back(&currentUser);
        break;
    case 3:
        menu(users, currentUser);
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
    User nextUser;
    User admin1 = User("admin1", "password1", "John Doe", "john@example.com", "123 Main St", "0123456789", false, {}, 20, 3, 1, 3, 4, 2, {});
    User admin2 = User("admin2", "password2", "Jane Doe", "jane@example.com", "456 Oak St", "0213645987", false, {}, 20, 3, 2, 3, 4, 2, {});
    User user1 = User("user1", "password3", "Bob Doe", "bob@example.com", "234 Wall St", "0345671298", false, {}, 20, 2, 3, 3, 4, 2, {});
    User user2 = User("user2", "password4", "Bob Smtih", "smith@example.com", "234 Oak St", "0498765298", false, {}, 20, 2, 4, 3, 4, 2, {});
    User user3 = User("user3", "password5", "John Smtih", "jsmtih@example.com", "456 Main St", "0512345678", false, {}, 20, 2, 5, 3, 4, 2, {});
    User user4 = User("user4", "password6", "Bob Dover", "dover@example.com", "789 Greens St", "0648395023", false, {}, 20, 2, 6, 3, 4, 2, {});
    User user5 = User("user5", "password7", "Peter Smtih", "peter@example.com", "123 Greens St", "0712312345", false, {}, 20, 2, 7, 3, 4, 2, {});
    User user6 = User("user6", "password8", "Peter Parker", "parker@example.com", "345 Brooklyn St", "0898745631", false, {}, 20, 2, 8, 3, 4, 2, {});
    User user7 = User("user7", "password9", "Harry Bon", "bon@example.com", "123 Oak St", "0923784590", false, {}, 20, 2, 9, 3, 4, 2, {});

    users = {&admin1, &admin2, &user1, &user2, &user3, &user4, &user5, &user6, &user7};
    welcomeInterface(users, currentUser);
    // currentUser = registerMember(users, currentUser);
    // currentUser.showInfoWithoutRating(users);
    // memberLogin(users, currentUser);
    return 0;
}
