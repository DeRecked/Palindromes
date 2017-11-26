#include "PalindromeR.hpp"

int PalindromeR::test_string(const string& s)
{   
    int front = 0;                                              // Points to front of string
    int end = s.length() - 1;                                   // Poiunts to end of string
     
    return test_char(s, front, end);                            // Initial call to recursive function
}

int PalindromeR::test_char(const string& s, int left, int right)
{
    char leftChar = tolower(s[left]);                           // Hold first and last values of string,
    char rightChar = tolower(s[right]);                         // converted to lowercase

    if ((right-left) < 1)                                       // If one or less characters remain,
        return -1;                                              // it is a palindrome and return -1 for success
    else if (leftChar == rightChar)                             // If chars match
        return test_char(s, ++left, --right);                   //     call recursive function with left+1 and right+1
    else                                                        // If chars do not match
    {                 
        if (leftChar < 'a' || leftChar > 'z')                 //     Test to see if only front char is non-alphanumeric
            return test_char(s, ++left, right);                 //         Call recursive function with left+1
        else if (rightChar < 'a' || rightChar > 'z')                //     Test to see if only end char is non-alphanumeric
            return test_char(s, left, --right);                 //         Call recursive function with right-1
        else return 1;                                          //     Otherwise, thie is not a palindrome; return 1
    }
}
