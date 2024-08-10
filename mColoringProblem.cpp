/*
M-Coloring Problem (Medium)
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:
Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.

Example 2:
Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0

Note: In Example there are Edges not the graph.Graph will be like, if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.Function will be contain 2-D graph not the edges.

Expected Time Complexity: O(M^N).
Expected Auxiliary Space: O(N).
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(bool graph[101][101], int vertex, int col, int n, int color[]) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && color[i] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int vertex, bool graph[101][101], int m, int n, int color[]) {
    if (vertex >= n) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isValid(graph, vertex, i, n, color)) {
            color[vertex] = i;
            if (solve(vertex + 1, graph, m, n, color)) {
                return true;
            }
            color[vertex] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = { 0 };
    return solve(0, graph, m, n, color);

}

int main() {
    bool graph[101][101] = {{0,1,1,1},
                            {1,0,1,0},
                            {1,1,0,1},
                            {1,0,1,0}};
    int m = 3; // number of colours
    int n = 4; // number of vertices

    if(graphColoring(graph, m,n)) {
        std::cout << "It is possible the color the graph with " << m << " colors" << std::endl;
    } else {
        std::cout << "It is not possible the color the graph with " << m << " colors" << std::endl;
    }

}