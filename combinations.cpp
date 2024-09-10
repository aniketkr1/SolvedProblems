/*
77. Combinations (Medium)

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int index, int n, int k, vector<int>& ds,
    vector<vector<int>>& ans) {
    if (ds.size() == k) {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i <= n; i++) {

        ds.push_back(i);
        solve(i + 1, n, k, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> ds;
    solve(1, n, k, ds, ans);
    return ans;
}

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> ans = combine(n, k);
    std::cout << "All combinations:\n";
    for(auto it : ans) {
        std::cout << "[ ";
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "] ";
    }
}