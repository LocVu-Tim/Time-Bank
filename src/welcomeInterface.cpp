#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void Guest();
void Member();
void Admin();

main(){
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

    cout <<"**************************************************"<<endl;
    cout <<"************WELCOME TO TIME BANK******************"<<endl;
    cout <<"Use the app as: "<<endl;
    cout<<"1. Guest"<<endl;
    cout<<"2. Member"<<endl;
    cout<<"3. Admin"<<endl;
    cout<<"Enter Your Choice: ";

    cin >>choice;
    cout <<endl;

    switch(choice){
        case 1:
            Guest();
            break;
        case 2:
            Member();
            break;
        case 3:
            Admin();
            break;
    }

}

void Guest(){
    int count;
    string gName,gPass,gN,gP;
    system("cls");
    cout <<"Enter username: ";
    cin >> gName;
    cout<<"Enter password: ";
    cin >> gPass;

    ifstream input("loginDetails.txt");
    while(input>>gN>>gP){
        if(gN==gName && gP==gPass){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"Login Successful";
        cin.get();
        main();
    }
    else{
        cout<<"Login Error \nPlease check your details"<<endl;
        main();
    }
}

void Member(){
    int count;
    string mName,mPass,mN,mP;
    system("cls");
    cout <<"Enter username: ";
    cin >> mName;
    cout<<"Enter password: ";
    cin >> mPass;

    ifstream input("loginDetails.txt");
    while(input>>mN>>mP){
        if(mN==mName && mP==mPass){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"Login Successful";
        cin.get();
        main();
    }
    else{
        cout<<"Login Error \n Please check your details"<<endl;
        main();
    }
}

void Admin(){
    int count;
    string aName,aPass,aN,aP;
    system("cls");
    cout <<"Enter username: ";
    cin >> aName;
    cout<<"Enter password: ";
    cin >> aPass;

    ifstream input("loginDetails.txt");
    while(input>>aN>>aP){
        if(aN==aName && aP==aPass){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"Login Successful";
        cin.get();
        main();
    }
    else{
        cout<<"Login Error \n Please check your details"<<endl;
        main();
    }
}