/*
46. Permutations (Medium)
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

#include<bits/stdc++.h>
using namespace std;

// optimal opproach using backtracking: T.C.- O(N!*N) and S.C.- O(1)
void solve(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}
// T.C.- O(N!*N) and S.C.- O(N)
void permutations(vector<int>& nums, vector<int>& ds, int visited[], vector<vector<int>>& ans) {
    if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            ds.push_back(nums[i]);
            visited[i] = 1;
            permutations(nums, ds, visited, ans);
            ds.pop_back();
            visited[i] = 0;
        }
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int visited[nums.size()];
    for (int i = 0; i < nums.size(); i++) {
        visited[i] = 0;
    }
    permutations(nums, ds, visited, ans);
    return ans;
}

int main() {
    vector<int> nums{ 1, 2,3 };
    vector<vector<int>> ans;
    // ans = permute(nums);
    solve(0, nums, ans);
    std::cout << "All permutations of a array: " << std::endl;
    for (auto it : ans) {
        for (auto i : it) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}