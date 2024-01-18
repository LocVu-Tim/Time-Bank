#include "../User.h"
#include "../Tools/Tool.h"

/*THIS FILE CONTAINS FUNCTIONS RELATING TO GUEST:
    - REGISTER TO BECOME MEMBER
    - SHOW INFO OF USERS WITHOUT RATING*/

// method to register to become user (for guest)
User registerMember(vector<User *> users, User *currentUser)
{
    int fee = 20;
    string temp;
    
    bool check = true;
    cout << "--------------Register--------------" << endl;

    while (check) {
        cout << "Please enter your full name: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, temp);
        currentUser->setFullName(temp);
        if (!(temp.empty())) {
            break;
        } else {
            continue;
        }
    }

    while (check) {
        cout << "Please enter your username: ";
        cin >> temp;
        if (checkValidUsername(users, temp) == false) {
            continue;
        } else {
            currentUser->setUsername(temp);
            break;
        }
    }

    while (check) {
        cout << "Please enter your password: ";
        cin >> temp;
        if (checkValidPwd(temp) == false) {
            continue;
        } else {
            currentUser->setPwd(temp);
            break;
        }
    }

    while (check) {
        cout << "Please enter your email: ";
        cin >> temp;
        if (checkValidEmail(users, temp) == false) {
            cout << "Invalid email\n";
            continue;
        } else {
            currentUser->setEmail(temp);
            break;
        }
    }

    while (check) {
        cout << "Please enter your phone number: ";
        cin >> temp;
        if (checkValidPhoneNo(users, temp) == false) {
            continue;
        } else {
            currentUser->setPhoneNo(temp);
            break;
        }
    }

    cout << "Please enter your home address: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, temp);
    currentUser->setHomeAddr(temp);

    cout << "Initial credit points set to 20\n";
    currentUser->setCreds(fee);
    return *currentUser;
}

// method to showinfo without rating score
void User::showInfoWithoutRating(vector<User *> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getRole() == 2)
        {
            users[i]->showInfoMember();
        }
        if (users[i]->getRole() == 3)
        {
            users[i]->showInfoAdmin();
        }
    }
}