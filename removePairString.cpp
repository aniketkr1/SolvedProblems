// cpp program to find the remove all the consecutive duplicate pairs and concatenate 
// the remaining string to replace the original string
// our task is to find the string with minimum length after applying the above operations
// we can apply the operation any number of times
// Input: "aaabbaaccd"
// Output: "ad"
//Explanation: 
//Remove (aa)abbaaccd =>abbaaccd
//Remove a(bb)aaccd => aaaccd
//Remove (aa)accd => accd
//Remove a(cc)d => ad

#include<bits/stdc++.h>
using namespace std;

string removePair(string s) {
    
    stack<char> st;
    string ans = "";
    for(int i = 0; i<s.length(); i++) {
        st.push(s[i]);
    }
    while(!st.empty()) {
        char t1 = st.top();
        st.pop();
        if(t1 == ans.back()) {
            ans.pop_back();
        } else {
            ans = ans + t1;
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans.length() == 0) {
        return "-1";
    }
    return ans;
}

int main() {
    string s = "bbdaccabb";
    std::cout << "The string = " << removePair(s);
}