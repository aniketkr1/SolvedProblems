// cpp program to find the numeric code of a string
// reference is a keypad phone
#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char, string>  m = { {'A', "2"}, {'B', "22"}, {'C', "222"}, {'D', "3"}, {'E', "33"}, {'F', "333"}, {'G', "4"}, {'H', "44"}
    , {'I', "444"}, {'J', "5"}, {'K', "55"}, {'L', "555"}, {'M', "6"}, {'N', "66"}, {'O', "666"}, {'P', "7"}, {'Q', "77"}, {'R', "777"}
    , {'S', "7777"}, {'T', "8"}, {'U', "88"}, {'V', "888"}, {'W', "9"}, {'X', "99"}, {'Y', "999"}, {'Z', "9999"}, {' ', "0"} };
    

    string s = "HEY U";
    string result = "";
    for(int i = 0; i<s.length(); i++) {
        result = result + m[s[i]];
    }
    std::cout << "result = " << result << std::endl;
}   
