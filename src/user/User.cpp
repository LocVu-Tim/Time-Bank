#include "User.h"
#include "../Width.h"
#include <iostream>
#include <utility>

/*THIS FILE CONTAINS GENERAL FUNCTIONS OF CLASS USER INCLUDING
    - GET SET METHODS
    - CHECK VALID METHODS
    - FIND BY USERNAME
*/

// Default constructor
User::User() {}

// Constructor
User::User(string userName, string pwd, string fullName, string email,
           string homeAddr, string phoneNo, vector<int> blocked = {}, vector<string> skills, int creds = 20,
           int role = 2,
           int userId = 0, double skillRatingScore = 0, double supporterRatingScore = 0, double hostRatingScore = 0,
           vector<Rating> ratings = {})
    : userName(std::move(userName)), pwd(std::move(pwd)), fullName(std::move(fullName)),
      email(std::move(email)),
      homeAddr(std::move(homeAddr)), phoneNo(std::move(phoneNo)), blocked(std::move(blocked)),skills(std::move(skills)),
      creds(creds), role(role), userId(userId),
      skillRatingScore(skillRatingScore),
      supporterRatingScore(supporterRatingScore),
      hostRatingScore(hostRatingScore),
      ratings(std::move(ratings)){};

// constructor used for block function
User::User(const string &username)
{
    this->userName = username;
}

// method to get username
string User::getUsername()
{
    return userName;
}

// method to set username
void User::setUsername(string userName)
{
    this->userName = std::move(userName);
}

// method to get password
string User::getPwd()
{
    return pwd;
}

// method to set password
void User::setPwd(string pass)
{
    this->pwd = std::move(pass);
}

// method to get full name
string User::getFullName()
{
    return fullName;
}

// method to set full name
void User::setFullName(string fName)
{
    this->fullName = std::move(fName);
}

// method to get email address
string User::getEmail()
{
    return email;
}

// method to set email
void User::setEmail(string mail)
{
    this->email = std::move(mail);
}

// method to get home address
string User::getHomeAddr()
{
    return homeAddr;
}

