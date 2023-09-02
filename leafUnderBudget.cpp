// cpp program to find the maximum left nodes that you can visit in your budget if the cost of visiting a leaf node
// is equal to the level of that leaf node. Currently we are at root node
/*Input:
                  10
                /    \
               8      2
             /      /   \
            3      3     6
                    \
                     4
and budget = 8
Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
In budget 8 one can visit Max 2 Leaf Nodes.*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
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

void inorderTraversal(node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int getCount(node *root, int k)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int count = 0;
    int height = 1;
    node *temp = root;
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> q;
    q.push(root);
    int size = q.size();
    while (!q.empty())
    {
        while (size--)
        {
            temp = q.front();
            q.pop();
            if (k > 0)
            {
                if (temp->left == NULL && temp->right == NULL)
                {
                    k = k - height;
                    if (k >= 0)
                    {
                        count++;
                    }
                }
            }
            else
            {
                return count;
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        size = q.size();
        height++;
    }
    return count;
}

int main()
{
    struct node *root = NULL;
    int arr[] = {10, 2, 11, 1, 9, 6, 4, 7, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }

    // root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);

    inorderTraversal(root);
    std::cout << "Count: " << getCount(root, 7);
}