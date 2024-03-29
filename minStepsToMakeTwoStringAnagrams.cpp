/*
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.
An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
*/

#include<bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) {
    unordered_map<char, int> sm;
    unordered_map<char, int> tm;

    for(int i = 0; i < s.length(); i++) {
        sm[s[i]]++;
        tm[t[i]]++;
    }

    int count = 0;

    for(auto a : sm) {
        if(tm.find(a.first) != tm.end()) {
            if(sm[a.first] == tm[a.first]) {
                count += sm[a.first];
            } else {
                count += min(sm[a.first], tm[a.first]);
            }
        }   
    }

    return s.length() - count;
}

/*int minSteps(string s, string t) {
    int count[26] = {0};
    int i = 0;
    while(i < s.size()) {
        count[t[i] - 'a']++;
        count[s[i] - 'a']--;
        i++;
    }

    int ans = 0;
    i = 0;
    while(i < 26) {
        ans += max(0, count[i]);
        i++;
    }
    return ans;
} */

int main() {
    string s = "leetcode";
    string t = "practice";

    std::cout << "Minimum numbers of steps to make two string Anagrams: " << minSteps(s,t);
}