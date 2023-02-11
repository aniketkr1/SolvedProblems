// cpp program to find the longest palindrome substring in a string
// Input: "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic substring is "aabbaa"
// Input: "abc"
// Output: a
// Explanation: "a", "b" and "c" are the longest palindromes with same length
//The result is the one with the least starting index.


#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string temp) {
    int l = 0;
    int r = temp.length()-1;
    while(l<=r) {
        if(temp[l] != temp[r]) {
            return false;
        } else {
            l++;
            r--;
        }
    }
    return true;
}
string longestPalin (string S) {
    // code here
    int maxLen = -1;
    string longestPalindrome="";
    for(int i = 0 ;i<S.length(); i++) {
        string p = "";
        for(int j = i; j<S.length(); j++) {
            p+=S[j];
            int len = p.length();
            if(len > maxLen) {
                if(isPalindrome(p)) {
                    longestPalindrome = p;
                    maxLen = len;
                }
            }
        }
        
    }
    return longestPalindrome;
}

int main() {
    string s ="abbaac";
    std::cout << "The longest palindrome: " << longestPalin(s);
}