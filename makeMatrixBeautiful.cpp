#include <bits/stdc++.h>
using namespace std;

int findMinOpeartion(vector<vector<int>> matrix, int n)
{
    vector<int> rowSum(n, 0), colSum(n, 0);
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rowSum[i] += matrix[i][j];
            colSum[i] += matrix[j][i];
        }
        mx = max(rowSum[i], max(mx, colSum[i])); // finding the maximum
    }
    for (int it : rowSum)
    {
        ans += mx - it;
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 2, 3}, {3, 2, 1}};
    int n = matrix.size();
    std::cout << "Minimum Operations: " << findMinOpeartion(matrix, n);
}