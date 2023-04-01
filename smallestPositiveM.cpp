// cpp program to find the smalles positive missing number
// arr[] = {1,2,3,4,5}
// Output: 6
// arr[] = {0,-10,1,3,-20}
// Output: 2

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n) 
{ 
    // Your code here
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++) {
        if(arr[i] > 0) {
            mp[arr[i]]++;
        }
    }
    for(int i = 1; i<1000001; i++) {
        if(mp.find(i) == mp.end()) 
        {
            return i;
        }
    }
} 

int main() {
    int arr[] = {1, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "smallest positive missing number: " << missingNumber(arr, n);

}

