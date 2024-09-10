/*
Count Inversions (Medium)
Given an array of integers. Find the Inversion Count in the array.  Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.

Examples:

Example 1:
Input: arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Example 3:
Input: arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Expected Time Complexity: O(n*logn).
Expected Auxiliary Space: O(n).
*/

#include<bits/stdc++.h>
using namespace std;

int merge(int low, int mid, int high, vector<long long>& arr) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int count = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(int low, int high, vector<long long>& arr) {
    int cnt = 0;
    if (low >= high) {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergeSort(low, mid, arr);
    cnt += mergeSort(mid + 1, high, arr);
    cnt += merge(low, mid, high, arr);
    return cnt;

}

long long int inversionCount(vector<long long>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    long long int ans = mergeSort(low, high, arr);
    return ans;
}

int main() {
    vector<long long int> arr = {2, 4, 1, 3, 5};
    std::cout << "Number of inversions: " << inversionCount(arr);
}