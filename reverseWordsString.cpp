// cpp program to reverse the words in a string and the words are separated by a single space only
// Input: s = "the sky is blue"
//Output: "blue is sky the"
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: reversed string should not contain leading or trailing spaces.
//Input: s = "a good   example"
//Output: "example good a"

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string ans = "";
    string str = "";
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == ' ') {
            if(str.length() != 0) {
                ans = " " + str + ans;
                str = "";
            }
            
        } else {
            str = str + s[i];
        }
    }
    ans = str + ans;
    if(ans[0] == ' ') {
        ans.erase(0,1);
    }
    return ans;
}


int main() {
    string s = "the sky is blue";
    string res = reverseWords(s);
    std::cout << "The string: " << res;
}