// method to set home address
void User::setHomeAddr(string Addr)
{
    this->homeAddr = std::move(Addr);
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
// int User::getRatingScore()
// {
//     return ratingScore;
// }

// method to set rating score
// void User::setRatingScore(int ratingScore)
// {
//     this->ratingScore = ratingScore;
// }
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

// method to get blocked person/people
vector<int> User::getBlocked()
{
    return blocked;
}

// method to set block
void User::setBlocked(int blocks)
{
    blocked.push_back(blocks);
}

// method to get userId
int User::getUserId()
{
    return userId;
}

// Method to set user ID
void User::setUserId(int id)
{
    this->userId = id;
}

// Method to get user ratings
const vector<Rating> &User::getRatings() const
{
    return ratings;
}

// method to top up credit points with pwd authorization
int User::topUpCreds(User user, int topUp)
{
    string temp;
    cout << "Please enter password for authorization: ";
    cin >> temp;
    if (!verifyPwd(std::move(user), temp))
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

// method to show info
void User::showInfo()
{
    cout.width(USERNAME_WIDTH);
    cout << left << userName;
    cout.width(FULLNAME_WIDTH);
    cout << left << fullName;
    cout.width(EMAIL_WIDTH);
    cout << left << email;
    cout.width(HOME_ADDR_WIDTH);
    cout << left << homeAddr;
    cout.width(PHONE_NUMBER_WIDTH);
    cout << left << phoneNo;
    cout.width(CREDIT_POINT_WIDTH);
    cout << left << creds;
}

// method to check valid username
bool checkValidUsername(vector<User *> users, string userName)
{
    // check for valid length
    if (!(userName.size() > 4 && userName.size() < 16))
    {
        cout << "Username must contain 5-15 characters.\n";
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
        if (caseInsensitiveStringCompare(users[i]->getUsername(), userName))
        {
            cout << "Username is already taken.\n";
            return false;
        }
    }

    return true;
}

// method to check valid email
bool checkValidEmail(const vector<User *> &users, const string &email)
{
    const regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

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
        }
    }
    // phone no must start with 0
    if (phoneNo[0] != '0')
    {
        cout << "Phone number must start with 0\n";
        return false;
    }

    // check if phone no alr existed
    for (int i = 0; i < users.size(); i++)
    {
        if (caseSensitiveStringCompare(users[i]->getPhoneNo(), phoneNo))
        {
            cout << "Phone number already existed.\n";
            return false;
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
bool verifyPwd(User user, const string pwd)
{
    if (!caseSensitiveStringCompare(user.getPwd(), pwd))
    {
        cout << "Incorrect password\n";
        return false;
    }
    return true;
}

// method to find user through username
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

// method to find user by id
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

// Method to count number of rating
int countRatings(const User &user, int type)
{
    int count = 0;

    for (Rating rate : user.ratings)
    {
        if (type == rate.getRatingTypeNumb())
        {
            count += 1;
        }
    }

    return count;
}

// Method to calculate rating score
double calRatingScore(const User &user, int type)
{
    double sum = 0;
    double value = 0;

    for (Rating rate : user.ratings)
    {
        if (type == rate.getRatingTypeNumb())
        {
            sum += rate.getRatingValue();
        }
    }

    value = sum / countRatings(user, type);

    return value;
}

// Method to get host rating
double User::getHostRating() const
{
    return this->hostRatingScore;
}

// Method to get skill rating
double User::getSkillRating() const
{
    return this->skillRatingScore;
}

// Method to get supporter rating
double User::getSupporterRating() const
{
    return this->supporterRatingScore;
}

// Method to get skill list
vector<string> User::getSkillList()
{
    return this->skills;
}

// Method to set user rating score
void updateRatingScore(User *user, int type)
{
    if (type == 1)
    {
        user->skillRatingScore = calRatingScore(*user, type);
    }
    else if (type == 2)
    {
        user->supporterRatingScore = calRatingScore(*user, type);
    }
    else if (type == 3)
    {
        user->hostRatingScore = calRatingScore(*user, type);
    }
}

// Method to set rating score
void setRatingScore(User user, int type, double score)
{
    if (type == 1)
    {
        user.skillRatingScore = score;
    }
    else if (type == 2)
    {
        user.supporterRatingScore = score;
    }
    else if (type == 3)
    {
        user.hostRatingScore = score;
    }
}

// TODO mock - Method to set skill
void User::setSkills(const vector<string> &skills)
{
    User::skills = skills;
}

void User::addSkill(string skill)
{
    skills.push_back(skill);
}

// Method to rate supporter
void rateSupporter(User *rater, User *rated)
{
    double skillValue;
    std::string skillComment;
    std::cout << "\n";
    std::cout << "How would you rate the supporter's SKILL (1 to 5):";
    std::cin >> skillValue;
    std::cout << "\n";
    std::cout << "Your comment on the supporter's SKILL:";
    std::getline(std::cin >> std::skipws, skillComment);
    Rating ratingSkill;
    ratingSkill.setRatingID(rated->ratings.size() - 1);
    ratingSkill.setRaterID(rater->userId);
    ratingSkill.setUserID(rated->userId);
    ratingSkill.setRatingType(1);
    ratingSkill.setRatingValue(skillValue);
    ratingSkill.setComment(skillComment);
    rated->ratings.push_back(ratingSkill);
    updateRatingScore(rated, 1);

    double supporterValue;
    std::string supporterComment;
    std::cout << "\n";
    std::cout << "How would you rate the supporter overall (1 to 5):";
    std::cin >> supporterValue;
    std::cout << "\n";
    std::cout << "Your comment on the supporter overall:";
    std::getline(std::cin >> std::skipws, supporterComment);
    Rating ratingSupporter;
    ratingSupporter.setRatingID(rated->ratings.size() - 1);
    ratingSupporter.setRaterID(rater->userId);
    ratingSupporter.setUserID(rated->userId);
    ratingSupporter.setRatingType(2);
    ratingSupporter.setRatingValue(supporterValue);
    ratingSupporter.setComment(supporterComment);
    rated->ratings.push_back(ratingSupporter);
    updateRatingScore(rated, 2);
}

// Method to rate host
void rateHost(User *rater, User *rated)
{
    double hostValue;
    std::string hostComment;
    std::cout << "\n";
    std::cout << "How would you rate the host overall (1 to 5):";
    std::cin >> hostValue;
    std::cout << "\n";
    std::cout << "Your comment on the host overall:";
    std::getline(std::cin >> std::skipws, hostComment);
    Rating ratingSkill;
    ratingSkill.setRatingID(rated->ratings.size() - 1);
    ratingSkill.setRaterID(rater->userId);
    ratingSkill.setUserID(rated->userId);
    ratingSkill.setRatingType(3);
    ratingSkill.setRatingValue(hostValue);
    ratingSkill.setComment(hostComment);
    rated->ratings.push_back(ratingSkill);
    updateRatingScore(rated, 3);
}

// Method to set rating
void User::setRatings(const vector<Rating> &rate)
{
    User::ratings = rate;
}

// Method to save user data to a file
void User::saveToFile(ofstream &file)
{
    file << userName << ":" << pwd << ":" << fullName << ":" << email << ":"
         << homeAddr << ":" << phoneNo << ":";
    for (const int &blockedUser : blocked)
    {
        file << blockedUser << ",";
    }
    file << "}";
    for (const string &skill : skills)
    {
        file << skill << ",";
    }
    file << "}" << creds << ":" << role << ":"
         << userId << ":" << skillRatingScore << ":" << supporterRatingScore << ":"
         << hostRatingScore << ":{";
    for (const Rating &rating : ratings)
    {
        file << rating.getRatingID() << ",";
    }
    file << "}" << "\n";
}

// Method to read user data from a file
void User::readFromFile(ifstream &file)
{
    // Assuming the file format is the same as the one used in saveToFile
    string line;
    getline(file, line);

    // Tokenize the line based on the delimiter ':'
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ':'))
    {
        tokens.push_back(token);
    }

    // Extract data from tokens and set the corresponding attributes
    userName = tokens[0];
    pwd = tokens[1];
    fullName = tokens[2];
    email = tokens[3];
    homeAddr = tokens[4];
    phoneNo = tokens[5];

    // Parse blocked users
    stringstream blockedStream(tokens[6]);
    string blockedUser;
    while (getline(blockedStream, blockedUser, ','))
    {
        blocked.push_back(stoi(blockedUser));
    }

    // Parse skills
    stringstream skillsStream(tokens[7]);
    string skill;
    while (getline(skillsStream, skill, ','))
    {
        skills.push_back(skill);
    }

    creds = stoi(tokens[8]);
    role = stoi(tokens[9]);
    userId = stoi(tokens[10]);
    skillRatingScore = stod(tokens[11]);
    supporterRatingScore = stod(tokens[12]);
    hostRatingScore = stod(tokens[13]);

    // Parse ratings
    stringstream ratingsStream(tokens[14]);
    string ratingId;
    while (getline(ratingsStream, ratingId, ','))
    {
        int ratingID = stoi(ratingId);
        // Create Rating object and add to ratings vector
        Rating rating;
        rating.setRatingID(ratingID);
        ratings.push_back(rating);
    }
}

// Load user data from a file
void loadDefaultData(vector<User *> &users, string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        // Create a new User object and read data from the file
        User *user = new User();
        user->readFromFile(file);
        users.push_back(user);
    }

    file.close();
}
