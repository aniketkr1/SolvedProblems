/*
131. Palindrome Partitioning (Medium)

Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    while (start <= end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}
void palindromePartition(int index, string str, vector<string>& ds, vector<vector<string>>& ans) {
    if (index >= str.size()) {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < str.size(); i++) {
        if (isPalindrome(str, index, i)) {
            ds.push_back(str.substr(index, i - index + 1));
            palindromePartition(i + 1, str, ds, ans);
            ds.pop_back();
        }
    }
}

int main() {
    string s = "aabb";
    int index = 0;
    vector<vector<string>> ans;
    vector<string> ds;

    palindromePartition(index, s, ds, ans);

    std::cout << "All palindrome partitions: " << std::endl << "[";
    for (auto it : ans) {
        std::cout << "[ ";
        for (auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "]";
    }
    std::cout << "]";
}