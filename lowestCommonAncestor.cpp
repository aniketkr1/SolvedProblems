// cpp program to find the lowest common ancestor in a BST(binary search tree)
#include<bits/stdc++.h>
using namespace std;

// structure of a node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

node *createNode(int val) {
    node *newNode = new node();
    newNode->data = val;
    newNode->left = newNode->right  = NULL;
    return newNode;
}

node *insert(node *root, int val) {
    if(root == NULL) {
        return createNode(val);
    }
    if(root->data > val) {
        root->left =  insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorderTraversal(node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        std::cout << root->data << "  ";
        inorderTraversal(root->right);
    }
}

node  *lowestCommonAncestor(node *root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > n1 && root->data > n2) {
        return lowestCommonAncestor(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2) {
        return lowestCommonAncestor(root->right, n1, n2);
    }
    return root;
}



int main() {
    int n;
    node *root = NULL;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    for(int i = 0; i<n; i++) {
        int data;
        std::cout << "Enter data: ";
        std::cin >> data;
        root = insert(root, data);
    }
    int n1, n2;
    std::cout << "Enter two element to find the lowest common ancestor(elements must not out of the bst elements): ";
    std::cin >> n1 >> n2;
    node *res = lowestCommonAncestor(root, n1, n2);
    std::cout << "The lowest common ancestor : " << res->data << std::endl;
    std::cout << "Inorder Traversal = " << std::endl;
    inorderTraversal(root);
}