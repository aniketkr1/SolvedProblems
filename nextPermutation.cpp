/*
31. Next Permutation (Medium)

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    bool breakPoint = false;
    int pos = 0;
    int n = nums.size();
    // finding breakpoint(num[i] < nums[i+1])
    for (int i = n-2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            breakPoint = true;
            pos = i;
            break;
        }
    }
    // breakpoint not found(array is in decreasing order)
    if (!breakPoint) {
        reverse(nums.begin(), nums.end());
    }
    else {
        // breakpoint found
        // finding the smallest number i.e > nums[i] and in the right half of index
        // i.e index from i+1 to n-1 and swap it with nums[i] that is breakpoint element
        
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > nums[pos]) {
                swap(nums[i], nums[pos]);
                break;
            }
        }
        
        // reversing the nums from pos+1 to end
        reverse(nums.begin() + pos + 1, nums.end());
    }
    std::cout << "Next Permutation: ";
    for(const auto& num : nums) {
        std::cout << num << " ";
    }
}

int main() {
    vector<int> nums = { 1,2,3 };
    nextPermutation(nums);
}