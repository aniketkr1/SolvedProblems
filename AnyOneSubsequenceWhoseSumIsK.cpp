/*
cpp program to print only one subsequences whose sum is k

Example 1:
Input: {1,2,1}, k = 2
Output: {1,1}

Example 2:
Input: {1,2,3,4,5}, k = 5
Output: {1,4}
*/

#include<bits/stdc++.h>
using namespace std;

bool anyOneSubsequenceWithSumK(int index, vector<int>& nums, vector<int>& ds, int sum, int k) {
    if(index >= nums.size()) {
        // condition satisfied
        if(sum == k) {
            for(auto it : ds) {
                std::cout << it << " ";
            }
            std::cout << std::endl;
            return true;
        }
        // condition not satisfied
        return false;
    }

    ds.push_back(nums[index]);
    sum += nums[index];
    if(anyOneSubsequenceWithSumK(index+1, nums, ds, sum, k) == true) {
        return true;
    }
    ds.pop_back();
    sum -= nums[index];
    if(anyOneSubsequenceWithSumK(index+1, nums, ds, sum, k) == true) {
        return true;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> ds;
    int index = 0;
    int sum = 0;
    int k = 3;
    if(!anyOneSubsequenceWithSumK(index, nums, ds, sum, k)) {
        std::cout << "No subsequence found whose sum is " << k;
    }
}