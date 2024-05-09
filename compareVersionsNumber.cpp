/*
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.
To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:
If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 
Example 1:
Input: version1 = "1.2", version2 = "1.10"
Output: -1
Explanation:
version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation:
Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:
Input: version1 = "1.0", version2 = "1.0.0.0"
Output: 0
Explanation:
version1 has less revisions, which means every missing revision are treated as "0".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stringToNumber(string num) {
        if (num == "") {
            return 0;
        }
        int len = num.length() - 1;
        int number = 0;
        for (int i = 0; i < num.length(); i++) {
            int n = char(num[i] - '0');
            number = number + n * (pow(10, (len--)));
            // std::cout << "Number: " << number << std::endl;
        }
        return number;
    }
    int compareVersion(string version1, string version2) {
        version1.push_back('.');
        version2.push_back('.');
        string str1 = "", str2 = "";
        int i = 0, j = 0;

        while (i < version1.length() || j < version2.length()) {
            while (version1[i] != '.' && i < version1.length()) {
                str1 += version1[i];
                i++;
            }
            while (version2[j] != '.' && j < version2.length()) {
                str2 += version2[j];
                j++;
            }

            int num1 = stringToNumber(str1);
            int num2 = stringToNumber(str2);
            str1 = "";
            str2 = "";

            if (num1 > num2) {
                return 1;
            }
            else if (num1 < num2) {
                return -1;
            }

            i++;
            j++;
        }

        return 0;
    }

};

int main() {
    string version1 = "1.0.3", version2 = "1.0.0.0";
    Solution s = Solution();
    int val = s.compareVersion(version1, version2);
    if(val == 1) {
        std::cout << "version1 > version1" << std::endl;
    } else if(val == -1) {
        std::cout << "version1 < version2" << std::endl;
    } else if(val == 0) {
        std::cout << "version1 = version2" << std::endl;
    }
}