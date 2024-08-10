/*
17. Letter Combinations of a Phone Number (Medium)

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.=
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

(1    )   (2 abc)   (3 def)

(4 ghi)   (5 jkl)   (6 mno)

(7 pqrs)  (8 tuv)   (9 wxyz)

   +*       0          #

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string output, string digits, int index, vector<string>& ans, vector<string>& mapping) {
    if (index >= digits.size()) {
        ans.push_back(output);
        return;
    }

    int val = digits[index] - '0';
    string str = mapping[val];

    for (int i = 0; i < str.size(); i++) {
        output.push_back(str[i]);
        solve(output, digits, index + 1, ans, mapping);
        output.pop_back(); // backtrack
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) {
        return ans;
    }
    vector<string> mapping = { "", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    solve("", digits, 0, ans, mapping);
    return ans;

}


int main() {
    vector<string> ans = letterCombinations("23");
    for(auto it : ans) {
        std::cout << it << " ";
    }

}