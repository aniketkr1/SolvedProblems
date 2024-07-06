/*
22. Generate Parentheses (Medium)

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int open, int close, string op, vector<string>& allParenthesis) {
    if (open == 0 && close == 0) {
        allParenthesis.push_back(op);
        return;
    }

    if (open != 0) {
        string op1 = op;
        op1.push_back('(');
        solve(open - 1, close, op1, allParenthesis);
    }
    if (close > open) {
        string op2 = op;
        op2.push_back(')');
        solve(open, close - 1, op2, allParenthesis);
        return;
    }

}
vector<string> generateParenthesis(int n) {
    vector<string> allParenthesis;
    int open = n;
    int close = n;
    string op = "";
    solve(open, close, op, allParenthesis);
    return allParenthesis;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for(string str : ans) {
        std::cout << str << "  ";
    }
}