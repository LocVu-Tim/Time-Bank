#include "../User.h"
#include "../Tools/Tool.h"

/*THIS FILE CONTAINS FUNCTIONS RELATING TO GUEST:
    - REGISTER TO BECOME MEMBER
    - SHOW INFO OF USERS WITHOUT RATING*/

// method to register to become user (for guest)
User registerMember(vector<User *> users)
{
    int fee = 20;
    int skill;
    string temp, fullName, userName, pwd, email, phone, homeAddr;
    User user;
    bool check = true;

    do
    {
        cout << "--------------Register--------------" << endl;

        cout << "Please enter your username: ";
        cin >> userName;
        if (!checkValidUsername(users, userName))
        {
            continue;
        }
        else
        {
            user.setUsername(userName);
            cout << "Please enter your full name: ";
            cin.ignore();
            getline(cin, fullName);
            user.setFullName(fullName);
            break;
        }
    } while (check);

    while (check)
    {
        cout << "Please enter your password: ";
        cin >> pwd;
        if (!checkValidPwd(pwd))
        {
            continue;
        }
        else
        {
            user.setPwd(pwd);
            break;
        }
    }

    while (check)
    {
        cout << "Please enter your email: ";
        cin >> email;
        if (!checkValidEmail(users, email))
        {
            continue;
        }
        else
        {
            user.setEmail(email);
            break;
        }
    }

    while (check)
    {
        cout << "Please enter your phone number: ";
        cin >> phone;
        if (!checkValidPhoneNo(users, phone))
        {
            continue;
        }
        else
        {
            user.setPhoneNo(phone);
            break;
        }
    }

    while (check)
    {
        cout << "List of skills:\n";
        cout << "1. Plumbing repairs\n";
        cout << "2. Tutoring\n";
        cout << "3. Garden care\n";
        cout << "4. House cleaning\n";
        cout << "Please choose your skill (Enter the number of the skill): ";
        cin >> skill;
        if (!(skill >=1 && skill <=4))
        {
            cout << "Invalid input\n";
        }
        else
        {
            user.addSkillFromList(user, skill);
            break;
        }
    }

    cout << "Please enter your home address: ";
    getline(cin, homeAddr);
    user.setHomeAddr(temp);

    cout << "Initial credit points set to 20\n";
    user.setCreds(fee);
    user.setUserId(users.size() + 1);
    user.setRole(2);
    users.push_back(&user);
    user.hostRatingScore = 0;
    user.skillRatingScore = 0;
    user.supporterRatingScore = 0;
    user.showAllInfo();
    return user;
}

// method to showinfo without rating score
void showInfoWithoutRating(vector<User *> users)
{
    for (auto &each : users)
    {
        if(each->getRole() == 2) {
            each->showInfo();
        }
        
    }
}