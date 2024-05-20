/*
cpp program to find the number of minimum steps to reach from source A(0,0) to destination A(X,Y)
Note: You can only move left, right, up and down, and only through cells that contain 1.

Input:
N=3, M=4
A=[[1,0,0,0],
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
*/

#include <bits/stdc++.h>
using namespace std;
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {

    if (A[0][0] == 0 || A[X][Y] == 0) {
        return -1;
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    q.push({0, {0, 0}}); // staring point
    visited[0][0] = -1;  // marking (0,0) as visited

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int s = q.front().first;

        q.pop();

        if (x == X && y == Y) {
            return s;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            else {
                if (A[nx][ny] == 1 && visited[nx][ny] == 0) {
                    q.push({s + 1, {nx, ny}});
                    visited[nx][ny] = 1; // marking it as visited
                }
            }
        }
    }
    return -1;
}

int main() {
    int N = 3;
    int M = 4;
    vector<vector<int>> A = {{0, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 1, 1}};
    int X = 2;
    int Y = 3;
    std::cout << "Ans: " << shortestDistance(N, M, A, X, Y) << std::endl;
}