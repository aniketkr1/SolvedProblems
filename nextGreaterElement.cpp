// cpp program to find the next greater element of all the elements
// Next greater element of an element in the array is the nearest 
// element on the right which is greater than the current element.
// If there does not exist next greater of current element,
// then next greater element for current element is -1. For example, 
// next greater of the last element is always -1.
// Input: N = 4, arr[] = [1 3 2 4]
// Output: 3 4 4 -1
// Explanation: In the array, the next larger element to 1 is 3 , 3 is 4
// , 2 is 4 and for 4 ? since it doesn't exist, it is -1.

#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long> v;
    stack<long long> s;
    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i = n-2; i>=0; i--) {
        while(!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }
        if(!s.empty() && s.top() >= arr[i]) {
            v.push_back(s.top());
        } else {
            if(s.empty()) {
                v.push_back(-1);
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    vector<long long> arr = {1,3,2,4};
    int n = arr.size();
    vector<long long> ans = nextLargerElement(arr, n);
    for(auto it : ans) {
        std::cout << it << "  ";
    }
}