#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "welcomeInterface.h"

using namespace std;
void menu();
void welcomeInterface()
{
	int choice;

	// Welcome Interface//
	cout << "" << endl;
	cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
	cout << "''Time BANK'' APPLICATION" << endl;
	cout << "" << endl;
	cout << "Instructor: Mr. Tran Duc Linh" << endl;
	cout << "Group: 18" << endl;
	cout << "s3891483 | Vu Loc" << endl;
	cout << "s3927082 | Van Hong Lam " << endl;
	cout << "s3979199 | Luong Anh Huy" << endl;
	cout << "s3978609 | Tran Tuan Minh" << endl;
	cout << "" << endl;
	menu();
}

void menu()
{
	int choice;
	bool running = true;

	User currentUser;
	vector<User *> users;
	// Vector to store user objects

	// Create and add two admin users
	User *admin1 = new User("admin1", "admin123", "Admin One", "admin1@example.com", "HO CHI MINH", "0987654321", {}, {"c++", "python", "java"}, 100, 3, 1, 4.5, 4.6, 4.7, {});
	User *admin2 = new User("admin2", "admin456", "Admin Two", "admin2@example.com", "HA NOI", "0123456789", {}, {"c", "python", "java"}, 150, 3, 2, 4.6, 4.7, 4.8, {});

	// Add admin users to the vector
	users.push_back(admin1);
	users.push_back(admin2);

	// Create and add seven regular users
	User *user1 = new User("user1", "user123", "User One", "user1@example.com", "Ho Chi Minh", "0765987325", {}, {"c#", "java"}, 50, 2, 3, 3.3, 4.4, 5.5, {});
	User *user2 = new User("user2", "user456", "User Two", "user2@example.com", "Ha Noi", "0234456098", {}, {"c++", "python"}, 30, 2, 4, 1.1, 2.2, 3.3, {});
	User *user3 = new User("user3", "user789", "User Three", "user3@example.com", "hochiminh", "0234987098", {}, {"c", "java"}, 75, 2, 5, 3.0, 4.0, 5.0, {});
	User *user4 = new User("user4", "user101", "User Four", "user4@example.com", "hanoi", "0876543321", {}, {"python", "java"}, 40, 2, 6, 4.9, 3.9, 2.9, {});
	User *user5 = new User("user5", "user111", "User Five", "user5@example.com", "hcm", "0321345890", {}, {"c", "java"}, 60, 2, 7, 3.8, 4.5, 3.9, {});
	User *user6 = new User("user6", "user121", "User Six", "user6@example.com", "hOcHiMinh", "0123780923", {}, {"c#"}, 20, 2, 8, 2.3, 3.5, 4.5, {});
	User *user7 = new User("user7", "user131", "User Seven", "user7@example.com", "HA Noi", "0678345123", {}, {"c"}, 90, 2, 9, 1.9, 2.8, 4.9, {});

	// Add regular users to the vector
	users.push_back(user1);
	users.push_back(user2);
	users.push_back(user3);
	users.push_back(user4);
	users.push_back(user5);
	users.push_back(user6);
	users.push_back(user7);

	// currentUser = registerMember(users, currentUser);
	// currentUser.showInfoWithoutRating(users);
	// memberLogin(users, currentUser);

	while (running)
	{
		cout << "" << endl;
		cout << "**************************************************" << endl;
		cout << "************ WELCOME TO TIME BANK ****************" << endl;
		cout << "Use the app as: " << endl;
		cout << "1. Admin" << endl;
		cout << "2. Member" << endl;
		cout << "3. Guest" << endl;
		cout << "Enter Your Choice: ";

		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input! Please enter a number."
				 << "\n";
			continue;
			continue;
		}

		switch (choice)
		{
		case 1:
			adminLogin(users, currentUser);
			break;
		case 2:
			memberLogin(users, currentUser);
			break;
		case 3:
			Guest(users);
			break;
		case 0:
			running = false;
			cout << "Exiting the application." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	}
}

void Admin(vector<User *> &users, User &currentUser)
{
	int choice;
	bool running = true;

	while (running)
	{
		cout << "\nAdmin menu\n";
		cout << "1.View admin information\n";
		cout << "2.Reset member password\n";
		cout << "3.Back to main menu\n";
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			menu();
			break;
		case 2:
			menu();
			break;
		case 3:
			menu();
			break;

		case 0:
			running = false;
			cout << "Exiting the application." << endl;
			break;
		default:
			cout << "Invalid choice!"
				 << "\n";
			break;
		}
	}
}

