// cpp program to add two numbers represented as string
#include<iostream>
#include<algorithm>
using namespace std;

string summation(string X, string Y) {

    string ans = "";
    int i = X.size() - 1;
    int j = Y.size() - 1;

    int sum = 0;
    while(i >= 0 || j >= 0) {

        if(i>=0) {
            sum = sum + (X[i] - '0');
        }
        if(j>=0) {
            sum = sum + (Y[j] - '0');
        }

        int digit = sum%10;
        ans = ans + to_string(digit);
        sum = sum/10;
        i--, j--;
    }

    if(sum > 0) {
        ans = ans + to_string(sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;

}


int main() {

    string num1 = "100";
    string num2 = "7";

    string ans = summation(num1, num2);
    std::cout << "Sum = " << ans;

}