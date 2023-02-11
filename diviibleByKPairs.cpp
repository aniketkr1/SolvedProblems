// cpp program to count all the possible pairs while absolute difference
// is divisible by k
// Input: {3, 7, 11, 11}, k= 4
// Output: 6 {(3,7), (7,11), (11,11), (11,3), (11,3), (11,7)}

#include<bits/stdc++.h>
using namespace std;

long long countPairs(int n, int arr[], int k) {
    long long ans = 0;
    map<int, int> m;
    for(int i = 0; i<n; i++) {
        ans = ans + m[arr[i]%k];
        m[arr[i]%k]++;
    }
    return ans;
}

int main() {
    int arr[] = {3, 7, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    long long pairs = countPairs(n, arr, k);
    std::cout << "Total number of pairs: " << pairs;
}