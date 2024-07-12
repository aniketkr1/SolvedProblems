/*
1717. Maximum Score From Removing Substrings (Medium)

You are given a string s and two integers x and y. You can perform two types of operations any number of times.
Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

*/

#include<bits/stdc++.h>
using namespace std;

int maximumGain(string s, int x, int y) {
    int count = 0;
    char c1;
    char c2;
    char p1;
    char p2;
    int m;
    int mn;
    m = max(x, y);
    mn = min(x, y);
    if (m == x) {
        c1 = 'a';
        c2 = 'b';
        m = x;
    }
    if (m == y) {
        c1 = 'b';
        c2 = 'a';
        m = y;
    }

    if (mn == x) {
        p1 = 'a';
        p2 = 'b';
        mn = x;
    }

    if (mn == y) {
        p1 = 'b';
        p2 = 'a';
        mn = y;
    }

    int n = s.length();
    int i = 0;
    while (n > i) {
        if (i + 1 < s.size() && s[i] == c1 && s[i + 1] == c2) {
            s.erase(i, 2);
            count += m;
            i = (i > 0) ? i - 1 : 0; 
        }
        else {
            i++;
        }
        n = s.size(); 
    }
    n = s.size();
    i = 0;
    while (n > i) {
        if (i + 1 < s.size() && s[i] == p1 && s[i + 1] == p2) {
            s.erase(i, 2);
            count += mn;
            i = (i > 0) ? i - 1 : 0;
        }
        else {
            i++;
        }
        n = s.size();
    }
    return count;
}


int main() {
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;
    std::cout << "Maximum score: " <<maximumGain(s, x, y);
}