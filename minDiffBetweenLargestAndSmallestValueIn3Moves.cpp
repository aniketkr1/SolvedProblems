/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves (Medium)

You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

Example 1:
Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

Example 2:
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.

Example 3:
Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
*/

#include<bits/stdc++.h>
using namespace std;

// We consider these scenarios:
// - Change the three largest elements to the fourth largest element
// - Change the two largest elements to the third largest and the smallest element to the second smallest
// - Change the largest element to the second largest and the two smallest elements to the third and fourth smallest
// - Change the three smallest elements to the fourth smallest element
int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) {
        return 0;
    }
    sort(nums.begin(), nums.end());

    int minDiff = INT_MAX;

    // first case
    int min = nums[0];
    int max = nums[nums.size() - 4];
    minDiff = std::min(minDiff, (max - min));

    // second case
    min = nums[1];
    max = nums[nums.size() - 3];
    minDiff = std::min(minDiff, (max - min));

    // third case
    min = nums[2];
    max = nums[nums.size() - 2];
    minDiff = std::min(minDiff, (max - min));

    // fourth case
    min = nums[3];
    max = nums[nums.size() - 1];
    minDiff = std::min(minDiff, (max - min));

    return minDiff;
}

int main() {
    vector<int> nums = { 3,9,0,5,8,12 };
    std::cout << minDifference(nums) << std::endl;
}