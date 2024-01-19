#ifndef TIME_BANK_WELCOMEINTERFACE_H
#define TIME_BANK_WELCOMEINTERFACE_H
// #include "../main.cpp"
#include "../user/User.h"
#include "../user/Admin/Admin.h"
#include "../user/Guest/Guest.h"
#include "../user/Member/Member.h"
#include "../user/Tools/Tool.h"
// #include "../welcomeInterface/welcomeInterface.cpp"
#include "../request/request.h"
#include "../request/controller/RequestController.h"
#include "../request/view/RequestView.h"
#include "../request/model/RequestModel.h"
#include <vector>

void Guest();
void Member();
void Admin();
void adminLogin();
void welcomeInterface();
// void memberLogin();
#endif // TIME_BANK_WELCOMEINTERFACE_H