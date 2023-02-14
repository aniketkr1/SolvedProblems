// cpp program to convert roman numbers into integers
// Input: "XIV";
// Output: 14

#include<bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
    // code here
    int num = 0;
    map<char,int> roman;
    roman.insert({'M', 1000});
    roman.insert({'D', 500});
    roman.insert({'C', 100});
    roman.insert({'L', 50});
    roman.insert({'X', 10});
    roman.insert({'V', 5});
    roman.insert({'I', 1});
    
    for(int i = 0; i<str.length(); i++) {
        if(roman[str[i]] < roman[str[i+1]]) {
            num = num + (roman[str[i+1]] - roman[str[i]]);
            i++;
        } else {
            num = num + roman[str[i]];
        }
    }
    return num;
}

int main() {
    string roman = "XIV";
    std::cout << roman << " = " << romanToDecimal(roman);
}