// cpp program to find the leaders in an array
// An element of array is leader if it is greater than or 
// equal to all the elements to its right side. The rightmost element is always a leader
// Input: n = 6, A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 as it is greater then all other elements in the right
// then 5 is the second leader as it is greater then all other elements in the right
// then 2 is the third leader as it is last element 

#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n){
    vector<int> ans;
    int leader = a[n-1];
    ans.push_back(leader);
    for(int i = n-2; i>=0; i--) {
        if(a[i] >= leader) {
            leader = a[i];
            ans.push_back(leader);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int arr[] = {20,16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans = leaders(arr, n);
    std::cout << "The leaders: ";
    for(auto it: ans) {
        std::cout << it << "  ";
    }

}