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

// method to register to become user (for guest)
User registerMember(vector<User *> users)
{
    int fee = 20;
    string temp;
    User user;
    bool check = true;
    cout << "--------------Register--------------" << endl;
    cout << "Please enter your full name: ";
    getline(cin, temp);
    user.setFullName(temp);
    while (check == true)
    {
        cout << "Please enter your username: ";
        cin >> temp;
        if (checkValidUsername(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setUsername(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        bool check;
        cout << "Please enter your password: ";
        cin >> temp;
        if (checkValidPwd(temp) == false)
        {
            continue;
        }
        else
        {
            user.setPwd(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        cout << "Please enter your email: ";
        cin >> temp;
        if (checkValidEmail(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setEmail(temp);
            temp = "";
            break;
        }
    }
    while (check)
    {
        cout << "Please enter your phone number: ";
        cin >> temp;
        if (checkValidPhoneNo(users, temp) == false)
        {
            continue;
        }
        else
        {
            user.setPhoneNo(temp);
            temp = "";
            break;
        }
    }
    cout << "Please enter your home address: ";
    cin >> temp;
    user.setHomeAddr(temp);
    temp = "";
    cout << "Initial credit points set to 20\n";
    user.setCreds(fee);
    users.push_back(&user);
    return user;
}


// method to showinfo without rating score
void User::showInfoWithoutRating(vector<User *> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i]->getUsername() << " - " << users[i]->getFullName() << " - " << users[i]->getPhoneNo() << " - " << users[i]->getEmail() << " - " << users[i]->getHomeAddr() << " - " << users[i]->getCreds() << " - ";
        if (users[i]->getRole() == 3 || users[i]->getRole() == 2)
        {
            cout << users[i]->getRole() << " - "; // add rating later
        }
        cout << endl;
    }
}