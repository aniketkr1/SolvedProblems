#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *createLinkedList(int arr[], int n)
{
    Node *temp = NULL;
    Node *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        if (temp == NULL)
        {
            temp = newNode;
            prev = temp;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
    }
    return temp;
}

void displayList(Node *head)
{
    Node *ptr = head;
    std::cout << "\nThe list : ";
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
Node *sortedInsert(struct Node *head, int data)
{
    std::cout << "After inserting: " << data << " ";
    Node *ptr = head;
    Node *pos = head;
    while (ptr != NULL)
    {
        if (ptr->data >= data)
        {
            break;
        }
        pos = ptr;
        ptr = ptr->next;
    }
    Node *newNode = new Node(data);

    // if I have to insert in the beginning
    if (pos->data == head->data && head->data > data)
    {
        newNode->next = head;
        return newNode;
    }
    else
    {
        // if we have to insert in the and any other position
        Node *temp = pos->next;
        pos->next = newNode;
        newNode->next = temp;
        return head;
    }
    return head;
}
int main()
{
    int arr[] = {70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createLinkedList(arr, n);
    displayList(root);

    Node *ans = sortedInsert(root, 75);
    displayList(ans);
}