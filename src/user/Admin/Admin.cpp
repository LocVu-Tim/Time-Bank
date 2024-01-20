#include "../User.h"
#include "../Tools/Tool.h"

/*THIS FILE CONTAINS FUNCTIONS RELATING TO ADMIN:
    - LOGIN WITH PREDEFINED USERNAME AND PASSWORD
    - SHOW INFO
    - RESET PASSWORD */

// method to login
bool User::loginAdmin(const vector<User *> &users, string checkUsername)
{
    string checkPwd;
    cout << "--------------Login--------------" << endl;

    cout << "Please enter predefined username: ";

    cin >> checkUsername;
    User *user = findByUsername(users, checkUsername);
    if (user == nullptr)
    {
        return false;
    }
    else
    {
        cout << "Please enter password: ";
        cin >> checkPwd;
        if (verifyPwd(*user, checkPwd))
        {
            cout << "Login successful\n";
        }
        else
        {
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
void User::changePwdAdmin(const vector<User *> &users, string username)
{
    string reset;
    bool checkPwd = false;
    bool checkName = false;
    

    // Use a do-while loop to ensure it runs at least once
    do
    {
        if (findByUsername(users, username) != nullptr)
        {
            cout << "Successfully found user. Please enter new password: ";
            cin >> reset;

            do
            {
                if (checkValidPwd(reset) == true)
                {
                    findByUsername(users, username)->setPwd(reset); // Fix: use the user pointer, not uninitialized pointer
                    cout << "Password successfully reset\n";
                    checkPwd = true;
                }
                else
                {
                    cout << "Invalid password format. Please try again: ";
                    cin >> reset;
                    
                }
            }while (!(checkPwd));

            break; // Update the loop condition
        }
        else
        {
            cout << "Username not found\n";
            cout << "Enter username again: ";
            cin >> username;
        }
    } while (!(checkName));
}