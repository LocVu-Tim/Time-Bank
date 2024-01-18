#include "User.h"
#include <iostream>

/*THIS FILE CONTAINS GENERAL FUNCTIONS OF CLASS USER INCLUDING
    - GET SET METHODS
    - CHECK VALID METHODS
    - FIND BY USERNAME
*/

// constructor
User::User(){};
User::User(int userIdVal, string username, string pwd, string fullName, string email,
           string homeAddr, string phoneNo, int creds, int ratingScore) : role(0)
{
    this->userId = userIdVal;
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

// method to get rating score
int User::getRatingScore()
{
    return ratingScore;
}

// method to set rating score
void User::setRatingScore(int ratingScore)
{
    this->ratingScore = ratingScore;
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
    blocked.push_back(blocks);
}

// method to get userId
int User::getUserId()
{
    return userId;
}

void User::setUserId(int userId)
{
    this->userId = userId;
}
// method to top up credit points with pwd authorization
int User::topUpCreds(User user, int topUp)
{
    string temp;
    cout << "Please enter password for authorization: ";
    cin >> temp;
    if (verifyPwd(user, temp) == false)
    {
        cout << "Incorrect password";
    }
    else
    {
        cout << "Enter top up amount: ";
        cin >> topUp;

        creds += topUp;
    }
    return creds;
}

// method to reset password for member

// method to check valid username
bool checkValidUsername(vector<User *> users, string userName)
{
    // check for valid length
    if (!(userName.size() > 4 && userName.size() < 21))
    {
        cout << "Username must contain 5-20 characters.\n";
        return false;
    }

    // check for no space
    for (int i = 0; i < userName.length(); i++)
    {
        if (isspace(userName[i]))
        {
            cout << "Username must not contain spaces.\n";
            return false;
        }
    }

    // check for matching username
    for (int i = 0; i < users.size(); i++)
    {
        if (caseInsensitiveStringCompare(users[i]->getUsername(), userName) == true)
        {
            cout << "Username is already taken.\n";
            return false;
            break;
        }
    }

    return true;
}

// method to check valid email
bool checkValidEmail(vector<User *> users, string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(email, pattern);
}

// method to check valid phone number
bool checkValidPhoneNo(vector<User *> users, string phoneNo)
{
    // phone no must have 10 digits
    if (phoneNo.length() != 10)
    {
        cout << "Phone number must have 10 digits.\n";
        return false;
    }
    // phone no must all be digits
    for (int i = 0; i < phoneNo.length(); i++)
    {
        if (!(isdigit(phoneNo[i])))
        {
            cout << "Phone number must only contain digits\n";
            return false;
            break;
        }
    }
    // phone no must start with 0
    if (!(phoneNo[0] == '0'))
    {
        cout << "Phone number must start with 0\n";
        return false;
    }

    // check if phone no alr existed
    for (int i = 0; i < users.size(); i++)
    {
        if (caseSensitiveStringCompare(users[i]->getPhoneNo(), phoneNo) == true)
        {
            cout << "Phone number already existed.\n";
            return false;
            break;
        }
    }

    return true;
}

// method to check valid password
bool checkValidPwd(string pwd)
{
    if (!(pwd.size() >= 8 && pwd.size() <= 15))
    {
        cout << "Password must contain 8-15 characters.\n";
        return false;
    }

    for (int i = 0; i < pwd.length(); i++)
    {
        if (isspace(pwd[i]))
        {
            cout << "Password must not contain space\n";
            return false;
        }
    }
    return true;
}

// method to verify password
bool verifyPwd(User user, string pwd)
{
    if (caseSensitiveStringCompare(user.getPwd(), pwd) == false)
    {
        cout << "Inccorrect password\n";
        return false;
    }
    return true;
}

// method to find user thru username
User *findByUsername(const vector<User *> &users, const string &username)
{
    for (const auto &userPtr : users)
    {
        if (caseInsensitiveStringCompare(userPtr->getUsername(), username))
        {
            return userPtr;
        }
    }
    cout << "User not found\n";
    return nullptr; // Return nullptr if user is not found
}

User *findById(const vector<User *> &users, const int targetId)
{
    for (const auto &userPtr : users)
    {
        if (userPtr->userId == targetId)
        {
            return userPtr;
        }
    }
    cout << "User not found\n";
    return nullptr;
}
