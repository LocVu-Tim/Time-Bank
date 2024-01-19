#include "../User.h"
#include "../Tools/Tool.h"


/*THIS FILE CONTAINS FUNCTIONS RELATING TO ADMIN:
    - LOGIN WITH PREDEFINED USERNAME AND PASSWORD
    - SHOW INFO
    - RESET PASSWORD */



// method to login
bool User::loginAdmin(const vector<User *>& users, string checkUsername) {
    string checkPwd;
    cout << "--------------Login--------------" << endl;

    cout << "Please enter predefined username: ";

    cin >> checkUsername;
    User *user = findByUsername(users, checkUsername);
    if (user == nullptr) {
        return false;
    } else {
        cout << "Please enter password: ";
        cin >> checkPwd;
        if (verifyPwd(*user, checkPwd)) {
            cout << "Login successful\n";
        } else {
            return false;
        }
        return true;
    }
}

// method to show info admin
void User::showInfoAdmin()
{
    showInfo();
    cout.width(ROLE_WIDTH);
    cout << left << "Admin";
    cout << endl;
}

// method to change password for admin
void User::changePwdAdmin(const vector<User *>& users, string username) {
    string reset;
    

    User *user = findByUsername(users, username);
    if (user == nullptr) {
        cout << "Username not found\n";
    } else {
        cout << "Successfully found user. Please enter new password: ";
        cin >> reset;
        if (checkValidPwd(reset)) {
            user->setPwd(reset);
            cout << "Password successfully reset\n";
        }
    }
}