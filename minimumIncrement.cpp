// cpp program to find the minimum number of increment operations 
//required to make all the elements of the array unique. 
//menas no value in the array should occur more than once. 
//In an operation a value can be incremented by 1 only.
// Input: {1, 2, 2, 3};
// Output: 2  
// Explaination: if we perform increment operation once on 2 it becomnes 3
// and 3 is already present in the array so perform increment operation once again
// we get 4 and 4 is unique now so there are two minimum operation required to make
// all the elments unique and these is no duplicates.

#include<bits/stdc++.h>
using namespace std;

long long int minIncrements(vector<int> arr, int N) {
    // Code here
    sort(arr.begin(), arr.end());
    long long int increment = 0;
    map<int, int> m;
    for(int i = 0; i<arr.size(); i++) {
        m[arr[i]]++;
    }
    for(int i = 0; i<N-1; i++) {
        if(arr[i] == arr[i+1]) {
            int j = 1;
            while(m.find(arr[i]+j) != m.end()) {
                j++;
            }
            increment += j;
            m[arr[i]+j]++;
        }
    }
    return increment;
}

int main() {
    vector<int> v {1, 2, 2, 3};
    int n = v.size();
    int increment = minIncrements(v, n);
    std::cout << "Minimum number of increment operation required to make all the elements unique: " << increment;
}