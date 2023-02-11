// cpp program to sort a given a string S consisting of only uppercase and lowercase characters
// The task is to sort uppercase and lowercase letters separately such that if the ith place in the
// original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.
// Input: N = 12 S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX

#include<bits/stdc++.h>
using namespace std;

string caseSort(string str, int n) {
    // your code here
    string s = str;
    int c = 0;
    int sm = 0;
    sort(s.begin(), s.end());
    for(int i = 0; i<n; i++) {
        if(s[i] > 'Z') {
            sm = i;
            break;
        }
    }
    for(int i = 0; i<n; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // capital
            str[i] = s[c];
            c++;
        } else {
            str[i]  = s[sm];
            sm++;
        }
    }
    return str;
}

int main() {
    string str = "deeIRSfrsTUX";
    int n = str.length();
    std::cout << "String after sorting: " << caseSort(str, n);
}