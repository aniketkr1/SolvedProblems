/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2] 
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2,0);

        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                ans[0] = nums[i];
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0) - ans[0];
        int orgSum = (nums.size()*(nums.size()+1))/2;
        ans[1] = orgSum - sum;
        return ans;
    }

    // vector<int> findErrorNums(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> v(n+1, 0);
    //     int missing = 0, duplicate = 0;
    //     for(int i = 0; i<n; i++) {
    //         v[nums[i]]++;
    //     }
    //     for(int i = 1; i<v.size(); i++) {
    //         if(v[i] == 2) {
    //             duplicate = i;
    //         }
    //         if(v[i] == 0) {
    //             missing = i;
    //         }
    //     }
    //     return {duplicate, missing};
    // }
};

int main() {
    Solution s =  Solution();
    vector<int> nums = {1,2,2,4};
    vector<int> ans = s.findErrorNums(nums);
    std::cout << "Duplicate: " << ans[0] << std::endl;
    std::cout << "Missing: " << ans[1] << std::endl;
}