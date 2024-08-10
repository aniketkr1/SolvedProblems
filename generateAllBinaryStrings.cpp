/*
Generate all binary strings (Medium)

Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.
A binary string is that string which contains only 0 and 1.

Example 1:
Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
*/

#include<bits/stdc++.h>
using namespace std;
void generateAllBinaryStrings(int k, string str, vector<string>& ans) {
    if(str.size() == k) {
        ans.push_back(str);
        return;
    }
    str.push_back('0');
    generateAllBinaryStrings(k, str, ans);
    str.pop_back();
    if(str[str.size()-1] == '1') {
        return;
    }
    str.push_back('1');
    generateAllBinaryStrings(k, str, ans);
}
int main() {
    int k = 3;
    vector<string> ans;
    generateAllBinaryStrings(k, "", ans);
    for(auto a : ans) {
        std::cout << a << " ";
    }

}