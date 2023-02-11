// cpp program to find the minimum number of time string A should be repeated such that
// string B is substring of it
//Input: A = "abcd", B = "cdabcdab"
//Output: 3
//Explanation:
//Repeating A three times (abcdabcdabcd),
//B is a substring of it. B is not a substring
//of A when it is repeated less than 3 times
//Input: A = "ab", B = "cab"
// Output : -1
//Explanation:
//No matter how many times we repeat A, we can't
//get a string such that B is a substring of it.

#include<bits/stdc++.h>
using namespace std;

int minRepeats(string A, string B) {
    // code here
    if(A == B) {
        return 1;
    }
    string temp = A;
    int counter = 1;
    while(A.length() < B.length()) {
        A = A + temp;
        counter++;
    }
    
    if(A.find(B) != -1) {
        return counter;
    }
    A = A + temp;
    counter++;
    if(A.find(B) != -1) {
        return counter;
    }
    return -1;
}

int main() {
    string A = "abcd";
    string B = "cdabcdab";
}