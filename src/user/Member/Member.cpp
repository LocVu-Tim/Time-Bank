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
