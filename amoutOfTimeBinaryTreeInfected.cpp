/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:
         1
       /   \
      5     3
       \    / \
        4  10  6
       / \
      9   2
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
    1
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

 
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* createBinaryTree(const std::vector<int>& arr, int index) {
     if (arr.empty()) {
        return nullptr;
    }

    Node* root = new Node(arr[0]);
    std::queue<Node*> q;
    q.push(root);

    for (size_t i = 1; i < arr.size(); i += 2) {
        Node* current = q.front();
        q.pop();

        if (arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != -1) {
            current->right = new Node(arr[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}


void binaryTreeToGraph(Node *root, unordered_map<int, vector<int>> &graph) {
    if(root != NULL) {
        if(root->left != NULL) {
            graph[root->data].push_back(root->left->data);
            graph[root->left->data].push_back(root->data);
            binaryTreeToGraph(root->left, graph);
        }
        
        if(root->right != NULL) {
           
            graph[root->data].push_back(root->right->data);
            graph[root->right->data].push_back(root->data);
            binaryTreeToGraph(root->right, graph);
        }
    }
}

int amountOfTime(Node* root, int start) {
    unordered_map<int, vector<int>> graph;
    binaryTreeToGraph(root, graph);
    
    int minute = 0;
    unordered_set<int> visited;
    visited.insert(start);
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int levelSize = q.size();
        while(levelSize > 0) {
            int current = q.front();
            q.pop();
            for(int num : graph[current]) {
                if(visited.find(num) == visited.end()) {
                    visited.insert(num);
                    q.push(num);
                }
            }
            levelSize--;
        }
        minute++;
    }
    return minute-1;

}

int main() {
    vector<int> tree = {1,5,3,-1,4,10,6,9,2};
    int start = 3;
    Node *root = createBinaryTree(tree, 0);

    std::cout << "Number of Minutes for the entire tree to be infected: " << amountOfTime(root, start);

}