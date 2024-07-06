/*
The Palindrome Pattern Difficulty: Hard
Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:
Input:
arr[][] =  [[1, 0, 0],
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome
occuring in a row having index 1.

Input:
arr[][] =   [[1, 0],
           [1, 0]]
Output: 0 C
Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {

    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }

    return true;
}

string pattern(vector<vector<int>>& arr) {
    string ans = "";
    string str;
    for (int i = 0; i < arr.size(); i++) {
        str = "";
        for (int j = 0; j < arr[i].size(); j++) {
            str += (arr[i][j] + '0');
        }

        if (isPalindrome(str)) {
            return to_string(i) + " R";
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        str = "";
        for (int j = 0; j < arr[i].size(); j++) {
            str += (arr[j][i] + '0');
        }
        if (isPalindrome(str)) {
            return to_string(i) + " C";
        }
    }

    return "-1";
}

int main() {
    vector<vector<int>> arr = { {1, 0, 0},
                                {0, 1, 0},
                                {1, 1, 0}};
    
    std::cout << "Output: " << pattern(arr) << std::endl;
}