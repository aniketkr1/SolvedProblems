/*
Indexes of Subarray Sum (Medium)

Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) that has sum equal to s. You mainly need to return the left and right indexes(1-based indexing) of that subarray.
In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Example 1:
Input: arr[] = [1,2,3,7,5], n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.

Example 2:
Input: arr[] = [1,2,3,4,5,6,7,8,9,10], n = 10, s = 15,
Output: 1 5
Explanation: The sum of elements from 1st to 5th position is 15.

Example 3:
Input: arr[] = [7,2,1], n = 3, s = 2
Output: 2 2
Explanation: The sum of elements from 2nd to 2nd position is 2.

Example 4:
Input: arr[] = [5,3,4], n = 3, s = 2
Output: -1
Explanation: There is no subarray with sum 2
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long s) {
    vector<int> ans;
    int left = 0;
    int right = 0;
    int sum = 0;
    for (int right = 0; right < n; right++) {
        sum += arr[right];
        while (sum > s && left < right) {
            sum -= arr[left];
            left++;
        }
        if (sum == s) {
            ans.push_back(left + 1);
            ans.push_back(right + 1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,7,5};
    int n = arr.size();
    int s = 12;
    vector<int> ans = subarraySum(arr, n, s);
    std::cout << "Indexes: " << ans[0] << " " << ans[1] << std::endl;
}