/*Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once.

Input:
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output:
{{0,0}}
Explanation:
From (0,0) we can find "abc" in horizontally right direction.
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool check(vector<vector<char>> grid, vector<vector<int>> steps, int i, int j, string word)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int x = 0; x < steps.size(); x++)
    {
        int dx = i;
        int dy = j;
        int count = 1;
        for (int y = 1; y < word.size(); y++)
        {
            dx = dx + steps[x][0];
            dy = dy + steps[x][1];

            if (isValid(dx, dy, n, m))
            {
                if (grid[dx][dy] == word[y])
                {
                    count++;
                }
            }
            else
            {
                break;
            }
        }
        if (count == word.size())
        {
            return true;
        }
    }
    return false;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
    vector<vector<int>> ans;
    char firstChar = word[0];
    vector<vector<int>> steps = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == firstChar)
            {
                if (check(grid, steps, i, j, word))
                {
                    ans.push_back({i, j});
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> grid = {{'d', 'a', 'b', 'b', 'e', 'd', 'e', 'd', 'a', 'a', 'd'},
                                 {'a', 'e', 'e', 'd', 'e', 'c', 'd', 'b', 'a', 'e', 'a'},
                                 {'a', 'e', 'c', 'a', 'e', 'a', 'b', 'e', 'd', 'e', 'c'},
                                 {'e', 'e', 'b', 'a', 'a', 'd', 'c', 'd', 'b', 'b', 'e'},
                                 {'b', 'e', 'c', 'b', 'a', 'e', 'c', 'a', 'a', 'a', 'a'},
                                 {'c', 'd', 'e', 'a', 'a', 'c', 'a', 'e', 'e', 'c', 'c'},
                                 {'a', 'b', 'b', 'c', 'd', 'c', 'd', 'e', 'a', 'd', 'c'}};

    vector<vector<char>> grid1 = {{'a', 'b', 'a', 'b'}, {'a', 'b', 'e', 'b'}, {'e', 'b', 'e', 'b'}};
    string word = "cbdec";
    string word1 = "abe";
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans = searchWord(grid1, word1);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i][0] << "," << ans[i][1] << std::endl;
    }
}