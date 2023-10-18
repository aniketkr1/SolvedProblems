/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Input: 
7 7 // number of nodes ans edges
0 1
0 2
1 2
1 3
3 0
4 5
2 5
Output: 2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vector<int> degree(V, 0);
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < V; i++)
    {
        degree[i] = adj[i].size();
        for (auto v : adj[i])
        {
            adjList[v].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> safeNodes;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (auto v : adjList[node])
        {
            degree[v]--;
            if (degree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main()
{
    int V = 7;
    vector<int> adj[] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = eventualSafeNodes(V, adj);
    for (auto v : ans)
    {
        std::cout << v << " ";
    }
}