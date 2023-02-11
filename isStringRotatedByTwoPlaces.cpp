// cpp program to check if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places
// Input: a = amazon, b = azonam
// Output: 1
// Input: a = geeksforgeeks, b = geeksgeeksfor
// Output: 0
// Input: a = "fsbcnuvqhffbsaqxwp", b = "wpfsbcnuvqhffbsaqx"
// Output: 1

#include<bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2)
{
    // Your code here
    string temp = str1;
    str1.push_back(str1[0]);
    str1.push_back(str1[1]);
    str1.erase(0,2);
    if(str1 == str2) {
        return true;
    } else {
        str1 = temp;
    }
    str2.push_back(str2[0]);
    str2.push_back(str2[1]);
    str2.erase(0,2);
    if(str1 == str2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s1 = "fsbcnuvqhffbsaqxwp";
    string s2 = "wpfsbcnuvqhffbsaqx";
    std::cout << "The result: " << isRotated(s1, s2);
    
}