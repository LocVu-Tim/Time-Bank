#include "user.h"

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
User::User(const string &username) : username(username), block(false) {}
// method to get username
string getUsername()
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

// method to top up credit points with pwd authorization
//  int User::topUpCreds (User user, int topUp) {
//      string temp;
//      cout << "Please enter password for authorization: ";
//      cin >> temp;
//      if(verifyPwd(user, temp) == false) {
//          cout << "Incorrect password";
//      } else{
//          cout << "Enter top up amount: ";
//          cin >> topUp;

//         creds += topUp;
//     }
//     return creds;
// }

// method to register to become user (for guest)
//  void User::registerMember(vector<User *> users) {
//      int fee = 20;
//      string temp;
//      User *user;
//      bool check = true;
//      cout << "--------------Register--------------" << endl;
//      cout << "Please enter your full name: ";
//      getline(cin, fullName);
//      user->setFullName(fullName);
//      while(true) {
//          cout << "Please enter your username: ";
//          cin >> temp;
//          if(checkValidUsername(users, temp) == false) {
//              continue;
//          } else {
//              user->setUsername(temp);
//              temp = "";
//              break;
//          }
//      }
//      while(true) {
//          cout << "Please enter your password: ";
//          cin >> temp;
//          if(checkValidPwd(temp) == false) {
//              continue;
//          } else {
//              user->setPwd(temp);
//              temp = "";
//              break;
//          }
//      }
//      while(true) {
//          cout << "Please enter your email: ";
//          cin >> temp;
//          if(checkValidEmail(users, temp) == false) {
//              continue;
//          } else {
//              user->setEmail(temp);
//              temp = "";
//              break;
//          }
//      }
//      while(true) {
//          cout << "Please enter your phone number: ";
//          cin >> temp;
//          if(checkValidPhoneNo(users, temp) == false) {
//              continue;
//          } else {
//              user->setPhoneNo(temp);
//              temp = "";
//              break;
//          }
//      }
//      cout << "Please enter your home address: ";
//      getline(cin, temp);
//      user->setHomeAddr(temp);
//      temp = "";
//      while(true) {
//          cout << "Please enter your city: ";
//          cin >> temp;
//          if(temp != "Ha Noi" || temp != "Sai Gon") {
//              continue;
//          } else {
//              user->setCity(temp);
//              temp = "";
//              break;
//          }
//      }
//      cout << "Initial credit points set to 20\n";
//      user->setCreds(fee);

// }

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

// method to login
//  bool User::login(vector<User *> users, string checkUsername) {
//      string checkPwd;
//      cout << "--------------Login--------------" << endl;
//      if(role == 2) {
//          cout << "Please enter registered username: ";
//      } else if (role == 3) {
//          cout << "Please enter predefined username: ";
//      }

//     cin >> checkUsername;
//     User *user = findByUsername(users, checkUsername);
//     if(user == nullptr) {
//         cout << "Username not found\n";
//         return false;
//     } else {
//         cout << "Please enter password: ";
//         cin >> checkPwd;
//         if(verifyPwd(*user, checkPwd) == true) {
//             cout << "Login successful\n";
//         } else {
//             cout << "Incorrect username/password\n";
//             return false;
//         }
//     return true;
//     }
// }

// method to showinfo without rating score
void User::showInfoWithoutRating(vector<User *> users)
{
    cout << username << " - " << fullName << " - " << phoneNo << " - " << email << " - " << homeAddr << " - " << creds << " - ";
    if (role == 3 || role == 2)
    {
        cout << role << " - "; // add rating later
    }
    cout << endl;
}

// method to block user from viewing content
string User::blockUser(vector<User *> users, string blocked, string blocker)
{
    cout << "Enter username to block: ";
    cin >> blocked;
    User *blockedUser = findByUsername(users, blocked);
    if (blockedUser == nullptr)
    {
        cout << "Could not find user\n";
    }
    else
    {
        cout << "User " << blockedUser->getUsername() << " is blocked\n";
        return blocked;
    }
}

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
    for (int i = 0; i < email.length(); i++)
    {
        if (!((email[i] == '@') && (email[i] != email[0] && email[i] != email[email.length() - 1])))
        {
            return false;
        }
        for (int i = 0; i < email.length(); i++)
        {
            if (isspace(email[i]))
            {
                cout << "Email must not contain spaces\n";
                return false;
            }
        }
        return true;
    }
}

// method to check valid phone number
bool checkValidPhoneNo(vector<User *> users, string phoneNo)
{
    // phone no must have 10 digits
    if (phoneNo.length() < 10)
    {
        cout << "Phone number must have 10 digits.\n";
        return false;
    }
    // phone no must all be digits
    for (int i = 0; i < phoneNo.length(); i++)
    {
        if (!(isdigit(phoneNo[i])))
        {
            cout << "Phone number must only contain digits";
            return false;
            break;
        }
    }
    // phone no must start with 0
    if (!(phoneNo[0] == '0'))
    {
        cout << "Phone number must start with 0";
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
