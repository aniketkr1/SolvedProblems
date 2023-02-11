// cpp program to check if s1 and s2 are anagrams or not
// An anagram of a string is another string that contains the same
// characters, only the order of characters can be different
// For example, “abcd” and “dabc” are an anagram of each other
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "apple";
    string s2 = "leapp";

    map<char, int> m1;
    map<char, int> m2;

    for(int i = 0; i<s1.length(); i++) {
        m1[s1[i]]++;
    }
    for(int i = 0; i<s2.length(); i++) {
        m2[s2[i]]++;
    }

    if(m1 == m2) {
        std::cout << "Both are anagrams";
    } else {
        std::cout << "Both are not anagrams";
    }
}