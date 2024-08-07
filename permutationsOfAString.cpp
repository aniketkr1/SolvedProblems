/*
Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order.

Example 1:
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6
forms as ABC, ACB, BAC, BCA, CAB and CBA .

Example 2:
Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS
BASG BGAS BGSA BSAG BSGA GABS GASB
GBAS GBSA GSAB GSBA SABG SAGB SBAG
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
*/

#include<bits/stdc++.h>
using namespace std;

void permutations(string S, string permute, int visited[], vector<string>& ans) {
    if (permute.size() == S.size()) {
        if (find(ans.begin(), ans.end(), permute) == ans.end()) {
            ans.push_back(permute);
            return;
        }
    }
    for (int i = 0; i < S.length(); i++) {
        if (!visited[i]) {
            permute.push_back(S[i]);
            visited[i] = 1;
            permutations(S, permute, visited, ans);
            visited[i] = 0;
            permute.pop_back();
        }
    }
}

vector<string>find_permutation(string S)
{
    vector<string> ans;
    int visited[S.length()];
    for (int i = 0; i < S.length(); i++) {
        visited[i] = 0;
    }
    string permute = "";
    permutations(S, permute, visited, ans);

    return ans;
}

// input/output method
void solve(string ip, string op, vector<string>& ans) {
    if (ip.size() == 0) {
        if (find(ans.begin(), ans.end(), op) == ans.end()) {
            ans.push_back(op);
        }
        return;
    }
    else {
        for (int i = 0; i < ip.size(); i++) {
            string ip1 = ip.substr(0, i) + ip.substr(i + 1);
            solve(ip1, op + ip[i], ans);
        }
    }
}

int main() {

    string ip = "ABC";
    vector<string> ans;
    string op = "";
    // solve(ip, op, ans);
    ans = find_permutation(ip);
    for (string s : ans) {
        std::cout << s << " ";
    }
}