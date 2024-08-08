/*
51. N-Queens (Hard)
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

.Q..
...Q
Q...
..Q.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    int uprow = row;
    int upcol = col;
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = uprow;
    col = upcol;
    while (col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    row = uprow;
    col = upcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
/*
void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}*/

// optimal solution

void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q'; // Place queen
            leftRow[row] = 1; // Mark row as occupied
            lowerDiagonal[row + col] = 1; // Mark lower diagonal as occupied
            upperDiagonal[n - 1 + col - row] = 1; // Mark upper diagonal as occupied
            
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // Recur
            
            // Backtrack
            board[row][col] = '.'; // Remove queen
            leftRow[row] = 0; // Unmark row
            lowerDiagonal[row + col] = 0; // Unmark lower diagonal
            upperDiagonal[n - 1 + col - row] = 0; // Unmark upper diagonal
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0),
        lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}

/*
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    int index = 0;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
*/

int main() {
    int n = 4;
    vector<vector<string>> ans = solveNQueens(4);
    for (auto row : ans) {
        std::cout << "Answer: " << std::endl;
        for (auto e : row) {
            std::cout << e << std::endl;
        }
        std::cout << endl;
    }

}