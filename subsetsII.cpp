/*
90. Subsets II (Medium)

Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include<bits/stdc++.h>
using namespace std;

void subsetII(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);
    for(int i = index; i<nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) {
            continue;
        }
        ds.push_back(nums[i]);
        subsetII(i+1, nums, ds, ans);
        ds.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    subsetII(index, nums, ds, ans);
    std::cout << "All subsets:" << "\n[ \n";
    for(auto it : ans) {
        std::cout << "[ ";
        for(auto i : it ) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]";
}