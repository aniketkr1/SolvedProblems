/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
Input: N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output: 0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<vector<int>> adj[N];
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> distance(N, INT_MAX);
        distance[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(auto u : adj[node]) {
                int v = u[0];
                int wt = u[1];
                if(distance[node] + wt < distance[v]) {
                    distance[v] = wt + distance[node];
                    q.push(v);
                }
            }
        }
        for(auto &v : distance) {
            if(v == INT_MAX) {
                v = -1;
            }
        }
        return distance;
    }

int main()
{
    int N = 6;
    int M = 7;
    vector<vector<int>> edge = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> ans = shortestPath(N, M, edge);
    for (auto a : ans) {
        std::cout << a << " ";
    }
}