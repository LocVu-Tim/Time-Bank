# Software Engineering Design, Advanced Programming Techniques_Final Group Assessment

## Project Files
- [GitHub Repository]()
- [UML Class Diagram]()
- [Report Paper]()

## Project Contribution
| Student Name and Snumber         | Contribution  | Role and Task                   |
| ---------------- |-------------------------|--------------------------------------|
|Vu Loc - s3891483 | 25%                     |Interface designer and supporter          | 
|Van Hong Lam - s3927082 | 25%                     | Responsible for Request funcitons |
|Luong Anh Huy - s3979199| 25%                      |  Responsible for Users funcitons                |
|Tran Tuan Minh - s3978609| 25%                      |  Responsible for Rating funcitons               |

## Project Detail
Time Bank project was for EEET2482 Software Engineering Design at RMIT University Vietnam semester 2023C
- Saigon South Campus (SGS) in Vietnam
- Lecturer: Mr. Tran Duc Linh
- Started date: Dec. 15, 2023
- Finished date: 21/1/2024

### Project Description
Time Banking is a community-building concept that facilitates the exchange of services between members in the application with credit as currency exchange instead of money. The application allows people to support each other in daily activities like plumbing repairs, tutoring, garden care, house clearning, etc...


### Project IDE
- Visual Studio Code 2023
- Visual Studio
- Intellij CLion

### Project Structure
```bash
.
└── src/
    ├── database/
    │   └── request.dat
    ├── rating/
    │   ├── rating.cpp
    │   └── rating.h
    ├── request/
    │   ├── controller/
    │   │   ├── RequestController.cpp
    │   │   └── RequestController.h
    │   ├── model/
    │   │   ├── RequestModel.cpp
    │   │   ├── RequestModel.h
    │   │   ├── UserRequest.h
    │   │   ├── fileUtility.cpp
    │   │   ├── userRequest.cpp
    │   │   └── userRequest.h
    │   ├── view/
    │   │   ├── RequestView.cpp
    │   │   └── RequestView.h
    │   ├── Request.h
    │   ├── request.cpp
    │   ├── request.exe
    │   └── request.h
    ├── user/
    │   ├── Admin/
    │   │   └── Admin.cpp
    │   ├── Guest/
    │   │   └── Guest.cpp
    │   ├── Member/
    │   │   └── Member.cpp
    │   ├── Tools/
    │   │   ├── Tool.cpp
    │   │   └── Tool.h
    │   ├── User.cpp
    │   └── User.h
    ├── userInterface/
    │   ├── admin.cpp
    │   ├── guest.cpp
    │   └── member.cpp
    ├── welcomeInterface/
    │   ├── adminDetail.dat
    │   ├── memberDetail.dat
    │   ├── welcomeInterface.cpp
    │   └── welcomeInterface.h
    ├── main.cpp
    ├── main.exe
    └── request.dat

```

## Test Accounts
Admin
```bash
username: admin1
password: admin123
```
Members
```bash
username: user1
password: user123
```
## Acknowledgement
[1] _sharma_  “Check if the given email address is valid or not in C++”, GeeksforGeeks. Accessed: Jan. 21, 2024. [Online]. Available at: https://www.geeksforgeeks.org/check-if-given-email-address-is-valid-or-not-in-cpp/ 

[2] https://chat.openai.com/ 

[3] https://claude.ai/ 

[4] “Learn C++ Programming”. Accessed: Jan. 21, 2024.[Online]. Available at: https://www.programiz.com/cpp-programming 

[5] “C++ Tutorial”. Accessed: Jan. 21, 2024. [Online]. Available at: https://www.w3schools.com/cpp/default.asp 

[6] “Learn C++ – Skill up with our free tutorials”. Accessed: Jan. 21, 2024. [Online]. Available at: https://www.learncpp.com/#google_vignette 

[7] “C++ Tutorial”. Accessed: Jan. 21, 2024. [Online]. Available at: https://www.tutorialspoint.com/cplusplus/index.htm 

[8] “C++ Programming Language”, GeeksforGeeks. Accessed: Jan. 21, 2024. [Online]. Available at: https://www.geeksforgeeks.org/c-plus-plus/ 

[9] “cplusplus” Accessed: Jan. 21, 2024. [Online]. Available at: https://cplusplus.com/reference/ 

