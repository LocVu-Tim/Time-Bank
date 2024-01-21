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

// Function to clear input buffer until a newline character is encountered

// method to login for admin
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

// method to show admin info
void User::showInfoAdmin()
{
    // Define box characters
    char topLeft = '+', topRight = '+', bottomLeft = '+', bottomRight = '+';
    char horizontal = '-', vertical = '|';

    // Get the maximum width among the fields
    int uniformWidth = 60; // You can adjust this value based on your preference

    // Display the top of the square box
    cout << topLeft;
    for (int i = 0; i < uniformWidth + 2; i++)
    {
        cout << horizontal;
    }
    cout << topRight << endl;

    // Display each row of information in the square box
    cout << vertical << " " << setw(uniformWidth) << left << "Username: " + userName << " " << vertical << endl;
    cout << vertical << " " << setw(uniformWidth) << left << "Full Name: " + fullName << " " << vertical << endl;
    cout << vertical << " " << setw(uniformWidth) << left << "Email: " + email << " " << vertical << endl;
    cout << vertical << " " << setw(uniformWidth) << left << "Home Address: " + homeAddr << " " << vertical << endl;
    cout << vertical << " " << setw(uniformWidth) << left << "Phone Number: " + phoneNo << " " << vertical << endl;
    cout << bottomLeft;
    for (int i = 0; i < uniformWidth + 2; i++)
    {
        cout << horizontal;
    }
    cout << bottomRight << endl;
}

// method to change password for admin
void User::changePwdAdmin(const vector<User *> &users, int userId)
{
    string reset;
    bool check = true;

    do
    {
        cout << "Enter user ID for changing password (enter -1 to cancel): ";

        // Check if the input is a valid integer
        while (!(cin >> userId))
        {
            cout << "Invalid input. Please enter a valid user ID.\n";
            clearInputBuffer(); // Clear input buffer
        }

        if (userId == -1)
        {
            cout << "Password reset canceled.\n";
            break;
        }

        User *user = findById(users, userId);

        if (user == nullptr)
        {
            cout << "User ID not found. Do you want to try again? (Y/N): ";
            char tryAgain;
            cin >> tryAgain;

            if (toupper(tryAgain) != 'Y')
            {
                cout << "Password reset canceled.\n";
                break;
            }
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
    } while (check);
}
