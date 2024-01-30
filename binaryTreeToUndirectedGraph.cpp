// cpp program to convert a given binary tree into a undirected graph
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

void inorderTraversal(Node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
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

int main() {
    vector<int> tree = {1,5,3,-1,4,10,6,9,2};
    Node *root = createBinaryTree(tree, 0);

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    unordered_map<int, vector<int>> graph;

    binaryTreeToGraph(root, graph);

    std::cout << "Graph: " << endl;
    for(const auto &entry : graph) {
        std::cout << entry.first << " -> ";
        for(int val : entry.second) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }

}