// cpp program to find an element in rotated sorted array in O(log n) time complexity
// The integer array is sorted in ascending order
// The integer array is rotated at an unknown pivot index
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

int search(vector<int>& nums, int target) {
    int s = nums.size()-1;
    if(nums.size() == 1) {
        if(nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }
    int pivot = -1;
    for(int i = 0; i<nums.size()-1; i++) {
        if(nums[i] > nums[i+1]) {
            pivot = i;
        }
    }
    if(pivot != -1) {
        int ans1 = binarySearch(nums, 0, pivot, target);
        int ans2 = binarySearch(nums, pivot+1, s, target);

        if(ans1 == ans2) {
            return -1;
        } else {
            return max(ans1, ans2);
        }

    } else {
        int ans3 = binarySearch(nums, 0, s, target);
        return ans3;
    }
    
}

int main() { 
    vector<int> nums {4,5,6,7,0,1,2};
    int target = 4;
    int res = search(nums, target);
    if(res != -1) {
        std::cout << target << " found at index " << res << std::endl;
    } else {
        std::cout << target << " not found" << std::endl;
    }
}