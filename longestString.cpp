// cpp program to find the longest string which is lexicographically smallest and
// also all of its prefix strings are already present in the array.
// prefix of "abc" = {"a", "ab", "abc"};
// Input: { ab, a, aa, abd, abc, abda, abdd, abde, abdab}
// Output: abdab {as all the prefix is present}

#include<bits/stdc++.h>
using namespace std;

string longestString(vector<string> &words)
{
    map<string, int> mp;
    for(int i = 0; i<words.size(); i++) {
        mp[words[i]];
    }
    string result = "";
    
    sort(words.begin(), words.end());
    for(int i = words.size()-1; i>=0; i--) {
        string s = words[i];
        int count = 0;
        for(int i = 1; i<s.length(); i++) {
            string r = s.substr(0,i);
            if(mp.find(r) != mp.end()) {
                // string found
                count++;
            }
        }
        if(count == s.length()-1) {
            
            if(result.length() <= s.length()) {
                result = s;
            }
        }
    }
    return result;
}

int main() {
    
    vector<string> v {"ab", "a", "abc", "abd"};
    string s = longestString(v);
    std::cout << "Longest Strin: " << s << std::endl;
    
}
