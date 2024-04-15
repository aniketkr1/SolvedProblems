// cpp program to convert the given array to a reduced form where all elements are in range from 0 to N-1. 
// The order of elements is same, i.e., 0 is placed in place of smallest element, 
// 1 is placed for second smallest element, and N-1 is placed for the largest element
// Input:Arr[] = {10, 40, 20}
// Output: 0 2 1
// Explanation: 10 is the least element so it is replaced by 0. 
// 40 is the largest element so it is replaced by 3-1 = 2
// And 20 is the 2nd smallest element so it is replaced by 1.

#include<bits/stdc++.h>
using namespace std;

void convert(int arr[], int n) {

    int temp[n];
    for(int i = 0; i<n; i++) {
        temp[i] = arr[i];
    }
    sort(temp, temp+n);
    map<int, int> mp;
    for(int i = 0; i<n; i++) {
        mp.insert({temp[i], i});
    }
    for(int i = 0; i<n; i++) {
        arr[i] = mp[arr[i]];
    }
    std::cout << "Modified array: ";
    for(int i = 0; i<n; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {5, 10, 40, 30, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    convert(arr, n);
}
