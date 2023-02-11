// cpp program to check validate IPv4 Address
// generalized IPv4 Address: (0-255).(0-255).(0-255).(0-255)
// Input: 222.111.111.111
// Output: 1 (1 means it is valid IPv4 Address, 0 menas it is not valid IPv4 Address)

#include<bits/stdc++.h>
using namespace std;

int isValid(string s) {
    // code here
    int dot = 0;
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == '.') {
            dot++;
        }
    }
    vector<char> store {'.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i<s.length(); i++) {
        if(find(store.begin(), store.end(), s[i]) == store.end()) {
            return 0;
        }
    }
    if(dot == 3) {
        string num = "";
        s.push_back('.');
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == '.') {
                if(num == "") {
                    return 0;
                }
                //std::cout << "number = " << num << std::endl;
                int myInt = stoi(num);
                if(myInt == 0 && num.size() >1) {
                    return 0;
                }
                if((myInt <=9 && myInt >= 0) && num.length() >1) {
                    return 0;
                }
                if((myInt <= 99 && myInt >= 10) && num.length() >2) {
                    return 0;
                }
                if((myInt <= 255 && myInt >= 100) && num.length() >3) {
                    return 0;
                }
                if(myInt <= 255 && myInt >= 0) {
                    num = "";
                } else return 0;
            } else {
                num += s[i];
            }
        }
        return 1;
    } else return 0;    
}


int main() {
    string s = "233.45.23.89";
    int res = isValid(s);
    std::cout << res << std::endl;
}