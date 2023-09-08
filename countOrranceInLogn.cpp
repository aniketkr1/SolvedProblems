/*
    cpp program to find the number of occurrences of X in Arr in a sorted array Arr of size N in log(n) time.
    Input:
    N = 7, X = 2
    Arr[] = {1, 1, 2, 2, 2, 2, 3}
    Output: 4
    Explanation: 2 occurs 4 times in the given array.
*/
#include <bits/stdc++.h>
using namespace std;
int count(int arr[], int n, int x)
{
    int low, high, first, last;
    low = 0;
    high = n - 1;
    first = last = -1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else
        {
            if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    if (first == -1)
    {
        return 0;
    }
    low = 0, high = n - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else
        {
            if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return last - first + 1;
}

int main()
{
    int n = 21, x = 7;
    int arr[] = {7, 7, 7, 7, 9, 11, 12, 14, 15, 16, 17, 18, 18, 18, 18, 18, 19, 19, 20, 21, 23};
    std::cout << "Occurance: " << count(arr, n, 7) << std::endl;
}