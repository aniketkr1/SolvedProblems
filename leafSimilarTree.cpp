/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
                   3
                /      \
              5         1
            /   \     /   \
           6     2   9     8
                /  \
               7    4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:
                 3                   3
               /   \               /    \ 
              5     1             5      1
            /  \   /  \         /   \   /  \ 
           6    2  9   8       6     7 4    2
               /  \                        /  \ 
              7    4                      9    8

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:
        1        1
       / \      /  \
      2   3    3    2

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 
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
void inorderTraversal(Node *root, vector<int> &nums) {
    if(root != NULL) {
        inorderTraversal(root->left, nums);
        if(root->left == NULL && root->right == NULL) {
            nums.push_back(root->data);
        }
        inorderTraversal(root->right, nums);
    }
}

bool leafSimilar(Node* root1, Node* root2) {
    vector<int> nums1, nums2;
    inorderTraversal(root1, nums1);
    inorderTraversal(root2, nums2);
    if(nums1 == nums2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<int> tree1 = {3,5,1,6,2,9,8,-1,-1,7,4};
    vector<int> tree2 = {3,5,1,6,7,4,2,-1,-1,-1,-1,-1,-1,9,8};

    Node *root1 = createBinaryTree(tree1, 0);
    Node *root2 = createBinaryTree(tree2, 0);

    bool b = leafSimilar(root1, root2);
    if(b) {
        std::cout << "trees have similar leaf";
    } else {
        std::cout << "trees don't have similar leaf";
    }
}
