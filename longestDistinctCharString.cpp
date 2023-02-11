// cpp program to find the longest substring with all distinct character
// S = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest 
// substring with all distinct characters

#include<bits/stdc++.h>
using namespace std;

int longestSubstrDistinctChars (string S)
{
    // your code here
    vector<char> st;
    int largest = 0;
    for(int i = 0; i<S.length(); i++) {
        // element found
        std::vector<char>::iterator it;
        it = std::find (st.begin(), st.end(), S[i]);
        if(it != st.end()) {
            if(largest < st.size()) {
                largest = st.size();
            }
            while(st.front() != S[i]) {
                st.erase(st.begin());
            }
            st.erase(st.begin());
            st.push_back(S[i]);
        } else {
            st.push_back(S[i]);
        }
    }
    if(st.size() > largest) {
        largest = st.size();
        return largest;
    } else 
    return largest;
}

int main() {
    string S = "mynameisaniket";
    int res = longestSubstrDistinctChars(S);
    std::cout << "Length of the longest substring with all characters are distinct: " << res << std::endl;
}