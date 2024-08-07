/*
78. Subsets (Medium)

Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include<bits/stdc++.h>
using namespace std;
void allSubset(int index, vector<int>& nums, vector<int>& ds,
    vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    allSubset(index + 1, nums, ds, ans); // pick 
    ds.pop_back();
    allSubset(index + 1, nums, ds, ans); // not pick
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    allSubset(index, nums, ds, ans);
    return ans;
}

int main() {
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> ans = subsets(nums);
    std::cout << "All subsets: " << std::endl << "[\n";
    for(auto it : ans) {
        std::cout << "[ ";
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]";
}