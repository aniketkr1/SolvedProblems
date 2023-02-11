// cpp progam to We check the usage of capitals in a word to be right when one of the following cases holds:
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Input: word = "INDIA"
// Output: true
// Input: word = "FlaG"
// Output: false

#include<bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) {
    if(word.size() == 1) {
        return true;
    }
    int capitalCount = 0;
    for(int i = 0; i<word.length(); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            capitalCount++;
        }
    }
    if(capitalCount == word.size()) {
        return true;
    } else if(capitalCount == 1 && (word[0] >= 'A' && word[0] <= 'Z')) {
        return true;
    } if(capitalCount == 0) {
        return true;
    } else return false;
}

int main() {
    string s = "HELLO";
    bool ans = detectCapitalUse(s); 
    if(ans) {
        std::cout << "Usage of capital is right";
    } else {
        std::cout << "usage of captial is not right";
    }
}