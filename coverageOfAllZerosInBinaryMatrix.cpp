/*
Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:
Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input:
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
*/
#include<bits/stdc++.h>
using namespace std;

int returnNoOfOne(vector<vector<int>>& matrix, int a, int b, int n, int m) {
    int count = 0;
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,-1,0,1 };

    for (int i = 0; i < 4; i++) {
        int mx = dx[i] + a;
        int my = dy[i] + b;

        if (mx >= 0 && mx < n && my >= 0 && my < m) {
            if (matrix[mx][my] == 1) {
                count++;
            }
        }
    }
    return count;
}

int findCoverage(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                count += returnNoOfOne(matrix, i, j, n, m);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> matrix = { {0, 1, 0},
                                    {0, 1, 1},
                                    {0, 0, 0} };
    std::cout << "Total coverage: " << findCoverage(matrix);
}