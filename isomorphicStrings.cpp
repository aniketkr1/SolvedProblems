/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
*/
#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2) {

    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, char> map1, map2;

    for (int i = 0; i < str1.length(); i++) {
        if (map1.find(str1[i]) != map1.end() && map1[str1[i]] != str2[i]) {
            return false;
        }

        if (map2.find(str2[i]) != map2.end() && map2[str2[i]] != str1[i]) {
            return false;
        }
        map1[str1[i]] = str2[i];
        map2[str2[i]] = str1[i];
    }
    return true;
}

int main() {
    string str1 = "apple";
    string str2 = "cbbkn";
    int ans = areIsomorphic(str1, str2);
    if(ans) {
        std::cout << "Isomorphic" << std::endl;
    } else {
        std::cout << "Not Isomorphic" << std::endl;
    }
}