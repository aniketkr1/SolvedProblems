#include<iostream>
#include<stdlib.h>
#include<queue>
struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data)
{
    struct node *ptr = root;
    struct node *temp = NULL;
    if(root == NULL)
    {
        return createNode(data);
    }
    while(ptr != NULL)
    {
        temp = ptr;
        if(data < ptr->data)
        {
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    if(data < temp->data)
    {
        temp->left = createNode(data);
    }
    else{
        temp->right = createNode(data);
    }

    return root;
}
// function to mirror a tree
struct node *mirror(struct node *root)
{
    struct node *ptr = root;
    std::queue<node *> q;
    q.push(ptr);
    while(!q.empty())
    {
        ptr = q.front();
        q.pop();
        std::swap(ptr->left, ptr->right);
        if(ptr->left != NULL)
        {
            q.push(ptr->left);
        }
        if(ptr->right != NULL)
        {
            q.push(ptr->right);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int size;
    std::cout << "How many? ";
    std::cin >> size;
    for(int i = 0; i<size; i++)
    {
        int item;
        std::cout << "Enter data: ";
        std::cin >> item;
        root = insert(root, item); 
    }
    std::cout << "Inorder Traversal:- ";
    inorder(root);
    std::cout << "\nInorder Traversal after mirroring:- ";
    root = mirror(root);
    inorder(root);
}