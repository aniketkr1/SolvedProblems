// cpp program to find the missing and repeating in an unsorted array
// one number 'A' from set {1, 2, N} is missing and one number 'B' occurs twice in array
// Input:N = 2, Arr[] = {2, 2}
// Output: 2 1
//Explanation: Repeating number is 2 and 
//smallest positive missing number is 1

#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
    // code here
    int *res = new int[2];
    sort(arr, arr+n);
    long long int N = n;
    
    for(int i = 0; i<N; i++) {
        if(arr[i] == arr[i+1]) {
            res[0] = arr[i];
            arr[i] = 0;
            break;
        }
    }
    
    long long fsum = (N*(N+1))/2;
    long long sum = 0;
    for(int i = 0; i<N; i++) {
        sum += arr[i];   
    }
    
    res[1] = fsum - sum;
    
    return res;
}

int main() {
    int arr[] = {1,2,3,3,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *res = findTwoElement(arr, n);
    std::cout << "Repeating: " << res[0] << "\nMissing: " << res[1];
}