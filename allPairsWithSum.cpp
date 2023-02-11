// cpp program to find all pairs with a given sum using two pointer approach and hashing

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

// Two pointer approach(duplicates allowed)
// Time complexity: O(nlogn) 
// Space complexity: O(1)
// shorting is required
void pairedElement(int arr[], int n, int sum) {
    int low = 0;
    int high = n-1;
    while(low < high) {
        if(arr[low] + arr[high] == sum) {
            std::cout << "(" <<  arr[low] << ", " << arr[high] << ")"<< std::endl;
        }   
        if(arr[low] + arr[high] > sum) {
            high--;
        } else {
            low++;
        }
    }
}

// Hashing(duplicates are not allowed)
// Time complexity: O(n);
// Space complexity: O(n);
// shorting is not required
void printPairs(int arr[], int n, int sum) {
    map<int, int> mp;
    for(int i = 0; i<n; i++) {
        int rem = sum - arr[i];
        if(mp.find(rem) != mp.end()) // element is present 
        {
            std::cout << "(" << rem << ", " << arr[i] << ")" << std::endl;
            mp.erase(rem);
        }
        mp[arr[i]]++;
    }

}
    
int main() {
    int arr[] = {1, 5, 5, 1, 2, 2, 3, 4, 6, 2, 5, 3, 4, 3, 2};
    int target = 7;
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size);
    std::cout << "Sorted Array: ";
    for(auto K : arr) {
        std::cout << K << " ";
    }
    std::cout << std::endl;
    pairedElement(arr, size, target);

    
}