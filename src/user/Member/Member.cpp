#include "../User.h"

User::User() {}
// constructor
User::User(string username, string pwd, string fullName, string email,
           string homeAddr, string phoneNo, int creds, int ratingScore)
{
    this->username = username;
    this->pwd = pwd;
    this->fullName = fullName;
    this->email = email;
    this->homeAddr = homeAddr;
    this->phoneNo = phoneNo;
    this->creds = creds;
    this->ratingScore = ratingScore;
}

// constructor used for block function
User::User(const string &username)
{
    this->username = username;
}
// method to get username
string User::getUsername()
{
    return username;
}

// method to set username
void User::setUsername(string username)
{
    this->username = username;
}

// method to get password
string User::getPwd()
{
    return pwd;
}

// method to set password
void User::setPwd(string pwd)
{
    this->pwd = pwd;
}

// method to get full name
string User::getFullName()
{
    return fullName;
}

// method to set full name
void User::setFullName(string fullName)
{
    this->fullName = fullName;
}

// method to get email address
string User::getEmail()
{
    return email;
}

// method to set email
void User::setEmail(string email)
{
    this->email = email;
}

// method to get home address
string User::getHomeAddr()
{
    return homeAddr;
}

// method to set home address
void User::setHomeAddr(string homeAddr)
{
    this->homeAddr = homeAddr;
}

// method to get phone number
string User::getPhoneNo()
{
    return phoneNo;
}

// method to set phone number
void User::setPhoneNo(string phoneNo)
{
    this->phoneNo = phoneNo;
}

// method to get credit points
int User::getCreds()
{
    return creds;
}

// method to set credit points
void User::setCreds(int creds)
{
    this->creds = creds;
}

/*method to get and set role
1: Guest
2: Member
3: Admin*/
int User::getRole()
{
    return role;
}

// method to set role
void User::setRole(int role)
{
    this->role = role;
}

// method to get blocked
bool User::isBlocked()
{
    return block;
}

// method to get blocked person/people
vector<string> User::getBlocked()
{
    return blocked;
}

// method to set block
void User::setBlocked(string blocks)
{
    for (int i = 0; i < blocked.size(); i++)
    {
        this->blocked.push_back(blocks);
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