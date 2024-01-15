#include "../User.h"
#include "../Tools/Tool.h"


/*THIS FILE CONTAINS FUNCTIONS RELATING TO MEMBER:
    - LOGIN WITH REGISTERED USERNAME AND PASSWORD
    - BLOCK OTHER MEMBER
    - SHOW INFO WITH AND WITHOUT BLOCK
    - CHANGE PASSWORD */


    
// method to login
bool User::loginMember(vector<User *> users, string checkUsername)
{
    string checkPwd;
    
    cout << "Please enter registered username: ";
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
void User::blockUser(vector<User *> users )
{
    string block;
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
void User::showInfoMember()
{
    cout << username << "-" << fullName << "-" << email << "-" << homeAddr << "-" << phoneNo << "-" << creds << "-" << "Member\n";
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
            if (getUsername() == blocks[j])
            {
                block = true;
                break;
            }
        }
        if (block == true)
        {
            continue;
        }
        else
        {
            users[i]->showInfoMember();
        }
    }
}