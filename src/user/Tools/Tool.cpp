#include "Tool.h"
#include "../User.h"

/*THIS FILE CONTAINS THE SET OF FUNCTIONS TO COMPARE STRINGS 
- CASE INSENSITIVE: NO NEED PERFECT MATCH, CONVERT TO LOWER THEN COMPARE
- CASE SENSITIVE: EXACT MATCH */


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

