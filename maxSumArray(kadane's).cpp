// cpp program to find largest continguous subarray
#include<iostream>
#include<limits.h>
// kadane's algorithms
int maxSumSubArray(int arr[], int n)
{
    
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        currSum = currSum + arr[i];
        if(currSum > maxSum)
        {
            maxSum = currSum;
        }
        if(currSum<0)
        {
            currSum = 0;
        }
    }
    
    return maxSum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int l = sizeof(arr)/sizeof(arr[0]);
    int maxSum = maxSumSubArray(arr, l);
    std::cout << "Maximum sum of sub array = " << maxSum;
}