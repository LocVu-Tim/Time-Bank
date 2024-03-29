#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>


using namespace std;


void menu();
void Guest();
void Member();
void Admin();
void adminLogin();
void memberLogin();

void welcomeInterface(){
    int choice;

    // Welcome Interface//
    cout <<""<<endl;
    cout <<"EEET2482/COSC2082 ASSIGNMENT"<<endl;
    cout <<"''Time BANK'' APPLICATION"<<endl;
    cout <<""<<endl;
    cout <<"Instructor: Mr. Tran Duc Linh"<<endl;
    cout <<"Group: 18"<<endl;
    cout <<"s3891483 | Vu Loc"<<endl;
    cout <<"s3927082 | Van Hong Lam "<<endl;
    cout <<"s3979199 | Luong Anh Huy"<<endl;
    cout <<"s3978609 | Tran Tuan Minh"<<endl;
    menu();
}

void menu (){
    int choice;
    bool running = true;

    while (running) {
        cout <<""<<endl;
        cout <<"**************************************************"<<endl;
        cout <<"************ WELCOME TO TIME BANK ****************"<<endl;
        cout <<"Use the app as: "<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. Member"<<endl;
        cout<<"3. Guest"<<endl;
        cout<<"Enter Your Choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();               
            cin.ignore(INT_MAX, '\n'); 
            cout << "Invalid input! Please enter a number."
                 << "\n";
            continue; 
        }

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                memberLogin();
                break;
            case 3:
                Guest();
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

void Admin(){
    int choice;
    bool running = true;

    while (running) {
        cout << "\nAdmin menu\n";
        cout << "1.Reset Member password\n";
        cout << "2.Back to main menu\n";
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: // Reset Member password
            cout << "\nChoose a Member to reset password \n";
            // View all Member information
            
                switch (choice)
                {
                case 1:
                    cout << "Member 1: "; // << TODO: username1 << "\n; //
                    // TODO: Reset Member password function
                case 2:
                    cout << "Member 2: "; // << TODO: username2 << "\n; //
                    // TODO: Reset Member password function
                    break;
                case 3:
                    cout << "Member 3: "; // << TODO: username3 << "\n"; //
                    // TODO: Reset Member password function
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

void adminLogin() {
    string aName, aPass, aN, aP;

    cout << "Enter username: ";
    cin >> aName;

    cout << "Enter password: ";
    cin >> aPass;

    ifstream adminFile("./welcomeInterface/adminDetail.dat");
    int found = 0;

    while (adminFile >> aN >> aP) {
        if (aName == aN && aPass == aP) {
            found = 1;
            break;
        }
    }

    adminFile.close();

    if (found) {
        cout << "Login Successful\n";
        Admin();
    } else {
        cout << "Login Error\n";
        adminLogin();
    }
}


void Member(){
    int choice;
    bool running = true;

    while (running) {
        cout << "\nMember Menu" << endl;
        cout << "1. View Information" << endl;
        cout << "2. Add Skills" << endl;
        cout << "3. List as Supporter" << endl;
        cout << "4. View Supporters" << endl;
        cout << "5. View Requests" << endl;
        cout << "6. Block Member" << endl;
        cout << "7. Back to Main Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: //View Information
                menu();
                break;

            case 2: //add skill
                menu();
                break;

            case 3: //list as supporter
                menu();
                break;

            case 4: //view request
                switch (choice) {
                    // choose host
                    case 1: //host 1
                        menu();
                        break;
                    case 2://host 2..
                        menu(); //your booking is received
                        //previous booked request
                        break;
                    case 3:
                        menu();
                        break;
                    case 4:
                        menu();
                        break;
                }
                menu();
                break;
            case 5:
                menu();
                break;
            case 6:
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

void memberLogin() {
    string mName,mPass,mN,mP;

    cout << "Enter username: ";
    cin >> mName;

    cout << "Enter password: ";
    cin >> mPass;

    ifstream memberFile("./welcomeInterface/memberDetail.dat");
    int found = 0;

    while (memberFile >> mN >> mP) {
        if (mName == mN && mPass == mP) {
            found = 1;
            break;
        }
    }

    memberFile.close();

    if (found) {
        cout << "Login Successful\n";
        Member();
    } else {
        cout << "Login Error\n";
        memberLogin();
    }
}

void Guest() {
    
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



