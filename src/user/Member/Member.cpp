#include "../User.h"
#include "../Tools/Tool.h"
#include "../../Width.h"
#include "Member.h"


/*THIS FILE CONTAINS FUNCTIONS RELATING TO MEMBER:
    - LOGIN WITH REGISTERED USERNAME AND PASSWORD
    - BLOCK OTHER MEMBER
    - SHOW INFO WITH AND WITHOUT BLOCK
    - CHANGE PASSWORD */



// method to login
bool User::loginMember(vector<User *> users, string checkUsername) {
    string checkPwd;

    cout << "Please enter registered username: ";
    cin >> checkUsername;
    User *user = findByUsername(users, checkUsername);
    if (user == nullptr) {
        cout << "Username not found\n";
        return false;
    } else {
        cout << "Please enter password: ";
        cin >> checkPwd;
        if (verifyPwd(user, &checkPwd)) {
            cout << "Login successful\n";
        } else {
            cout << "Incorrect username/password\n";
            return false;
        }
        return true;
    }
}

// TODO: Rewrite block function
// method to block member
void User::blockUser(const vector<User *>& users, User &currentUser) {
    
   string blockName;
   cout << "Enter username to block: ";
   cin >> blockName;
   
   if (findByUsername(users, blockName) == nullptr) {
       cout << "Username not found\n";
   } else {
       currentUser.blocked.push_back(blockName);
       cout << "User " << blockName << " is blocked\n";
   }
}

// method to reset password for member
void User::changePwdMember(User user, string temp) {
    string newPwd;
    cout << "Enter old password: ";
    cin >> temp;
    if (verifyPwd(user, &temp)) {
        cout << "Password verified. Please enter new password: ";
        cin >> newPwd;
        if (checkValidPwd(newPwd) == true && caseSensitiveStringCompare(newPwd, user.userName) == false)
        {
            user.setPwd(newPwd);
            cout << "Password successfully reset\n";
        }
    } else {
        cout << "Incorrect password verification\n";
    }
}

// method to show info
void User::showInfoMember()
{
    showInfoWithRating();
    cout.width(ROLE_WIDTH);
    cout << left << "Member";
    cout << endl;
    
}

// void User::showInfoMemberWithRating(vector<User *> users) {
    
// }
// method to show info with blocked
void User::showInfoWithBlock(vector<User *> users) {

    for (auto &user: users) {
        vector<int> blocks = user->getBlocked();
        bool block = false;
        for (int j: blocks) {
            if (getUserId() == j) {
                block = true;
                break;
            }
        }
        if (block) {
            continue;
        } else {
            user->showInfoMember();
        }
    }
}
