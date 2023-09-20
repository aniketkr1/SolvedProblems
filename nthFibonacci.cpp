// cpp program to print nth fibonacci number
#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n) {
    vector<int> fibonacci(n+1, 0);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for(int i = 2; i<=n; i++) {
        fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2])%1000000007;
    }
    return fibonacci[n];
}

int main() {
    int n = 5;
    int f = nthFibonacci(n);
    std::cout << n <<"thFibonacci: " << f << std::endl;
}