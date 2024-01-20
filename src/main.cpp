#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
// #include "user/Admin/Admin.h"
// #include "user/Guest/Guest.h"
// #include "user/Member/Member.h"
// #include "user/Tools/Tool.h"
#include "./welcomeInterface/welcomeInterface.h"


int main() {
    //vector<User*> users;
    //User currentUser;
    //// Vector to store user objects

    //// Create and add two admin users
    //User* admin1 = new User("admin1", "admin123", "Admin One", "admin1@example.com", "HO CHI MINH", "0987654321", {}, { "c++", "python", "java" }, 100, 3, 1, 4.5, 4.6, 4.7, {});
    //User* admin2 = new User("admin2", "admin456", "Admin Two", "admin2@example.com", "HA NOI", "0123456789", {}, { "c", "python", "java" }, 150, 3, 2, 4.6, 4.7, 4.8, {});

    //// Add admin users to the vector
    //users.push_back(admin1);
    //users.push_back(admin2);

    //// Create and add seven regular users
    //User* user1 = new User("user1", "user123", "User One", "user1@example.com", "Ho Chi Minh", "0765987325", {}, { "c#",  "java" }, 50, 2, 3, 3.3, 4.4, 5.5, {});
    //User* user2 = new User("user2", "user456", "User Two", "user2@example.com", "Ha Noi", "0234456098", {}, { "c++", "python" }, 30, 2, 4, 1.1, 2.2, 3.3, {});
    //User* user3 = new User("user3", "user789", "User Three", "user3@example.com", "hochiminh", "0234987098", {}, { "c",  "java" }, 75, 2, 5, 3.0, 4.0, 5.0, {});
    //User* user4 = new User("user4", "user101", "User Four", "user4@example.com", "hanoi", "0876543321", {}, { "python", "java" }, 40, 2, 6, 4.9, 3.9, 2.9, {});
    //User* user5 = new User("user5", "user111", "User Five", "user5@example.com", "hcm", "0321345890", {}, { "c", "java" }, 60, 2, 7, 3.8, 4.5, 3.9, {});
    //User* user6 = new User("user6", "user121", "User Six", "user6@example.com", "hOcHiMinh", "0123780923", {}, { "c#" }, 20, 2, 8, 2.3, 3.5, 4.5, {});
    //User* user7 = new User("user7", "user131", "User Seven", "user7@example.com", "HA Noi", "0678345123", {}, { "c" }, 90, 2, 9, 1.9, 2.8, 4.9, {});

    //// Add regular users to the vector
    //users.push_back(user1);
    //users.push_back(user2);
    //users.push_back(user3);
    //users.push_back(user4);
    //users.push_back(user5);
    //users.push_back(user6);
    //users.push_back(user7);

    // currentUser = registerMember(users, currentUser);
    // currentUser.showInfoWithoutRating(users);
    // memberLogin(users, currentUser);
    welcomeInterface();

//     // Initialize or reload default data
//     // fstream myUserFile;
//     // string userFile = "user.dat";
//     // vector<User *> users = {};

//     if (defaultData) //if there's no default data then create and initialize default data using dynamic memory allocation
//     {
//         User *admin1 = new(std::nothrow) User(1, "admin1", "password1", "John Doe", "john@example.com", "123 Main St",
//                                               "0123456789", false, {}, 20, 2, 0, 0, 0, {});
//         User *admin2 = new(std::nothrow) User(2, "admin2", "password2", "Jane Doe", "jane@example.com", "456 Oak St",
//                                               "0213645987", false, {}, 20, 2, 0, 0, 0, {});
//         User *user1 = new(std::nothrow) User(3, "user1", "password3", "Bob Doe", "bob@example.com", "234 Wall St",
//                                              "0345671298", false, {}, 20, 2, 0, 0, 0, {});
//         User *user2 = new(std::nothrow) User(4, "user2", "password4", "Bob Smith", "smith@example.com", "234 Oak St",
//                                              "0498765298", false, {}, 20, 2, 0, 0, 0, {});
//         User *user3 = new(std::nothrow) User(5, "user3", "password5", "John Smith", "jsmtih@example.com", "456 Main St",
//                                              "0512345678", false, {}, 20, 2, 0, 0, 0, {});
//         User *user4 = new(std::nothrow) User(6, "user4", "password6", "Bob Dover", "dover@example.com", "789 Greens St",
//                                              "0648395023", false, {}, 20, 2, 0, 0, 0, {});
//         User *user5 = new(std::nothrow) User(7, "user5", "password7", "Peter Smith", "peter@example.com",
//                                              "123 Greens St", "0712312345", false, {}, 20, 2, 0, 0, 0, {});
//         User *user6 = new(std::nothrow) User(8, "user6", "password8", "Peter Parker", "parker@example.com",
//                                              "345 Brooklyn St", "0898745631", false, {}, 20, 2, 0, 0, 0, {});
//         User *user7 = new(std::nothrow) User(9, "user7", "password9", "Harry Bon", "bon@example.com", "123 Oak St",
//                                              "0923784590", false, {}, 20, 2, 0, 0, 0, {});
//         User *user8 = new(std::nothrow) User(10, "popo", "12313", "Boby Spark", "sth@gmail.com", "752 Sth Street",
//                                              "9812411", false, {}, 20, 2, 0, 0, 0, {});
 

//         admin1->setRole(3);
//         admin2->setRole(3);
//         user1->setRole(2);
//         user2->setRole(2);
//         user3->setRole(2);
//         user4->setRole(2);
//         user5->setRole(2);
//         user6->setRole(2);
//         user7->setRole(2);

//         users = {admin1, admin2, user1, user2, user3, user4, user5, user6, user7};

//     } else {
//         // Open user file
//         myUserFile.open("user.dat", std::ios::in);

//         if (!myUserFile.is_open()) {
//             cout << "Failed to open user.dat file \n";
//         }

//         /* Reload users' data from the file */
//         string userIdData, usernameData, pwdData, fullNameData, emailData, homeAddrData, phoneNoData, credsData, ratingScoreData, roleData;

//     //     vector<User *> userReload = {};

//         while (!myUserFile.eof()) {
//             userIdData = "", usernameData = "", pwdData = "", fullNameData = "", emailData = "", homeAddrData = "", phoneNoData = "", credsData = "", ratingScoreData = "", roleData = "";

//     //         //read data from .dat file
//     //         getline(myUserFile, userIdData, ':'); //getline using delimiter
//     //         getline(myUserFile, usernameData, ':');
//     //         getline(myUserFile, pwdData, ':');
//     //         getline(myUserFile, fullNameData, ':');
//     //         getline(myUserFile, emailData, ':');
//     //         getline(myUserFile, homeAddrData, ':');
//     //         getline(myUserFile, phoneNoData, ':');
//     //         getline(myUserFile, credsData, ':');
//     //         getline(myUserFile, ratingScoreData, ':');
//     //         getline(myUserFile, roleData, ':');

//             if (userIdData == "" || userIdData == "\n") {
//                 break;
//             }
// //            User *userData = new (std::nothrow) User(stoi(userIdData), usernameData, pwdData, fullNameData, emailData, homeAddrData, phoneNoData, stoi(credsData), stoi(ratingScoreData));
// //            userData->setRole(stoi(roleData));
// //            userReload.push_back(userData);
//         }
//         myUserFile.close();
//     }


//     // Save user data to file
//     myUserFile.open("user.dat", std::ios::out);
//     if (!myUserFile) {
//         cout << "Fail to create/open file \n";
//     }


//    //Save data to user.dat with delimiter :
//    for(auto user: users) {
//        myUserFile << user->getUserId() << ":" << user->getUsername() << ":" << user->getPwd() << ":" << user->getFullName() << ":" << user->getEmail() << ":" << user->getHomeAddr() << ":" << user->getPhoneNo() << ":"<< user->getCreds() << ":" << user->getRatingScore() << ":" << user->getRole() << ":" << endl;
//    }

    // myUserFile.close();
    return 0;
}
