/*
1508. Range Sum of Sorted Subarray Sums (Medium)

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

Example 1:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.

Example 2:
Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:
Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int rangeSum(vector<int>& nums, int n, int left, int right) {
    // generate all non-empty continuous subarrays sum
    vector<int> sums;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            sums.push_back(sum);
        }
    }
    sort(sums.begin(), sums.end());
    int ans = 0;
    for (int i = left - 1; i < right; i++) {
        ans = (ans + sums[i]) % mod;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    int n = nums.size();
    int left = 1;
    int right = 5;
    std::cout << "sum: " << rangeSum(nums, n, left, right) << std::endl;
    
}