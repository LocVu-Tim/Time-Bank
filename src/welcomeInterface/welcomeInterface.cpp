#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "welcomeInterface.h"
using namespace std;

void welcomeInterface(){
    int choice;

    // Welcome Interface//
    cout <<"EEET2482/COSC2082 ASSIGNMENT"<<endl;
    cout <<"''Time BANK'' APPLICATION"<<endl;
    cout <<""<<endl;
    cout <<"Instructor: Mr. Tran Duc Linh"<<endl;
    cout <<"Group: "<<endl;
    cout <<"s3891483, Vu Loc"<<endl;
    cout <<"s3927082, Van Hong Lam "<<endl;
    cout <<"s3979199, Luong Anh Huy"<<endl;
    cout <<"s3978609, Tran Tuan Minh"<<endl;
    cout <<""<<endl;
    menu();
}

void menu (){
    int choice;
    bool running = true;

    while (running) {
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

        switch(choice){
            case 1:
                adminLogin();
                
            case 2:
                Member();
                
            case 3:
                Guest();
                
        }

    }
}

void Admin(){

    int choice;
    cout << "\nAdmin menu\n";
    cout << "1.View admin information\n";
    cout << "2.Reset member password\n";
    cout << "3.Back to main menu\n";
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

void adminLogin() {
    int count;
    string aName,aPass,aN,aP;
    system("cls");
    cout <<"Enter username: ";
    cin >> aName;
    cout<<"Enter password: ";
    cin >> aPass;

    ifstream input("adminDetail.dat");
    while(input>>aN>>aP){
        if(aN==aName && aP==aPass){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"Login Successful\n"; 
        Admin();
    }
    else{
        cout<<"Login Error \n Please check your details"<<endl;
        adminLogin();
    }
   
}

void Member(){
    int choice;
    cout << "\nMember menu:\n";
    cout << "1.View information\n";
    cout << "2.Add skills\n";
    cout << "3.Listed as supporter\n";
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

void loginMember() {
    int count;
    string mName,mPass,mN,mP;
    system("cls");
    cout <<"Enter username: ";
    cin >> mName;
    cout<<"Enter password: ";
    cin >> mPass;

    ifstream input("memberDetail.txt");
    while(input>>mN>>mP){
        if(mN==mName && mP==mPass){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"Login Successful\n"; 
        cin.get();
        Member();
    }
    else{
        cout<<"Login Error \n Please check your details"<<endl;
        loginMember();
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



