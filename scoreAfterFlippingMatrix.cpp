/*
861. Score After Flipping Matrix (Medium)

You are given an m x n binary matrix grid.
A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
Return the highest possible score after making any number of moves (including zero moves).

Example 1:
Initial state:
0 0 1 1
1 0 1 0
1 1 0 0

Step 1:
1 1 0 0
1 0 1 0
1 1 0 0

Step 2:
1 1 0 0
1 0 0 0
1 1 1 0

Step 3:
1 1 1 1 = 15
1 0 0 1 = 9
1 1 1 1 = 15

Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Example 2:
Input: grid = [[0]]
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string n) {
    string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

void flipCol(vector<vector<int>>& grid, int c, int n) {

    for (int i = 0; i < n; i++) {
        if (grid[i][c] == 0) {
            grid[i][c] = 1;
        }
        else {
            grid[i][c] = 0;
        }
    }
}

void flipRow(vector<vector<int>>& grid, int r, int m) {

    for (int i = 0; i < m; i++) {
        if (grid[r][i] == 0) {
            grid[r][i] = 1;
        }
        else {
            grid[r][i] = 0;
        }
    }
}

// There are only two rules that you need to know in this problem. If the first number in the row is 0, flip the row. 
// If the count of 0 in the col is greater than the count of 1, flip the col. Easy peasy
int matrixScore(vector<vector<int>>& grid) {
    int score = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
            flipRow(grid, i, m);
        }
    }

    int j = 0;
    for (int i = 0; i < m; i++) {
        int zeroCount = 0;
        int oneCount = 0;
        for (j = 0; j < n; j++) {
            if (grid[j][i] == 0) {
                zeroCount++;
            }
            else {
                oneCount++;
            }
        }

        if (zeroCount > oneCount) {
            flipCol(grid, i, n);
        }
    }

    for (int i = 0; i < n; i++) {
        string num = "";
        for (int j = 0; j < m; j++) {
            num += (grid[i][j] + '0');
        }
        score += binaryToDecimal(num);
    }
    return score;
}

int main() {
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    std::cout << "Highest possible score: " << matrixScore(grid) << std::endl;
}