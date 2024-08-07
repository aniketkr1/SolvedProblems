/*
cpp program to (print all subsequence = print all subset = print powerset)

Example 1:
Input: "abc";
Output: {"", a, b, c, ab, ab, ac, abc};

Example 2:
Input: "ab";
Output: {"", a, b, ab};
*/

#include<bits/stdc++.h>
using namespace std;

void printAllSubsequences(string ip, string op) {
    if(ip.length() == 0) {
        std::cout << op << std::endl;
        return;
    }
    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    printAllSubsequences(ip, op1);
    printAllSubsequences(ip, op2);
    return ;
}

int main() {
    string ip = "abc";
    string op = "";
    printAllSubsequences(ip, op);
}