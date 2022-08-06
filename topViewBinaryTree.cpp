// cpp program to print top view of the binary tree
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node*  createNode(int data) {
    struct node *newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

}

struct node * insert(struct node *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data > root->data) {
        root->right = insert(root->right, data);
    } else if(data < root->data) {
        root->left = insert(root->left, data);
    }

    return root;
}

void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        std::cout << root->data << "  ";
        inorderTraversal(root->right);
    }
}

/* void levelOrderTraversal(struct node *root) {
    queue<node*> q;
    node *temp = NULL;
    q.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        std::cout << temp->data << "  ";
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
} */

vector<int> topView(struct node *root) {
        
        queue<pair<node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            node *temp = it.first;
            int line = it.second;
            if(mp.find(line) == mp.end()) {
                mp[line] = temp->data;
            }
            if(temp->left != NULL) {
               
                q.push({temp->left, line-1});
            }
            if(temp->right != NULL) {
                q.push({temp->right, line+1});
            }
        }

   for(auto it :mp) {
    std::cout<< it.second << "  ";
   }
}





int main() {
    
    int n;
    struct node *root = NULL;
    int arr[] = {30, 15, 35, 10, 20, 34, 40};
    n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<n; i++) {
        int data = arr[i];
        root = insert(root, data);
    }
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    //std::cout << "\nLevel Order Traversal: ";
    //levelOrderTraversal(root);
    std::cout << std::endl;
    std::cout << "Top view of the binary tree: ";
    topView(root);
           
}