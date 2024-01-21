#include "../User.h"
#include "../Tools/Tool.h"


/*THIS FILE CONTAINS FUNCTIONS RELATING TO GUEST:
    - REGISTER TO BECOME MEMBER
    - SHOW INFO OF USERS WITHOUT RATING*/

// method to register to become user (for guest)
User registerMember(vector<User *> users)
{
    int fee = 20;
    string temp;
    User user;
    bool check = true;
    cout << "--------------Register--------------" << endl;
    cout << "Please enter your full name: ";
    getline(cin, temp);
    user.setFullName(temp);
    while (check == true)
    {
        cout << "Please enter your username: ";
        cin >> temp;
        if (checkValidUsername(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setUsername(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        bool check;
        cout << "Please enter your password: ";
        cin >> temp;
        if (checkValidPwd(temp) == false)
        {
            continue;
        }
        else
        {
            user.setPwd(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        cout << "Please enter your email: ";
        cin >> temp;
        if (checkValidEmail(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setEmail(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        cout << "Please enter your phone number: ";
        cin >> temp;
        if (checkValidPhoneNo(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setPhoneNo(temp);
            temp = "";
            break;
        }
    }
    cout << "Please enter your home address: ";
    cin >> temp;
    user.setHomeAddr(temp);
    temp = "";
    cout << "Initial credit points set to 20\n";
    user.setCreds(fee);
    users.push_back(&user);
    return user;
}

// method to showinfo without rating score
void showInfoWithoutRating(vector<User *> users)
{
    for(auto &each: users) {
        each->showInfo();
    }   
}