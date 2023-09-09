// cpp program to find kth largest element in binary search tree(BST)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *CreateNode(int data)
{
    Node *NewNode = new Node(data);
    if (!NewNode)
    {
        std::cout << "Memory error" << std::endl;
        return NULL;
    }
    NewNode->left = NewNode->right = NULL;

    return NewNode;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void revInorderTraversal(Node *root, int &ans, int &count, int &k)
{
    // revers of inorder traversal
    if (root == NULL)
    {
        return;
    }
    revInorderTraversal(root->right, ans, count, k);
    if (count == k - 1)
    {
        ans = root->data;
    }
    count++;
    revInorderTraversal(root->left, ans, count, k);
}

int kthLargest(Node *root, int K)
{
    if (root == NULL)
    {
        return -1;
    }
    int ans = -1;
    int count = 0;
    revInorderTraversal(root, ans, count, K);
    return ans;
}

int main() {
    Node *root = CreateNode(6);
    root->left = CreateNode(4);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(5);
    root->right = CreateNode(8);
    root->right->left = CreateNode(7);
    root->right->right = CreateNode(9);

    inorderTraversal(root);
    int k = 5;
    std::cout << "\n" << k << "th largest element: " << kthLargest(root, k) << std::endl;
}