/*
60. Permutation Sequence (Hard)

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

Example 3:
Input: n = 3, k = 1
Output: "123"
*/

#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> number;
    int fact = 1;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        number.push_back(i);
    }
    number.push_back(n);
    k = k - 1;
    string ans = "";
    while (true) {
        ans += to_string(number[k / fact]);
        number.erase(number.begin() + k / fact);
        if (number.size() == 0) {
            break;
        }
        k = k % fact;
        fact = fact / number.size();
    }
    return ans;
}

int main() {
    int n = 3, k = 3;
    std::cout << k << "th permutation sequence: " << getPermutation(n, k);

}