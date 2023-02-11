// cpp program to  minimuze the sum 
// we can remove any two elements from the list, note their sum, and add the sum to the list
// Repeat these steps while there is more than a single element in the list
// The task is to minimize the sum of these chosen sums.
// Input: {1, 4, 7, 10}
// Output: 39
// Explaination: we choose two elements from the list {1, 4} sum = 5 and minimizedSum = 5
// we add 5 to the list and list become {5, 7, 10} and again we  select two lements from the list {5, 7}
// sum = 12 we add 12 to the list and list become {12, 10} and minimizedSum = 5+(5+7) = 17
// again we add two elements from the list {12, 10} sum = 22 and we add 22 to the list and list become {22}
// and minimizedSum = 17+22 = 39 and now there is only one elements in the list so we return the minimizedSum

#include<bits/stdc++.h>
using namespace std;

int minimizeSum(int N, vector<int> arr) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i<arr.size(); i++) {
        pq.push(arr[i]);
    }
    int finalSum = 0;
    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a+b;
        pq.push(sum);
        finalSum += sum;
    }
    return finalSum;
}

int main() {
    vector<int> nums {1, 4, 7, 10};
    int n = nums.size();
    std::cout << "Minimum sum = " << minimizeSum(n, nums) << std::endl;
}