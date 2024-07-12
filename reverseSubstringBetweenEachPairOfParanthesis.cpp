/*
1190. Reverse Substrings Between Each Pair of Parentheses (Medium)

You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.

Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
*/

#include<bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ')') {
            string rev = "";
            while (!st.empty() && st.top() != '(') {
                rev += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
            for (int j = 0; j < rev.length(); j++) {
                st.push(rev[j]);
            }
        }
        else {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string s = "(ed(et(oc))el)";
    std::cout << "Reversed string: " << reverseParentheses(s) << std::endl;
}