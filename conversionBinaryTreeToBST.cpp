// cpp program to convert a binary tree into binary search tree(BST)
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
void preorderTraversal(Node *root, vector<int> &vect)
{
    if (root == NULL)
    {
        return;
    }
    vect.push_back(root->data);
    preorderTraversal(root->left, vect);
    preorderTraversal(root->right, vect);
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

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *binaryTreeToBST(Node *root)
{
    if (root == NULL)
    {
        return nullptr;
    }
    vector<int> vect;
    preorderTraversal(root, vect);
    Node *tree = NULL;
    for (auto v : vect)
    {
        tree = insert(tree, v);
    }
    return tree;
}

int main()
{
    Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->left->left = CreateNode(4);
    root->right = CreateNode(3);

    Node *ans = binaryTreeToBST(root);
    std::cout << "Inorder Traversal after conversion: ";
    inorderTraversal(ans);
}