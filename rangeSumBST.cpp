/*
Given the root Node of a binary search tree and two integers low and high, return the sum of values of all Nodes with a value in the inclusive range [low, high].

Example 1:
            10
           /  \
          5    15
        /  \     \ 
       3    7      18
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
                 10
               /    \
              5      15
            /  \     /  \
           3     7   13  18
          /      /
        1        6  
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
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
    // Base case: If the current index is out of bounds or the value is null (-1), return nullptr
    if (index >= arr.size() || arr[index] == -1) {
        return nullptr;
    }

    // Create a new Node with the value at the current index
    Node* root = new Node(arr[index]);

    // Recursively create the left and right subtrees
    root->left = createBinaryTree(arr, 2 * index + 1);
    root->right = createBinaryTree(arr, 2 * index + 2);

    return root;
}

void inorderTraversal(Node* root, int& sum, int low, int high) {
    if(root != NULL) {
        inorderTraversal(root->left, sum, low, high);
        if(root->data <= high && root->data >= low) {
            sum += root->data;
        }
        inorderTraversal(root->right, sum, low, high);
    }
}

int rangeSumBST(Node* root, int low, int high) {
    int sum = 0;
    inorderTraversal(root, sum, low, high);
    return sum;
}

int main() {
    std::vector<int> arr = {10,5,15,3,7,13,18,1,-1,6};
    int low = 6, high = 10;
    Node *root = createBinaryTree(arr, 0);
    std::cout << "Sum: " << rangeSumBST(root, low, high);

}