/*cpp program to check if there is a subarray with 0 sum
Input:5
4 2 -3 1 6
Output:
Yes
Explanation:
2, -3, 1 is the subarray
with sum 0.*/

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> st{0};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (st.find(sum) == st.end())
        {
            st.insert(sum);
        }
        else
        {
            return true;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, N))
    {
        std::cout << "Subarray exists" << std::endl;
    }
    else
    {
        std::cout << "Subarray don't exixts" << std::endl;
    }
}