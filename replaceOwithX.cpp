/* Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.
A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.
Input:
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Output:
ans = {{'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
bool isBoundry(int i, int j, int n, int m)
{
    return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // bfs traversal
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isBoundry(i, j, n, m) && mat[i][j] == 'O')
            {
                q.push({i, j});
                mat[i][j] = 'N';
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int x1 = x + dx[d];
                        int y1 = y + dy[d];
                        if (isValid(x1, y1, n, m) && mat[x1][y1] == 'O')
                        {
                            q.push({x1, y1});
                            mat[x1][y1] = 'N';
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'N')
            {
                mat[i][j] = 'O';
            }
            else if (mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}
int main()
{
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'X', 'O', 'O'}};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<char>> ans = fill(n, m, mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
}