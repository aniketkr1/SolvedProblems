// cpp program to find node with maximum value at each level of the binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

vector<int> maximumValue(Node* node) {
    //code here
    // we can use level order traversal
    vector<int> maxm;
    if(node == NULL) {
        return maxm;
    }

    Node *temp = node;
    queue<Node*> q;
    q.push(temp);
    int len = q.size();
    while(!q.empty()) {
        int val = INT_MIN;
        while(len != 0) {
            temp = q.front();
            q.pop();
            len--;
            
            if(temp->data > val) {
                val = temp->data;
            }
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
        }
        maxm.push_back(val);
        len = q.size();
    }
    
    return maxm;
}

int main()
{
    Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right = CreateNode(3);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);

    vector<int> ans = maximumValue(root);
    for(auto m : ans )  {
        std::cout << m << " ";
    }
    
}