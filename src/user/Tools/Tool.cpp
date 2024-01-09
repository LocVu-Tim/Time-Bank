#include "Tool.h"

// method to compare strings (case insensitive)
bool caseInsensitiveStringCompare(const string &str1, const string &str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    for (int i = 0; i < str1.length(); i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            return false;
        }
    }
    return true;
}

// method to compare strings (case sensitive)
bool caseSensitiveStringCompare(const string &str1, const string &str2)
{
    if (str1.compare(str2) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}