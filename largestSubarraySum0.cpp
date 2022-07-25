// cpp program to find the length of the largest subarray whose sum is zero
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 0, -4, 9, 5, -14};
    int size = sizeof(arr)/sizeof(arr[0]);
    map<int, int> mp;

    int sum = 0;
    int maxLength = 0;

    for(int i = 0; i<size; i++) {
        sum = sum + arr[i];

        if(arr[i] == 0 && maxLength == 0) {
            maxLength = i;
        }
        if(sum == 0) {
            maxLength = i + 1;
        }
        
        if(mp.find(sum) != mp.end()) {
            maxLength = max(maxLength, i - mp[sum]);

        } else {
            mp[sum] = i;
        }
    }
    std::cout << "Length: " << maxLength << std::endl;
}
