/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/

#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int> occur;

    for(int i = 0; i<arr.size(); i++) {
        int count = 1;
        while(i+1 < arr.size() && arr[i] == arr[i+1]) {
            count++;
            i++;
        }
        occur.push_back(count);
    }

    sort(occur.begin(), occur.end());

    for(int i = 1; i<occur.size(); i++) {
        if(occur[i-1] == occur[i]) {
            return false;
        }
    }
    return true;
}


/*bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> occurance;
    for(int i = 0; i<arr.size(); i++) {
        occurance[arr[i]]++;
    }

    vector<int> vect;

    for(auto m : occurance) {
        int x = m.second;
        if(find(vect.begin(), vect.end(), x) != vect.end()) {
            return false;
        } else {
            vect.push_back(x);
        }
    }
    return true;
}*/

int main() {
    vector<int> arr = {1,2,2,1,1,3};
    if(uniqueOccurrences(arr)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}