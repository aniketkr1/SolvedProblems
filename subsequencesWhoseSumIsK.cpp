/*
cpp program to print all subsequences whose sum is k

Example 1:
Input: {1,2,1}, k = 2
Output: {{1,1}, {2}}

Example 2:
Input: {1,2,3,4,5}, k = 5
Output: {{1,4},{2,3},{5}}
*/

#include<bits/stdc++.h>
using namespace std;

void subsequencesWithSumK(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int sum, int k) {
    if(index >= nums.size()) {
        if(sum == k) {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(nums[index]);
    sum += nums[index];
    subsequencesWithSumK(index+1, nums, ds, ans, sum, k);
    ds.pop_back();
    sum -= nums[index];
    subsequencesWithSumK(index+1, nums, ds, ans, sum, k);
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    int sum = 0;
    int k = 10;
    subsequencesWithSumK(index, nums, ds, ans, sum, k);
    std::cout << "All subsequences: " << std::endl << "[\n";
    for(auto it : ans) {
        std::cout << "[ ";
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]";
}