#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <sstream>
#include <ostream>
#include <istream>
#include <vector>
#include <regex>
#include "Tools/Tool.h"
#include "../Width.h"
#include "../rating/rating.h"

using namespace std;

class User {
private:
    int userID;
    string userName, pwd, fullName, email, homeAddr, phoneNo;
    bool isBlock;
    vector<int> blocked;
    vector<string> skills;
    int creds, role;
    double skillRatingScore, supporterRatingScore, hostRatingScore;
    std::vector<Rating> ratings;

    /*Rating *skillRating, *supporterRating, *hostRating;*/
public:
    // default constructor
    User();

    // Constructor
    User(string userName, string pwd, string fullName, string email, string homeAddr,
         string phoneNo, bool block, vector<string> blocked, int creds, int role, int userId,
         double skillRatingScore, double supporterRatingScore, double hostRatingScore, vector<Rating> ratings);

    // constructor used for block function
    User(const string &username);

    // method to get username
    string getUsername();

    // method to set username
    void setUsername(string username);

    // method to get password
    string getPwd();

    // method to set password
    void setPwd(string pwd);

    // method to get full name
    string getFullName();

    // method to set full name
    void setFullName(string fullName);

    // method to get email address
    string getEmail();

    // method to set email
    void setEmail(string email);

    // method to get home address
    string getHomeAddr();

    // method to set home address
    void setHomeAddr(string homeAddr);

    // method to get phone number
    string getPhoneNo();

    // method to set phone number
    void setPhoneNo(string phoneNo);

    // method to get credit points
    int getCreds();

    // method to set credit points
    void setCreds(int creds);

    /*method to get and set role
    1: Guest
    2: Member
    3: Admin*/
    int getRole();

    // method to set role
    void setRole(int role);

    // method to get blocked
    bool isBlocked();

    // method to get blocked person/people
    void getBlocked();

    // method to set block
    void setBlocked(string blocks);

    // method to get userId
    int getUserId();

    // method to set user id
    void setUserId(int id);

    // method to block user from viewing content
    void blockUser(const vector<User *> &users, User &currentUser);

    // method to show info with global width
    void showInfo();

    // method to show info with block
    void showInfoWithBlock(vector<User *> users);

    // method to show info member
    void showInfoMember();

    // method to show info admin
    void showInfoAdmin();

    // method to top up credit points with pwd authorization
    int topUpCreds(User user, int topUp);

    // method to reset password for member
    void changePwdMember(User user, string temp);

    // method to change password for admin
    void changePwdAdmin(const vector<User *> &users, string username);

    // method to login for member
    bool loginMember(vector<User *> users, string checkUsername);

    // method to login for admin
    bool loginAdmin(const vector<User *> &users, string checkUsername);

    // method to showinfo without rating score
    void showInfoWithoutRating(vector<User *> users);

    // method to compare strings (case-insensitive)
    friend bool caseInsensitiveStringCompare(const string &str1, const string &str2);

    // method to compare strings (case-sensitive)
    friend bool caseSensitiveStringCompare(const string &str1, const string &str2);

    // method to check valid username
    friend bool checkValidUsername(vector<User *> users, string userName);

    // method to check valid email
    friend bool checkValidEmail(const vector<User *> &users, const string &email);

    // method to check valid phone number
    friend bool checkValidPhoneNo(vector<User *> users, string phoneNo);

    // method to check valid password
    friend bool checkValidPwd(string pwd);

    // method to verify password
    friend bool verifyPwd(User user, const string &pwd);

    // method to find user through username
    friend User *findByUsername(const vector<User *> &users, const string &username);

    // method to find user through id
    friend User *findById(const vector<User *> &users, int targetId);

    // Method to get user ratings
    const vector<Rating> &getRatings() const;

    // Method to count number of rating
    friend int countRatings(const User &user, int type);

    // Method to calculate rating score
    friend double calRatingScore(const User &user, int type);

    // Method to set rating score
    friend void setRatingScore(User user, int type, double score);

    // Method to show member info with rating
    // void User::showInfoMemberWithRating(vector<User *> users);

    //method to show all info (including password and rating) 
    void showAllInfo();

    // Method to show info with rating
    void showInfoWithRating();
    // Method to update user rating
    friend void updateRatingScore(User user, int type);

    // Method to get host rating
    double getHostRating() const;

    // Method to get skill rating
    double getSkillRating() const;

    // Method to get supporter rating
    double getSupporterRating() const;

    // Method to get skill
    vector<string> getSkillList();
};

// method to register user
User registerMember(vector<User *> &users, User currentUser);

// method to check valid username
bool checkValidUsername(vector<User *> users, string userName);

// method to check valid email
bool checkValidEmail(const vector<User *> &users, const string &email);

// method to check valid phone number
bool checkValidPhoneNo(vector<User *> users, string phoneNo);

// method to check valid password
bool checkValidPwd(string pwd);

// method to verify password
bool verifyPwd(User user, const string &pwd);

// method to find user through username
User *findByUsername(const vector<User *> &users, const string &username);

// method to find user by if
User *findById(const vector<User *> &users, const int targetId);

// method to find member through username
User *findMemberByUsername(const vector<User *> &users, const string &username);

// method to find admin through username
User *findAdminByUsername(const vector<User *> &users, const string &username);
