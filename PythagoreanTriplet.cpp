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
        std::cout << "pythagorean triplet found" << std::endl;
    } else {
        std::cout << "pythagorean triplet not found" << std::endl;
    }
}