/*
1636. Sort Array by Increasing Frequency (Easy)

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        map<int, vector<int>> temp;

        for (auto it : mp) {
            for (int i = 0; i < it.second; i++) {
                temp[it.second].push_back(it.first);
            }
        }

        for (auto it : temp) {
            vector<int> vec = it.second;
            // Sort the vector in decreasing order usign lambda function
            std::sort(vec.begin(), vec.end(), [](int a, int b) {
                return a > b; // Define the order for decreasing
            });
            ans.insert(ans.end(), vec.begin(), vec.end());
        }

        return ans;
    }

int main() {
    vector<int> nums = {1,1,2,2,2,3};
    vector<int> ans = frequencySort(nums);
    for(auto a : ans) {
        std::cout << a << " ";
    }
}