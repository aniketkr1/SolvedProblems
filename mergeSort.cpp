/*
cpp programt to sort an array using merge sort algorithm

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
*/

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // pushing the remaining elements of the left array
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // pushing the remaining elements of the right array
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // copying the mergerd elements back to original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low]; //temp[i-low] since temp is zero-based and i ranges from low to high.
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
int main() {
     vector<int>nums = {6,3,1,8,9,2};
    int low = 0;
    int high = nums.size() - 1;
    mergeSort(nums, low, high);
    for(int num : nums) {
        std::cout << num << " ";
    }
}

