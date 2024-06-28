/*
2486. Append Characters to String to Make Subsequence (Medium)

You are given two strings s and t consisting of only lowercase English letters.
Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Example 1:
Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.

Example 2:
Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").

Example 3:
Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t) {
    int s_index = 0;
    int t_index = 0;

    while (s.length() > s_index && t.length() > t_index) {
        if (s[s_index] == t[t_index]) {
            t_index++;
        }

        s_index++;
    }

    return (t.length() - t_index);
}

int main() {
    string s = "coaching";
    string t = "coding";

    std::cout << "Min numbers of chars to be appened: " << appendCharacters(s, t) << std::endl;
}