/*
Permutation with Spaces
Difficulty: Medium
Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:
Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

Example 2:
Input:
s = "BBR"
Output: (B B R)(B BR)(BB R)(BBR)
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op, vector<string>& ans) {
    if (ip.length() == 0) {
        ans.push_back(op);
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);

    ip.erase(ip.begin() + 0);

    solve(ip, op1, ans);
    solve(ip, op2, ans);
    return;
}

vector<string> permutation(string s) {
    vector<string> ans;
    string ip = s;
    ip.erase(ip.begin() + 0);
    string op;
    op.push_back(s[0]);

    solve(ip, op, ans);
    return ans;
}


int main() {
    string s = "ABC";
    vector<string> ans = permutation(s);
    for(auto s : ans) {
        std::cout << "(" << s << ")";
    }

}