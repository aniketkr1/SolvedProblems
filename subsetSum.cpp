/*
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Example 1:
Input:
n = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then
Sum = 2+3 = 5.

Example 2:
Input:
n = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
*/

#include<bits/stdc++.h>
using namespace std;
void findSubsets(int index, int sum, vector<int>& nums, vector<int>& ans) {
    if (index >= nums.size()) {
        ans.push_back(sum);
        return;
    }

    findSubsets(index + 1, sum + nums[index], nums, ans); // pick
    findSubsets(index + 1, sum, nums, ans); // not pick
}
vector<int> subsetSums(vector<int> arr, int n) {
    int index = 0;
    vector<int> ans;
    int sum = 0;
    findSubsets(index, sum, arr, ans);
    return ans;
}
int main() {
    vector<int> arr = { 3, 1,2 };
    int n = arr.size();
    vector<int> ans = subsetSums(arr, n);
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        std::cout << i << " ";
    }
}