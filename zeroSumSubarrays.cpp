// cpp program to find the number of subarrays whose sum is equal to 0
// Input: {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4 {The 4 subarrays are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]}

#include<bits/stdc++.h>
using namespace std;

int findSubarrays(vector<long long int> &arr, int n) {
    
    int count = 0;
    map<int, int> mp;
    long long int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if(sum == 0) {
            count++;
        }
        if(mp.find(sum) != mp.end()) {
            mp[sum]++;
            count +=  (mp[sum] - 1);
        } else {
            mp[sum]++;
        }
    }
    return count;
}

int main() {
    vector<long long int> v = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = v.size();
    int res = findSubarrays(v, n);
    std::cout << "Total number of subarrays whose sum is equal to 0 = " << res;

}