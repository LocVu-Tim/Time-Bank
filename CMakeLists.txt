cmake_minimum_required(VERSION 3.27)
project(Time_Bank)


set(CMAKE_CXX_STANDARD 14)

# include where the std library


include_directories(src/rating)
include_directories(src/request/controller)
include_directories(src/request/model)
include_directories(src/request/view)
include_directories(src/user)

add_executable(Time_Bank
        src/rating/rating.cpp
        src/request/controller/RequestController.cpp
        src/request/model/RequestModel.cpp
        src/request/view/RequestView.cpp
        src/request/request.cpp
        src/user/user.cpp
        src/welcomeInterface/welcomeInterface.cpp
        src/user/Member/Member.cpp
        src/user/Guest/Guest.cpp
        src/user/Admin/Admin.cpp
        src/user/Tools/Tool.cpp
        src/main.cpp
        src/user/Member/Member.h
        src/request/request.h
        src/request/model/fileUtility.cpp
        src/request/model/userRequest.cpp)