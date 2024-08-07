/*
cpp program to print all subsequences of an array

Example 1:
Input: {1,2,3}
Output: {{1,2,3},{1,2},{1,3},{1},{2,3},{2},{3},{}}

Example 2:
Input: {1,3,2};
Output: {{1,3,2},{1,3},{1,2},{1},{3,2},,{3},{2},{}}
*/

#include<bits/stdc++.h>
using namespace std;

void subsequences(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    subsequences(index+1, nums, ds, ans); // take
    ds.pop_back();
    subsequences(index+1, nums, ds, ans); // not take
}

int main() {
    vector<int> nums {1,2,3};
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    subsequences(index, nums, ds, ans);
    for(auto it : ans) {
        for(auto i : it) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}