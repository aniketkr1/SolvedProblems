/*
784. Letter Case Permutation (Medium)

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op, vector<string>& ans) {
    if (ip.length() == 0) {
        ans.push_back(op);
        return;
    }

    if (isalpha(ip[0])) {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);
        solve(ip, op1, ans);
        solve(ip, op2, ans);
        return;
    }
    else {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(ip, op1, ans);
        return;
    }

}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string ip = s;
    string op = "";
    solve(ip, op, ans);
    return ans;
}

int main() {
    string str = "a1b2";
    vector<string> permutations = letterCasePermutation(str);
    for(auto p : permutations) {
        std::cout << p << std::endl;
    }
}