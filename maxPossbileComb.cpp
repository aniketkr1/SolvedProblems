// cpp program to find the maximum possible number
// after combining the array of strings
#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    return a+b > b+a;
}

int main() {
    vector<string> v = {"3", "30", "34", "5", "9"};
    sort(v.begin(), v.end(), compare);
    
    string result = "";
    for(auto k : v) {
        result += k;
    }

    std::cout << "Result = " << result;
    
}   
