/*
39. Combination Sum (Medium)

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

*/

#include<bits/stdc++.h>
using namespace std;

void combinationSum(int index, vector<int>& nums, int target, vector<int>& ds, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        return;
    }
    if(target == 0) {
        ans.push_back(ds);
        return;
    }

    if(nums[index] <= target) {
        ds.push_back(nums[index]);
        combinationSum(index, nums, target-nums[index], ds, ans);
        ds.pop_back();
    }
    combinationSum(index+1, nums, target, ds, ans);
}

int main() {
    vector<int> nums = {2,3,5};
    int target = 8;
    int index = 0;
    vector<int> ds;
    vector<vector<int>> ans;
    combinationSum(index, nums, target, ds, ans);
    std::cout << "All combinations: " << std::endl << "[";
    for(auto it : ans) {
        std::cout << " [ ";
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "]";
    }
    std::cout << " ]";
}