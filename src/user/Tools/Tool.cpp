#include "Tool.h"

// method to compare strings (case insensitive)
bool caseInsensitiveStringCompare(const string &str1, const string &str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    for (int i = 0; i < str1.length(); i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            return false;
        }
    }
    return true;
}

// method to compare strings (case sensitive)
bool caseSensitiveStringCompare(const string &str1, const string &str2)
{
    if (str1.compare(str2) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// method to check valid username
bool checkValidUsername(vector<User *> users, string userName)
{
    // check for valid length
    if (userName.size() < 4)
    {
        cout << "Username must contain 5 characters or more.\n";
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
    if (pwd.length() < 8)
    {
        cout << "Password must be at least 8 characters long\n";
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
        cout << "Inccorrect password";
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
    return nullptr; // Return nullptr if user is not found
}
