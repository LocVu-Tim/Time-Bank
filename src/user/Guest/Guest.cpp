#include "../User.h"
#include "../Tools/Tool.h"

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
void User::showInfoWithoutRating(vector<User *> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i]->getUsername() << " - " << users[i]->getFullName() << " - " << users[i]->getPhoneNo() << " - " << users[i]->getEmail() << " - " << users[i]->getHomeAddr() << " - " << users[i]->getCreds() << " - ";
        if (users[i]->getRole() == 3 || users[i]->getRole() == 2)
        {
            cout << users[i]->getRole() << " - "; // add rating later
        }
        cout << endl;
    }
}