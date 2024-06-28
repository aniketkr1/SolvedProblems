/*
1296. Divide Array in Sets of K Consecutive Numbers (Medium)

Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
Return true if it is possible. Otherwise, return false.

Example 1:
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Example 2:
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Example 3:
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
*/

#include<bits/stdc++.h>
using namespace std;

/* bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) {
        return false;
    }
    sort(nums.begin(), nums.end());
    int start;
    int flag = 0;
    int count = 0;
    for (int i = 0; i < nums.size() / k; i++) {
        flag = 0;
        count = 0;
        start = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != -1 && flag == 0) {
                start = nums[j];
                flag = 1;
            }
            if (nums[j] == start && nums[j] != -1) {
                start++;
                nums[j] = -1;
                count++;
            }
            if (count == k) {
                break;
            }
        }
    }

    for (auto v : nums) {
        if (v != -1) {
            return false;
        }
    }
    return true;
}*/

bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) {
        return false;
    }

    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    int n = nums.size();
    while (n--) {
        for (auto m : mp) {
            for (int i = m.first; i < m.first + k; i++) {
                if (mp[i] == 0) {
                    return false;
                }
                mp[i]--;
                if (mp[i] == 0) {
                    mp.erase(i);
                }
            }
            break;
        }
    }
    return true;
}

int main() {
    vector<int> nums = { 1,2,3,3,4,4,5,6 };
    int k = 4;
    bool isPossible = isPossibleDivide(nums, k);
    if(isPossible) {
        std::cout << "It is possible" << std::endl;
    } else {
        std::cout << "It is not possible" << std::endl;
    }
}