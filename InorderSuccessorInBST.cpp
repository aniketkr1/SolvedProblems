/*cpp program to find the Inorder Successor of the given Node in the BST, Given a BST, and a reference to a Node x in the BST.
Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.
*/

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

struct Node *createNode(int data)
{
    struct Node *newNode = new Node(data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    struct Node *ptr = root;
    struct Node *temp = NULL;
    if (root == NULL)
    {
        return createNode(data);
    }
    while (ptr != NULL)
    {
        temp = ptr;
        if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (data < temp->data)
    {
        temp->left = createNode(data);
    }
    else
    {
        temp->right = createNode(data);
    }
    return root;
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
void inOrderTraversal(Node *root, vector<Node *> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left, inorder);
    inorder.push_back(root);
    inOrderTraversal(root->right, inorder);
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    vector<Node *> inorder;
    inOrderTraversal(root, inorder);
    for (int i = 0; i < inorder.size() - 1; i++)
    {
        if (inorder[i]->data == x->data)
        {
            return inorder[i + 1];
        }
    }
    return NULL;
}

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    Node *x = root->left;
    Node *succesor = inOrderSuccessor(root, x);
    std::cout << "\nInorder Successor: " << succesor->data;
    
}
