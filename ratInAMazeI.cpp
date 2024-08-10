/*
Rat in a Maze Problem - I (Medium)

Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:
Input: mat[][] = [[1, 0, 0, 0],
                  [1, 1, 0, 1],
                  [1, 1, 0, 0],
                  [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int row, int col, string path, vector<vector<int>>& mat,
    vector<vector<int>>& visited, vector<string>& ans, int dx[], int dy[], string directions, int n) {
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && mat[nx][ny] == 1) {
            visited[nx][ny] = 1;
            solve(nx, ny, path + directions[i], mat, visited, ans, dx, dy, directions, n);
            visited[nx][ny] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<string> ans;
    if (mat[n - 1][n - 1] == 0) {
        ans.push_back("-1");
        return ans;
    }
    string path = "";
    int dx[4] = { 1, 0, 0, -1 };
    int dy[4] = { 0, -1, 1, 0 };
    string directions = "DLRU";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (mat[0][0] == 1) {
        visited[0][0] = 1;
        solve(0, 0, "", mat, visited, ans, dx, dy, directions, n);
    }
    return ans;

}
int main() {
    vector<vector<int>> mat =  {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    std::cout << "Possible Paths: ";
    for(const auto& path : ans) {
        std::cout << path << " ";
    }
}