// cpp program to find the index of first and last occurrance of X
// Time Complexity: O(logn) using binary search
// Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int binarySearchFirst(int arr[], int low, int high, int key) {
    
    int minx = INT_MAX;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) {
            // element found
            if(mid < minx) {
                minx = mid;
            }
            high = mid-1;
        }  else if(key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if(minx != INT_MAX) {
        return minx;
    } else {
        return -1;
    }
}

int binarySearchLast(int arr[], int low, int high, int key) {
    
    int maxm = INT_MIN;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) {
            // element found
            if(mid > maxm) {
                maxm = mid;
            }
            low = mid+1;
        }  else if(key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if(maxm != INT_MIN) {
        return maxm;
    } else {
        return -1;
    }
}


int main() {
    int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int len = sizeof(arr)/sizeof(arr[0]);
    int low = binarySearchFirst(arr, 0, len-1, 5);
    int high = binarySearchLast(arr, 0, len-1, 5);
    std::cout << "First Index = " << low << std::endl;
    std::cout << "Last Index = " << high << std::endl;

}