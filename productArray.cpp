// cpp program to find the product of all elements except itself
// Explaination: nums = {10, 3, 5, 6, 2}
// ans[0] = 3*5*6*2 = 180, ans[1] = 10*5*6*2 = 600, ..... so on.
// we are multiplying all the elements except itself
// Input: {10, 3, 5, 6, 2}
// Output: {180, 600, 360, 300, 900}

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
    //code here   
    vector<long long int> ans;
    int zeroCount = 0;
    long long p = 1;
    for(auto a : nums) {
        if(a == 0) {
            zeroCount++;
            continue;
        } else {
            p = p * a;
        }
    }
    if(zeroCount > 1) {
        ans.assign(n, 0);
        return ans;
    }
    for(int i = 0; i<n; i++) {
        if(zeroCount == 1) {
            if(nums[i] == 0) {
                ans.push_back(p);
            } else {
                ans.push_back(0);
            }
        }
        else {
            long long int rem = p/nums[i];
            ans.push_back(rem);
        }
    }
    return ans;
}

int main() {
    vector<long long int> v = {10, 3, 5, 6, 2};
    int n = v.size();
    vector<long long int> res = productExceptSelf(v, n);
    for(auto a : res) {
        std::cout << a << " ";
    }

}