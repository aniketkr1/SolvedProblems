// cpp program to connect all the nodes that are at the same level
// use nextRight pointer for this purpose
// Input:
/*      10
    /   \
   20   30
  /  \
 40  60   */
// Output:
// 10 20 30 40 60 (this is level ordre traversal)
// 40 20 60 10 30 (this is inorder traversal)
// Explanation:The connected tree is
/*     10 ---> NULL
       /   \
     20---> 30 ---> NULL
   /   \
 40---> 60 ---> NULL   */


#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node *left;
    node *right;
    node *nextRight;
};

node *CreateNode(int data)
{
    node *NewNode = new node();
    if( !NewNode )
    {
        std::cout << "Memory error" << std::endl;
        return NULL;
    }

    NewNode->data = data;
    NewNode->left = NewNode->right = NULL;
    
    return NewNode;
}

node *InsertNode(node *root, int data)
{
    if( root == NULL )
    {
        root = CreateNode(data);
        return root;
    }
    else
    {
        std:: queue<node*> q;
        q.push(root);

        while( !q.empty() )
        {
            node *temp = q.front();
            q.pop();

            if( temp->left != NULL )
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = CreateNode(data);
                return root;
            }
            if( temp->right != NULL )
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = CreateNode(data);
                return root;
            }
        }
    }
}

void Inorder(node *temp)
{
    if( temp )
    {
        Inorder(temp->left);
        std::cout << temp->data << "  " ;
        Inorder(temp->right);
    }
}

void levelorder(node *root)
{
    struct node *temp = root;
    std::queue<node *> q;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << temp->data << "  ";
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
void connect(node *root) {
    int size;
    std::queue<node*> q;
    struct node *temp = root;
    q.push(temp);
    size = q.size();
    while(!q.empty()) {
        struct node *ptr = NULL;
        while(size != 0) {
            
            temp = q.front();
            q.pop();
            if(ptr == NULL) {
                temp->nextRight = NULL;
                ptr = temp;
            } else {
                ptr->nextRight = temp;
                ptr = temp;
            }
            size--;
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
        }
        ptr->nextRight = NULL;
        size = q.size();
    }
}    

int main() {
    node *root = CreateNode(20);
    root = InsertNode(root, 80);
    root = InsertNode(root,45);
    root = InsertNode(root,56);
    root = InsertNode(root,76);
    root = InsertNode(root,43);
    root = InsertNode(root,23);

    /*       20
            /  \
            80   45
          / \    / \   
         56  76 43  23 */

    std::cout << "\nLevelorder traversal: " ;
    levelorder(root);
    std::cout << "\nInorder traversal: " ;
    Inorder(root); 
}