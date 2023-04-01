// cpp program to check whether or not exits two elements in array whose sum is exactly x
// Input:N = 6, X = 16, Arr[] = {1, 4, 45, 6, 10, 8}
/// Output: Yes
// Explanation: Arr[3] + Arr[4] = 6 + 10 = 16

#include<bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x) {
    // two pointer approach
    sort(arr, arr+n);
    int left = 0;
    int right = n-1;
    while(left < right) {
        if(arr[left] + arr[right] == x) {
            return true;
        } else if(arr[left] + arr[right] > x) {
            right--;
        } else {
            left++;
        }
    }
    return false;
}

int main() {
    int arr[] = {2, 4, 8, 30, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(hasArrayTwoCandidates(arr, n, 11)) std::cout << "yes";
    else 
    std::cout << "no";

}