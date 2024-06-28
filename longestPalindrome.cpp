/*
409. Longest Palindrome (Easy)

Given a string s which consists of lowercase or uppercase letters, return the length of the longest
palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

*/

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    int count = 0;
    int max = 0;
    for (auto m : mp) {
        if (m.second % 2 != 0) {
            count += m.second - 1;
            max = 1;
        }
        else {
            count += m.second;
        }
    }
    return max + count;
}

int main() {
    string str = "abccccdd";
    std::cout << "Lenght of the longest palindrome that can be built: " << longestPalindrome(str);
}