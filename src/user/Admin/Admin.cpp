#include "../User.h"
#include "../Tools/Tool.h"

// method to show info
void User::showInfo()
{
    cout << username << "-" << fullName << "-" << email << "-" << homeAddr << "-" << phoneNo << "-" << creds << "-";
    if (role == 3)
    {
        cout << "Admin"
             << "-";
    }
    else if (role == 2)
    {
        cout << "Member"
             << "-";
    }
    cout << endl;
}

// method to change password for admin
void User::changePwdAdmin(vector<User *> users, string username)
{
    string reset;
    cout << "Enter username for changing password: ";
    cin >> username;

    User *user = findByUsername(users, username);
    if (user == nullptr)
    {
        cout << "Username not found\n";
    }
    else
    {
        cout << "Successfully found user. Please enter new password: ";
        cin >> reset;
        if (checkValidPwd(reset) == true)
        {
            user->setPwd(reset);
            cout << "Password successfully reset\n";
        }
    }
}