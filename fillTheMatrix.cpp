// cpp program to find the minimum numbers of iterations requred to fill the whole with ones
// In on iteration, '1' can be filled in the 4 neighbouring elements of a cell containing '1'
// Input: N = 2, M = 3, X = 2, Y = 3
// Output: 3 
//Explanation: 3 is the minimum possible number of iterations in which the matrix can be filled.

#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int Ex, int Ey) {
    if(x < 1  || x >= Ex || y < 1 || y >= Ey) {
        return 0;
    } else {
        return 1;
    }
}

int minIteration(int N, int M, int x, int y){    
    // code here
    queue<pair<int,int>> q;
    vector<vector<int>> visited(N+1, vector<int>(M+1, 0));
    visited[x][y] = 1;
    q.push({x, y});
    int count = 0;
    
    int Ex = N+1;
    int Ey = M+1;
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int mx = a + dx[i];
                int my = b + dy[i];
                
                if(isValid(mx,my,Ex,Ey) && visited[mx][my] == 0) {
                    q.push({mx, my});
                    visited[mx][my] = 1;
                }
            }
        }
        count++;
        
    }
    return count-1;
}

int main() {
    int N, M;
    N = 2, M = 3;
    int X, Y;
    X = 2, Y = 3;

    std::cout << "Minimum numbers of iterations required to fill the whole matrix with ones: " << minIteration(N, M, X, Y) << std::endl;
}
