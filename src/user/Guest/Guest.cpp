#include "../User.h"
#include "../Tools/Tool.h"

/*THIS FILE CONTAINS FUNCTIONS RELATING TO GUEST:
    - REGISTER TO BECOME MEMBER
    - SHOW INFO OF USERS WITHOUT RATING*/

// method to register to become user (for guest)
User registerMember(vector<User *> users, User currentUser)
{
    int fee = 20;
    string temp;
    User user;
    bool check = true;
    cout << "--------------Register--------------" << endl;

    while(check) {
        cout << "Please enter your full name: ";
        getline(cin, temp);
        user.setFullName(temp);
        if(!(temp.empty())) {
            break;
        } else {
            continue;
        }
    }
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