/*
40. Combination Sum II (Medium)

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

#include<bits/stdc++.h>
using namespace std;

void combinationSumII(int index, vector<int>& nums, int target, vector<int>& ds, vector<vector<int>>& ans) {
    if(target == 0) {
        ans.push_back(ds);
        return;
    }

    for(int i = index; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) {
            continue;
        }
        if(nums[i] > target) {
            break;
        }
        ds.push_back(nums[i]);
        combinationSumII(i+1, nums, target-nums[i], ds, ans);
        ds.pop_back();
    }
}

int main() {
    vector<int> nums {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> ds;
    vector<vector<int>> ans;
    int index = 0;
    sort(nums.begin(), nums.end());
    combinationSumII(index, nums, target, ds, ans);
    std::cout << "All combinations: " << std::endl << "[\n";
    for(auto it : ans) {
        std::cout << "[ ";
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]";


}