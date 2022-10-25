// cpp program to construct a binary search tree(bst) from an inorder traversal(increasing array)
#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// we are going the construct the binary tree from the given inorder traversal

node *constructTree(int arr[], int start, int end) {
    if(start > end) {
        return NULL;
    }
    // getting the mid element as all the element
    // before mid are smaller then the mid element
    // and after the mid element all the bigger
    int mid = (start+end)/2;

    // creating a new node withe the value
    node *temp = new node(arr[mid]);

    // attaching the new node to the left as it is smaller then the mid element
    temp->left = constructTree(arr, start, mid-1);
    // attaching the new node to the right as it is larger then the mid element
    temp->right = constructTree(arr, mid+1, end);

    return temp;

}

void inorderTraversal(node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        std::cout << root->data << "  ";
        inorderTraversal(root->right);
    }
}


int main() {
    
    int n;
    printf("Enter the number of elements in the binary search tree: ");
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the sorted array(inorder traversal) of the tree:\n";
    for(int i = 0; i<n; i++) {
        std::cin >> arr[i];
    }

    

    node *root = constructTree(arr, 0, n-1);
    std::cout << "Inorder Traversal of the tree after construction:  ";
    inorderTraversal(root);



}

