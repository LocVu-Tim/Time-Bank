#include "../User.h"
#include "../Tools/Tool.h"

// method to login
bool User::login(vector<User *> users, string checkUsername)
{
    string checkPwd;
    cout << "--------------Login--------------" << endl;
    if (role == 2)
    {
        cout << "Please enter registered username: ";
    }
    else if (role == 3)
    {
        cout << "Please enter predefined username: ";
    }

    cin >> checkUsername;
    User *user = findByUsername(users, checkUsername);
    if (user == nullptr)
    {
        cout << "Username not found\n";
        return false;
    }
    else
    {
        cout << "Please enter password: ";
        cin >> checkPwd;
        if (verifyPwd(*user, checkPwd) == true)
        {
            cout << "Login successful\n";
        }
        else
        {
            cout << "Incorrect username/password\n";
            return false;
        }
        return true;
    }
}

// method to show info add rating later
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