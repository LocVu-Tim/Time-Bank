#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "user/Admin/Admin.cpp"
#include "user/Guest/Guest.cpp"
#include "user/Member/Member.cpp"
#include "user/Tools/Tool.h"
#include "./welcomeInterface/welcomeInterface.cpp"
#include "user/User.h"

bool defaultData = false;

int main()
{
    welcomeInterface();

    // Initialize or reload default data 
    fstream myUserFile;
    string userFile = "user.dat";
    vector<User *> users = {};

    if (defaultData) //if there's no default data then create and initialize default data using dynamic memory allocation
    {
        User *admin1 = new (std::nothrow) User(1, "admin1", "password1", "John Doe", "john@example.com", "123 Main St",  "0123456789", 20, 4);
        User *admin2 = new (std::nothrow) User(2, "admin2", "password2", "Jane Doe", "jane@example.com", "456 Oak St", "0213645987", 20, 3);
        User *user1 = new (std::nothrow) User(3, "user1", "password3", "Bob Doe", "bob@example.com", "234 Wall St", "0345671298", 20, 5);
        User *user2 = new (std::nothrow) User(4, "user2", "password4", "Bob Smtih", "smith@example.com", "234 Oak St", "0498765298", 20, 4);
        User *user3 = new (std::nothrow) User(5, "user3", "password5", "John Smtih", "jsmtih@example.com", "456 Main St", "0512345678", 20, 4);
        User *user4 = new (std::nothrow) User(6, "user4", "password6", "Bob Dover", "dover@example.com", "789 Greens St", "0648395023", 20, 3);
        User *user5 = new (std::nothrow) User(7, "user5", "password7", "Peter Smtih", "peter@example.com", "123 Greens St", "0712312345", 20, 2);
        User *user6 = new (std::nothrow) User(8, "user6", "password8", "Peter Parker", "parker@example.com", "345 Brooklyn St", "0898745631", 20, 4);
        User *user7 = new (std::nothrow) User(9, "user7", "password9", "Harry Bon", "bon@example.com", "123 Oak St", "0923784590", 20, 2);

        admin1->setRole(3);
		admin2->setRole(3);
		user1->setRole(2);
		user2->setRole(2);
		user3->setRole(2);
		user4->setRole(2);
		user5->setRole(2);
		user6->setRole(2);
		user7->setRole(2);

        users = { admin1, admin2, user1, user2, user3, user4, user5, user6, user7 };


    } else {
        // Open user file
		myUserFile.open("user.dat", std::ios::in);

		if(!myUserFile.is_open()) {
            cout << "Failed to open user.dat file \n";
        }

		/* Reload users' data from the file */
        string userIdData, usernameData, pwdData, fullNameData, emailData, homeAddrData, phoneNoData, credsData, ratingScoreData, roleData;

        vector<User *> userReload = {};

        while(!myUserFile.eof()) {
            userIdData = "", usernameData = "", pwdData = "", fullNameData = "", emailData = "", homeAddrData = "", phoneNoData = "", credsData = "", ratingScoreData = "", roleData = "";

            //read data from .dat file 
            getline(myUserFile, userIdData, ':'); //getline using delimiter
            getline(myUserFile, usernameData, ':');
            getline(myUserFile, pwdData, ':');
            getline(myUserFile, fullNameData, ':');
            getline(myUserFile, emailData, ':');
            getline(myUserFile, homeAddrData, ':');
            getline(myUserFile, phoneNoData, ':');
            getline(myUserFile, credsData, ':');
            getline(myUserFile, ratingScoreData, ':');
            getline(myUserFile, roleData, ':');

            if(userIdData == "" || userIdData == "\n") {
                break;
            }

            User *userData = new (std::nothrow) User(stoi(userIdData), usernameData, pwdData, fullNameData, emailData, homeAddrData, phoneNoData, stoi(credsData), stoi(ratingScoreData));
            userData->setRole(stoi(roleData));
            userReload.push_back(userData);
        }     
        myUserFile.close();


    }




    // Save user data to file
	myUserFile.open("user.dat", std::ios::out);
	if (!myUserFile) {
		cout << "Fail to create/open file \n";
	}


    //Save data to user.dat with delimiter : 
    for(auto user: users) {
        myUserFile << user->getUserId() << ":" << user->getUsername() << ":" << user->getPwd() << ":" << user->getFullName() << ":" << user->getEmail() << ":" << user->getHomeAddr() << ":" << user->getPhoneNo() << ":"<< user->getCreds() << ":" << user->getRatingScore() << ":" << user->getRole() << ":" << endl;
    }

    myUserFile.close();
    return 0;
}
