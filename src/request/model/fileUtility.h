// header guard
#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H
// This is for the file utility functions
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "./userRequest.h"
#define FILENAME "request.dat"

using namespace std;

class fileUtility
{
public:
    fileUtility()
    {
    }
    void writeToFile(userRequest *request);
    void loadFromFile(vector<userRequest *> &requestList);
    void modifyFile(vector<userRequest *> &requestList);
    // void updateFile(vector<userRequest *> &requestList);
};

#endif // FILE_UTILITY_H