// cpp program to check if the given string follow the same pattern 
// Here follow means a full match, such that there is a bijection 
// between a letter in pattern and a non-empty word in s.
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Explanation: a --> dog, b --> cat, b --> cat, a --> dog
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Explanation: a --> dog, b --> cat, b -->cat, a --> fish
// here a is pointing to 2 different objects and don't follow patter

#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> vs;
    string word = "";
    for(auto x : s) {
        if(x == ' ') {
            vs.push_back(word);
            word = "";
        } else {
            word = word + x;
        }
    }
    vs.push_back(word);

    if(pattern.length() != vs.size()) {
        return false;
    }
    for(int i = 0; i<pattern.size()-1; i++) {
        for(int j = i+1; j<pattern.size(); j++) {
            if(pattern[i] != pattern[j] && vs[i] == vs[j]) {
                return false;
            }
            if(pattern[i] == pattern[j] && vs[i] != vs[j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";
    bool ans = wordPattern(pattern, s);
    if(ans) {
        std::cout << "Pattern matched";
    } else {
        std::cout << "Pattern don't matched";
    }
}