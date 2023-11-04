/*
Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.
Input: N = 5, Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
*/
#include<bits/stdc++.h>
using namespace std;

bool checkTriplet(int arr[], int n) {
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++) {
        mp[arr[i]*arr[i]]++;
    }
    for(int i = 0; i<n; i++)  {
        for(int j = 0; j<n; j++) {
            if( mp[(arr[i]*arr[i]) + (arr[j]*arr[j])]) {
                return true;
            }
        }
    }
        return false;
	}

int main() {
    int arr[] = {3, 2, 4, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(checkTriplet(arr, n)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}