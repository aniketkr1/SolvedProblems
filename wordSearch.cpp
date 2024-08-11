/*
79. Word Search (Medium)

Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "ABCB"
Output: false
*/
#include<bits/stdc++.h>
using namespace std;

bool solve(int row, int col, int index, vector<vector<char>>& board, string word, int dx[], int dy[], int m, int n) {
    // we reach the end of string word that means we found the word
    if (index >= word.size()) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        // checking all 4 directions and if it is valid then then marking it with "#"
        // so that we don't visit it again
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == word[index]) {
            // making that cell as visited
            char temp = board[row][col];
            board[row][col] = '#';
            // recursive call on that cell where the character is matched
            // index will be index+1 (move the pointer to next character of the word)
            if (solve(nx, ny, index + 1, board, word, dx, dy, m, n) == true) {
                return true;
            }
            // backtrack(restore to origianl character so that we can check other possibilities)
            board[row][col] = temp;
        }
    }

    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    char start = word[0];
    int dx[4] = { 1, 0, 0, -1 };
    int dy[4] = { 0, -1, 1, 0 };
    // If any cell == first character of the word we will check
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == start) {
                if (solve(i, j, 1, board, word, dx, dy, m, n)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    string word = "ABCCED";
    if (exist(board, word)) {
        std::cout << word << " exist";
    }
    else {
        std::cout << word << " don't exist";
    }
}
