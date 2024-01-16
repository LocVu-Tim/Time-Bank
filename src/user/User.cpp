#include "User.h"
#include <iostream>
#include <utility>

/*THIS FILE CONTAINS GENERAL FUNCTIONS OF CLASS USER INCLUDING
    - GET SET METHODS
    - CHECK VALID METHODS
    - FIND BY USERNAME
*/

//Default constructor
User::User() {}

// Constructor
User::User(string userName, string pwd, string fullName, string email,
           string homeAddr, string phoneNo, bool block = false, vector<int> blocked = {}, int creds = 20,
           int role = 2,
           int userId = 0, double skillRatingScore = 0, double supporterRatingScore = 0, double hostRatingScore = 0,
           vector<Rating> ratings = {})
        : userName(std::move(userName)), pwd(std::move(pwd)), fullName(std::move(fullName)), email(std::move(email)),
          homeAddr(std::move(homeAddr)), phoneNo(std::move(phoneNo)), isBlock(block), blocked(std::move(blocked)),
          creds(creds), role(role), userId(userId),
          skillRatingScore(skillRatingScore),
          supporterRatingScore(supporterRatingScore),
          hostRatingScore(hostRatingScore),
          ratings(std::move(ratings)) {};

// constructor used for block function
User::User(const string &username) {
    this->userName = username;
}

// method to get username
string User::getUsername() {
    return userName;
}

// method to set username
void User::setUsername(string userName) {
    this->userName = std::move(userName);
}

// method to get password
string User::getPwd() {
    return pwd;
}

// method to set password
void User::setPwd(string pass) {
    this->pwd = std::move(pass);
}

// method to get full name
string User::getFullName() {
    return fullName;
}

// method to set full name
void User::setFullName(string fName) {
    this->fullName = std::move(fName);
}

// method to get email address
string User::getEmail() {
    return email;
}

// method to set email
void User::setEmail(string mail) {
    this->email = std::move(mail);
}

// method to get home address
string User::getHomeAddr() {
    return homeAddr;
}

// method to set home address
void User::setHomeAddr(string Addr) {
    this->homeAddr = std::move(Addr);
}

// method to get phone number
string User::getPhoneNo() {
    return phoneNo;
}

// method to set phone number
void User::setPhoneNo(string phoneNo) {
    this->phoneNo = phoneNo;
}

// method to get credit points
int User::getCreds() {
    return creds;
}

// method to set credit points
void User::setCreds(int creds) {
    this->creds = creds;
}

/*method to get and set role
1: Guest
2: Member
3: Admin*/
int User::getRole() {
    return role;
}

// method to set role
void User::setRole(int role) {
    this->role = role;
}

// method to get blocked
bool User::isBlocked() {
    return isBlock;
}

// method to get blocked person/people
vector<int> User::getBlocked() {
    return blocked;
}

// method to set block
void User::setBlocked(int blocks) {
    blocked.push_back(blocks);
}

// method to get userId
int User::getUserId() {
    return userId;
}

// Method to set user ID
void User::setUserId(int id) {
    this->userId = id;
}

//Method to get user ratings
const vector<Rating> &User::getRatings() const {
    return ratings;
}

//Method to set user rating
void setRatingScore(User user, int type, double score) {
    if (type == 1) {
        user.skillRatingScore = calRatingScore(user, type);
    } else if (type == 2) {
        user.supporterRatingScore = calRatingScore(user, type);
    } else if (type == 3) {
        user.hostRatingScore = calRatingScore(user, type);
    }
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

// method to reset password for member

// method to check valid username
bool checkValidUsername(vector<User *> users, string userName) {
    // check for valid length
    if (userName.size() < 4) {
        cout << "Username must contain 5 characters or more.\n";
        return false;
    }

    // check for no space
    for (int i = 0; i < userName.length(); i++) {
        if (isspace(userName[i])) {
            cout << "Username must not contain spaces.\n";
            return false;
        }
    }

    // check for matching username
    for (int i = 0; i < users.size(); i++) {
        if (caseInsensitiveStringCompare(users[i]->getUsername(), userName)) {
            cout << "Username is already taken.\n";
            return false;
        }
    }

    return true;
}

// method to check valid email
bool checkValidEmail(vector<User *> users, string email) {
    const regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    return regex_match(email, pattern);
}

// method to check valid phone number
bool checkValidPhoneNo(vector<User *> users, string phoneNo) {
    // phone no must have 10 digits
    if (phoneNo.length() != 10) {
        cout << "Phone number must have 10 digits.\n";
        return false;
    }
    // phone no must all be digits
    for (int i = 0; i < phoneNo.length(); i++) {
        if (!(isdigit(phoneNo[i]))) {
            cout << "Phone number must only contain digits\n";
            return false;
        }
    }
    // phone no must start with 0
    if (phoneNo[0] != '0') {
        cout << "Phone number must start with 0\n";
        return false;
    }

    // check if phone no alr existed
    for (int i = 0; i < users.size(); i++) {
        if (caseSensitiveStringCompare(users[i]->getPhoneNo(), phoneNo)) {
            cout << "Phone number already existed.\n";
            return false;
        }
    }

    return true;
}

// method to check valid password
bool checkValidPwd(string pwd) {
    if (pwd.length() < 8) {
        cout << "Password must be at least 8 characters long\n";
        return false;
    }

    for (int i = 0; i < pwd.length(); i++) {
        if (isspace(pwd[i])) {
            cout << "Password must not contain space\n";
            return false;
        }
    }
    return true;
}

// method to verify password
bool verifyPwd(User user, string pwd) {
    if (!caseSensitiveStringCompare(user.getPwd(), pwd)) {
        cout << "Incorrect password\n";
        return false;
    }
    return true;
}

// method to find user through username
User *findByUsername(const vector<User *> &users, const string &username) {
    for (const auto &userPtr: users) {
        if (caseInsensitiveStringCompare(userPtr->getUsername(), username)) {
            return userPtr;
        }
    }
    cout << "User not found\n";
    return nullptr; // Return nullptr if user is not found
}

//method to find user by id
User *findById(const vector<User *> &users, const int targetId) {
    for (const auto &userPtr: users) {
        if (userPtr->userId == targetId) {
            return userPtr;
        }
    }
    cout << "User not found\n";
    return nullptr;
}

// Method to count number of rating
int countRatings(const User &user, int type) {
    int count = 0;

    for (Rating rate: user.ratings) {
        if (type == rate.getRatingTypeNumb()) {
            count += 1;
        }
    }

    return count;
}

// Method to calculate rating score
double calRatingScore(const User &user, int type) {
    double sum = 0;
    double value = 0;

    for (Rating rate: user.ratings) {
        if (type == rate.getRatingTypeNumb()) {
            sum += rate.getRatingValue();
        }
    }

    value = sum / countRatings(user, type);

    return value;
}

// Method to update rating score
void updateScore(User user, int type) {

}