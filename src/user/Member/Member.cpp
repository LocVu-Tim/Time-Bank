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

// method to block member
void User::blockUser(vector<User *> users, string block)
{
    cout << "Enter username to block: ";
    cin >> block;
    if (findByUsername(users, block) == nullptr)
    {
        cout << "Username not found\n";
    }
    else
    {
        setBlocked(block);
        cout << "User " << block << " is blocked";
    }
}

// method to reset password for member
void User::changePwdMember(User user, string temp)
{
    string newPwd;
    cout << "Emter old password: ";
    cin >> temp;
    if (verifyPwd(user, temp) == true)
    {
        cout << "Password verified. Please enter new password: ";
        cin >> newPwd;
        if (checkValidPwd(newPwd) == true)
        {
            user.setPwd(newPwd);
            cout << "Password successfully reset\n";
        }
    }
    else
    {
        cout << "Incorrect password verification\n";
    }
}

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
// method to show info with blocked
void User::showInfoWithBlock(vector<User *> users)
{

    cout << "----------Show users information----------\n";
    for (int i = 0; i < users.size(); i++)
    {
        vector<string> blocks = users[i]->getBlocked();
        bool block = false;
        for (int j = 0; j < blocks.size(); j++)
        {
            if (username == blocks[j])
            {
                block = true;
            }
        }
        if (block == true)
        {
            continue;
        }
        else
        {
            users[i]->showInfo();
        }
    }
}