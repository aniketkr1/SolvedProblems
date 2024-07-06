/*
1297. Maximum Number of Occurrences of a Substring (Medium)

Given a string s, return the maximum number of occurrences of any substring under the following rules:
The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.

Example 1:
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
*/

#include<bits/stdc++.h>
using namespace std;

// Actually, we only need to check the substring with the minSize, 
// since the occurences of substrings with longer length must be less than or equal to the ones with shorter length.

// this function checking the count of unique characters in str and returns true if the count <= maxLetters
bool check(string str, int maxLetters) {
    int arr[26] = { 0 };
    for (int i = 0; i < str.length(); i++) {
        arr[int(str[i]) - 97]++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) {
            count++;
        }
    }
    if (count <= maxLetters) {
        return true;
    }
    return false;
}

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

    map<string, int> mp;
    string str = "";

    for (int i = 0; i < s.length() + 1; i++) {
        if (str.length() == minSize) {
            if (check(str, maxLetters)) {
                mp[str]++;
            }
            str.erase(str.begin() + 0);
        }
        str += s[i];
    }

    int max = 0;
    for (auto m : mp) {
        if (m.second > max) {
            max = m.second;
        }
    }
    return max;
}

int main() {
    string s = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;

    std::cout << "maxium occurance of substring: " << maxFreq(s, maxLetters, minSize, maxSize) << std::endl;

}