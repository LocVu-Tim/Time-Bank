#include "../User.h"
#include "../Tools/Tool.h"

// method to login
bool User::loginAdmin(vector<User *> users, string checkUsername)
{
    string checkPwd;
    cout << "--------------Login--------------" << endl;
    
    cout << "Please enter predefined username: ";

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

// method to show info admin
void User::showInfoAdmin()
{
    cout << username << "-" << fullName << "-" << email << "-" << homeAddr << "-" << phoneNo << "-" << creds << "-" << "Admin\n" ;
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