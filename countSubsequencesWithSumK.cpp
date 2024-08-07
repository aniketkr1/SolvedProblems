/*
cpp program to count the number of subsequences with sum = k

Example 1:
Input: {1,2,1}, k = 2;
Output: 2 {(1,1), (2)}

Example 2:
Input: {1,2,3,4,5}, k = 10
Output: 3 {(1,2,3,4), (1,4,5), (2,3,5)}
*/

#include<bits/stdc++.h>
using namespace std;

int countSubsequencesWithSumK(int index, vector<int>& nums, int sum, int k) {
    if(index >= nums.size()) {
        // condition satisfied
        if(sum == k) {
            return 1;
        }
        // condition not satisfied
        return 0;
    }

    sum += nums[index];
    int l = countSubsequencesWithSumK(index+1, nums, sum, k);

    sum -= nums[index];
    int r = countSubsequencesWithSumK(index+1, nums, sum, k);

    return l+r;
}

int main() {
    vector<int> nums = {1,2,1};
    int index = 0;
    int sum = 0;
    int k = 2;
    
    std::cout << countSubsequencesWithSumK(index, nums, sum, k);
}