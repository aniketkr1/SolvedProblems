// cpp program to find height of a tree
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = new node();
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

int height(node *root)
{
    int size;
    int count = 0;
    struct node *temp = root;
    std::queue<node *> q;
    q.push(root);
    size = q.size();
    while(!q.empty())
    {
        
        while(size != 0)
        {
            temp = q.front();
            q.pop();
            size--;
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
            
        }
        size = q.size();
        count = count + 1;
    }
    return count;
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

    int h = height(root);
    std::cout << "Height = " << h;
    
}