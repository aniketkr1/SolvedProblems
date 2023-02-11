// cpp program to find the minimum possible sum of two numbers formed using 
//the elements of the array. All digits in the given array must be used to form the two numbers
// an array Arr of size N such that each element is from the range 0 to 9
// Input: {6, 8, 4, 5, 2, 3}
// Output: 604 {The two numbers are 358 and 246}

#include<bits/stdc++.h>
using namespace std;

string solve(int arr[], int n) {
    sort(arr, arr+n);
    string ans;
    int i = n-1;
    int carry = 0;
    while( i >= 0 ) {
        int num1 = arr[i--];
        int num2 = 0;
        if(i >= 0) {
            num2 = arr[i--];
        }
        int sum = num1 + num2 + carry;
        if(sum >9) {
            carry = sum/10;
            sum = sum%10;
        } else {
            carry = 0;
        }
        ans = ans + to_string(sum);
    }
    
    if(carry > 0) {
        ans.push_back(carry+'0');
    }
    
    while(ans.back()=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main() {
    int Arr[] = {5, 3, 0, 7, 4};
    int n = sizeof(Arr)/sizeof(Arr[0]);

    std::cout << "minimum sum = " << solve(Arr, n);
}