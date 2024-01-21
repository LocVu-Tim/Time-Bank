#include "../User.h"
#include "../Tools/Tool.h"

/*THIS FILE CONTAINS FUNCTIONS RELATING TO ADMIN:
    - LOGIN WITH PREDEFINED USERNAME AND PASSWORD
    - SHOW INFO
    - RESET PASSWORD */

// // method to login
// bool User::loginAdmin(const vector<User *> &users, string checkUsername) {
//     string checkPwd;
//     cout << "--------------Login--------------" << endl;

//     cout << "Please enter predefined username: ";

//     cin >> checkUsername;
//     User *user = findByUsername(users, checkUsername);
//     if (user == nullptr) {
//         cout << "Username not found\n";
//         return false;
//     } else {
//         cout << "Please enter password: ";
//         cin >> checkPwd;
//         if (verifyPwd(*user, checkPwd)) {
//             cout << "Login successful\n";
//         } else {
//             cout << "Incorrect username/password\n";
//             return false;
//         }
//         return true;
//     }
// }
User *User::loginAdmin(const vector<User *> &users)
{
    string username;
    string password;

    cout << "Enter your admin username: ";
    cin >> username;

    // Find admin user by username
    User *adminUser = findByUsername(users, username);

    if (adminUser == nullptr)
    {
        cout << "Admin user not found. Please check your username.\n";
        return nullptr;
    }

    // Check if the found user has admin role (role 3)
    if (adminUser->getRole() != 3)
    {
        cout << "User is not an admin. Login failed.\n";
        return nullptr;
    }

    cout << "Enter your admin password: ";
    cin >> password;

    // Verify password
    if (verifyPwd(*adminUser, password))
    {
        cout << "Admin login successful!\n";
        return adminUser;
    }
    else
    {
        cout << "Incorrect password. Admin login failed.\n";
        return nullptr;
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
void User::changePwdAdmin(const vector<User *> &users, int userId)
{
    string reset;
    bool check = true;
    do
    {
        cout << "Enter user ID for changing password: ";
        cin >> userId;

        User *user = findById(users, userId);
        if (user == nullptr)
        {
            cout << "Username not found\n";
        }
        else
        {
            cout << "Successfully found user. Please enter new password: ";
            cin >> reset;
            if (checkValidPwd(reset))
            {
                user->setPwd(reset);
                cout << "Password successfully reset\n";
                check = false;
            }
        }
    } while(check);
}