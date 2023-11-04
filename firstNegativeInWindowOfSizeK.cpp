/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
Input : N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
Output : -8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans(N - K + 1, 0);
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
    }

    for (int i = K - 1; i < N; i++)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
        while (!q.empty() && q.front() < i - K + 1)
        {
            q.pop();
        }
        if (!q.empty())
        {
            ans[i - K + 1] = A[q.front()];
        }
    }
    return ans;
}

int main() {
    long long  N = 8;
    long long  A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long  K = 3;
    vector<long long> ans = printFirstNegativeInteger(A, N, K);
    std::cout << "Output: " << std::endl;
    for(auto v : ans) {
        std::cout << v << " ";
    }
}