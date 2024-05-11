/*
cpp program to convet a 12hr format to 24hr format time

Example 1:
Input: 01:24:22PM
Output: 13:24:22

*/
#include<bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    int n = s.length();
    if(s[n-2] == 'A' && s[0] == '1' && s[1] == '2') {
        s[0] = '0';
        s[1] = '0';
        return s.substr(0, 8);
    } else if(s[n-2] == 'P' && s[0] == '1' && s[1] == '2') {
        return s.substr(0, 8);
    } else if(s[n-2] == 'A') {
        return s.substr(0, 8);
    } else if(s[n-2] == 'P') {
        int hour = int(s[0] - '0')*10 + int(s[1] - '0');
        hour += 12;
        string str = to_string(hour);
        s[0] = str[0];
        s[1] = str[1];
    }
    return s.substr(0,8);
}

int main() {
    string time_12hr = "01:40:22PM";
    string time_24hr = timeConversion(time_12hr);
    std::cout << "Time in 24 hour Format: " << time_24hr << std::endl;
}