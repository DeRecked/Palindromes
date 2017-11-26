// palindromeR.hpp -- recursive palindrome tester
// c. 2015 A. Deeter

#ifndef PALINDROMER_HPP
#define PALINDROMER_HPP

#include <iostream>
#include <string>

using namespace std;

class PalindromeR 
{

public:
  PalindromeR() {}
  int test_string(const string& s);
  int test_char(const string& s, int left, int right);
};

#endif
