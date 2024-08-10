/*
    37. Sudoku Solver
Solved
Hard
Topics
Companies
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
------+-------+-------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . 1 .
7 . . | . 2 . | . . 6
------+-------+-------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . 5 .
. . . | 8 . . | 7 9 .

Example 1:
Input: board = [['5','3','.','.','7','.','.','.','.'],['6','.','.','1','9','5','.','.','.'],['.','9','8','.','.','.','.','6','.'],['8','.','.','.','6','.','.','.','3'],['4','.','.','8','.','3','.','.','1'],['7','.','.','.','2','.','.','.','6'],['.','6','.','.','.','.','2','8','.'],['.','.','.','4','1','9','.','.','5'],['.','.','.','.','8','.','.','7','9']]

5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+-------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+-------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9

Output: [['5','3','4','6','7','8','9','1','2'],['6','7','2','1','9','5','3','4','8'],['1','9','8','3','4','2','5','6','7'],['8','5','9','7','6','1','4','2','3'],['4','2','6','8','5','3','7','9','1'],['7','1','3','9','2','4','8','5','6'],['9','6','1','5','3','7','2','8','4'],['2','8','7','4','1','9','6','3','5'],['3','4','5','2','8','6','1','7','9']]

Explanation: The input board is shown above and the only valid solution is shown below:
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int row, int col, vector<vector<char>>& board, int n, char val) {

    // check for row
    for (int i = 0; i < n; i++) {
        if (board[row][i] == val) {
            return false;
        }
    }
    // check for col
    for (int i = 0; i < n; i++) {
        if (board[i][col] == val) {
            return false;
        }
    }

    // checking for submatrix of 3x3
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}
bool solve(int row, int col, vector<vector<char>>& board, int n) {
    // we are able to traverse every row and fill the cells and got an answer
    if (row == n) {
        return true;
    }
    // move to next row and start from column index = 0
    if (col == n) {
        return solve(row + 1, 0, board, n);
    }
    // ignoring the cell if it's already filled and checking for next cell(col+1)
    if (board[row][col] != '.') {
        return solve(row, col + 1, board, n);
    }
    // if cell is empty checking for every possible value from 1 to 9
    for (char val = '1'; val <= '9'; val++) {
        if (check(row, col, board, n, val)) {
            // if satisfies all conditions than fill the cell 
            board[row][col] = val;
            // if the solve function return true that means we got an answer
            if (solve(row, col + 1, board, n) == true) {
                return true;
            }
            // backtracking(empty the cell)
            board[row][col] = '.';
        }
    }
    return false;
}

/*
bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (check(i, j, board, board.size(), val)) {
                        board[i][j] = val;
                        if (solve(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
*/

int main() {
    vector<vector<char>>  board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'} };
    int n = board.size();
    solve(0, 0, board, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}