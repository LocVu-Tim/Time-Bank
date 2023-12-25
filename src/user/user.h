#pragma once
class User {
    private:
    string username, pwd, fullName, email, homeAddr, city, phoneNo;
    bool block;
    int creds, role;
    /*Rating *skillRating, *supporterRating, *hostRating;*/
    public:
    //default constructor
    User();
    //constructor
    User(string username, string pwd, string fullName, string email,
    string homeAddr, string city, string phoneNo, int creds);
    
    //constructor used for block function
    User(const string &username);
    //method to get username
    string getUsername(); 
    
    //method to set username
    void setUsername(string username); 

    //method to get password
    string getPwd(); 

    //method to set password
    void setPwd(string pwd); 

    //method to get city
    string getCity(); 

    //method to set city
    void setCity(string city); 

    //method to get full name
    string getFullName(); 

    //method to set full name 
    void setFullName(string fullName); 

    //method to get email address
    string getEmail(); 

    //method to set email
    void setEmail(string email); 

    //method to get home address
    string getHomeAddr(); 

    //method to set home address
    void setHomeAddr(string homeAddr); 

    //method to get phone number 
    string getPhoneNo();

    //method to set phone number
    void setPhoneNo(string phoneNo); 

    //method to get credit points
    int getCreds(); 

    //method to set credit points
    void setCreds(int creds); 

    /*method to get and set role
    1: Guest
    2: Member
    3: Admin*/
    int getRole();

    //method to set role
    void setRole(int role); 

    //method to get blocked
    bool isBlocked(); 

    
    //method to top up credit points with pwd authorization
    int topUpCreds (User user, int topUp); 
        

    //method to register to become user (for guest)
    void registerMember(vector<User *> users); 
    

    //method to reset password for member
    void changePwdMember(User user, string temp); 

    //method to change password for admin
    void changePwdAdmin(vector<User *> users, string username); 

    //method to login
    bool login(vector<User *> users, string checkUsername); 

    //method to showinfo without rating score 
    void showInfoWithoutRating(vector<User *> users); 

    //method to block user from viewing content
    string blockUser(vector<User *> users, string blocked, string blocker); 
};  

//method to compare strings (case insensitive)
bool caseInsensitiveStringCompare(const string &str1, const string &str2); 

//method to compare strings (case sensitive)
bool caseSensitiveStringCompare(const string &str1, const string &str2); 

//method to check valid username
bool checkValidUsername(vector<User *> users, string userName); 

//method to check valid email
bool checkValidEmail(vector <User *> users, string email); 
    

//method to check valid phone number 
bool checkValidPhoneNo (vector<User *> users, string phoneNo); 

//method to check valid password
bool checkValidPwd(string pwd); 

//method to verify password
bool verifyPwd(User user, string pwd); 

//method to find user thru username
User* findByUsername(const vector<User*>& users, const string& username); 


int main() {

    return 0;
}