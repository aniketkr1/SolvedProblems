// cpp program to check wheter a path exist from source to destination or not
// You can traverse up, down, right and left.
// The description of cells is as follows:
// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall.
// There are only a single source and a single destination.
// // Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0 
// 3 0 0 0 3 
// 3 3 3 3 3 
// 0 2 3 0 0 
// 3 0 0 1 3 
// There is no path to reach at (3,1) that is (2) i,e at destination from (4,3) that is (1) i,e source.

#include<bits/stdc++.h>
using namespace std;

// it check whether a positon is valid or not
bool isValid(int x, int y, int n) {
    if(x < 0 || x >= n || y < 0 || y >= n) {
        return 0;
    } 
    return 1;
}

bool is_Possible(vector<vector<int>>& grid) 
{
    //code here
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n,0));
    queue<pair<int,int>> q;
    
    // finding source which is 1 here 
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] == 1) {
                q.push({i,j});
                visited[i][j] = 1;
                break;
            }
        }
    }
    
    // by using this we can check all the 4 positions 
    // left, right, top, down of a particular cell
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    // using BFS traversal
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // after getting cell cordinates we check left, right, up and down of that cordinate
        for(int i = 0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            // check the position is valid or not and checking if its already visited or not
            // if that cell is not visited then only we will proceed further
            if(isValid(nx, ny, n) && !visited[nx][ny]) {
                if(grid[nx][ny] == 2) {
                    return 1;
                } 
                if(grid[nx][ny] == 3) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;    // making that cell as visited
                }
            } 
        }
        
    }
    return 0;
}

int main() {
    vector<vector<int>> grid = {{3,0,3,0,0},
                                {3,0,0,0,3},
                                {3,3,3,3,3},
                                {0,2,3,3,0},
                                {3,0,0,1,3}};

    if(is_Possible(grid)) {
        std::cout << "It is possible to reach destination from source" << std::endl;
    } else {
        std::cout << "It is not possible to reach desionation from source" << std::endl;
    }                        
}