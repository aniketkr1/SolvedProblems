/*
cpp program to check if N is a power of 2. More formally, check if N can be expressed as 2^x for some integer x.
Input: N = 8
Output: YES
Explanation: 8 is equal to 2 raised to 3 (23 = 8). 
*/

#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
    if(n == 0) {
        return 0;
    }
    // if during any iteration, remainder is non-zero then number is not power of two, return false.
    while(n != 1) {
        if(n%2 != 0) {
            return 0;
        }
        n = n/2;
    }
    return 1;
    
}

int main() {
    long long n = 256;
    if(isPowerofTwo(n)) {
        std::cout << "isPowerofTwo: YES" << std::endl; 
    } else {
        std::cout << "isPowerofTwo: NO" << std::endl;
    }
}