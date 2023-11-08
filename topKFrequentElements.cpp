/*Given a non-empty array nums[] of integers of length N, find the top k elements which have the highest frequency in the array. If two numbers have same frequencies, then the larger number should be given more preference.

Input: N = 6, nums = {1,1,1,2,2,3}, k = 2
Output: {1, 2}

Input:N = 8, nums = {1,1,2,2,3,3,3,4}, k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> topK(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> q;
    for(auto i : nums) {
        mp[i]++;
    }
    for(auto m : mp) {
        q.push({m.second, m.first});
    }
    
    while(!q.empty() && k--) {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int main() {

    int N = 8;
    vector<int> nums = {1,1,2,2,3,3,3,4};
    int k = 2;
    vector<int> ans = topK(nums, k);
    std::cout << "Top K frequnt elements: " << std::endl;
    for(auto v : ans) {
        std::cout << v << " ";
    }

}