void adminLogin(vector<User *> &users, User &currentUser)
{
	string aName;
	bool loginSuccessful = false;

	do
	{
		User *loginAdmin = currentUser.loginAdmin(users);
		if (loginAdmin != nullptr)
		{
			currentUser = *loginAdmin;
			// print admin info
			currentUser.showInfo();
			Admin(users, currentUser);
			loginSuccessful = true;
		}
		else
		{
			cout << "Login Error\n";
			cout << "Enter username again: ";
			cin >> aName;
		}
	} while (!loginSuccessful);
}

void Member(vector<User *> &users, User &currentUser)
{
	int choice;
	bool running = true;
	int skill;
	// database
	RequestModel rm;
	RequestView rv;
	RequestController rc(rm, rv);

	// load data from file
	rm.load();
	rc.setUser(&currentUser);
	rc.setUserList(users);

	while (running)
	{
		cout << "\nMember Menu" << endl;
		cout << "1. View Information" << endl;
		cout << "2. Add Skills" << endl;
		/*cout << "3. List as Supporter" << endl;
		  cout << "4. View Supporters" << endl;
		  cout << "5. View Requests" << endl;*/
		cout << "3. Manage Your Requests" << endl;
		cout << "4. Block Member" << endl;
		cout << "5. Back to Main Menu" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			currentUser.showAllInfo();
			break;
		case 2:
			bool skillBool = true;
			while (skillBool)
			{
				cout << "List of skills:\n";
				cout << "1. Plumbing repairs\n";
				cout << "2. Tutoring\n";
				cout << "3. Garden care\n";
				cout << "4. House cleaning\n";
				cout << "Please choose your skill: ";
				switch (skill)
				{
				case 1:
					currentUser.addSkill("Plumbing repairs");
					skillBool = false;
					break;
				case 2:
					currentUser.addSkill("Tutoring");
					skillBool = false;
					break;
				case 3:
					currentUser.addSkill("Garden care");
					skillBool = false;
					break;
				case 4:
					currentUser.addSkill("House cleaning");
					skillBool = false;
					break;
				default:
					cout << "Invalid choice\n";
					break;
				}
			}
			break;
		case 3:
			rc.selectAvailableFunction();
			break;
		case 4:
			currentUser.blockUser(users, currentUser);
			break;
		case 5:
			break;
		case 0:
			running = false;
			cout << "Exiting the application." << endl;
			break;
		default:
			cout << "Invalid choice!"
				 << "\n";
			break;
		}
	}
}

// TODO not sure
void memberLogin(vector<User *> &users, User &currentUser)
{
	string mName;
	bool loginSuccessful = false;

	do
	{
		User *loginUser = currentUser.loginMember(users);
		if (loginUser != nullptr)
		{
			currentUser = *loginUser;
			/* currentUser.setUsername(mName);
			 currentUser.setPwd(findByUsername(users, mName)->getPwd());*/
			// User *foundUser = findMemberByUsername(users, currentUser.getUsername());
			// if (foundUser != nullptr)
			// {
			//     currentUser = *foundUser;
			//     Member(users, currentUser);
			//     loginSuccessful = true;
			// }
			// else
			// {
			//     cout << "Error: User not found\n";
			// }
			cout << mName << endl;
			cout << "set name " << currentUser.getUsername() << currentUser.getPwd() << endl;
			Member(users, currentUser);
			loginSuccessful = true;
		}
		else
		{
			cout << "Login error\n";
		}

	} while (!loginSuccessful);
}

void Guest(vector<User *> &users)
{

	int choice;
	cout << "1. View supporters\n";
	cout << "2. Register member\n";
	cout << "3. Back to main menu\n";
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		menu();
		break;
	case 2:
		menu();
		break;
	case 3:
		menu();
		break;
	default:
		cout << "Invalid choice!"
			 << "\n";
		break;
	}
}
bool defaultData = false;

// ARCHIVE
// Create a test user
// User usertoTest = registerMember(userList);

// User *relUser = &usertoTest;
// rc.setUser(relUser);
//     User* user = new User();
//     User* toBeBlocked = new User();
//     User* jao = *&toBeBlocked;
//     jao->setUsername("jao");
//     jao->setUserId(11);
//     // Normal one
//     User* testUser = *&user;
//     testUser->setUsername("usefalcuty");
//     testUser->setUserId(12);
//     // TODO: finish this
// //    testUser->();
//     // Another one
//     User* testUser2 = new User();
//     testUser2->setUsername("usefalcuty2");
//     testUser2->setUserId(13);

//     testUser->setBlocked(jao->getUserId());
//     // set skills
//     testUser->setSkills({ "C++", "Java", "Python" });
//     testUser2->setSkills({ "C++", "Java", "Python" });
//     jao->setSkills({ "C++", "Java", "Python" });
//     vector<User*> userList = { testUser, testUser2, jao };

//     int choice;
//     cout << "enter 0 to 2 to test the user in function:" << endl;
//     cin >> choice;
//     rc.setUser(userList[choice]);
//     rc.setUserList(userList);