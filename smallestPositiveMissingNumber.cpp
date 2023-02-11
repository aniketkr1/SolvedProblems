// cpp program to find the smallest positive missing number
// Input: N = 5 arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing number is 6.

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n) 
{ 
    // Your code here
    for(int i = 0; i<n; i++) {
        if(arr[i] < 0) {
            arr[i] = 0;
        }
    }
    sort(arr, arr+n);
    int count = 0;
    // checking if 1 is there is not
    // if its not there then return 1 else check further
    for(int i = 0; i<n; i++) {
        if(arr[i] == 1) {
            count++;
        }
    }
    if(count == 0) {
        return 1;
    }
    for(int i = 0; i<n-1; i++) {
        if(arr[i+1] - arr[i] > 1 ) {
            return (arr[i]+1);
        }
    }
    return arr[n-1]+1;
} 

int main() {
    int arr[] = {-20, -10, 0, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Smallest positive missing number: " << missingNumber(arr, n);
}