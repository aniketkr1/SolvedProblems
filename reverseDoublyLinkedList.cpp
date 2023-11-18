// cpp program to reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *createNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}

Node *createList(int arr[], int n)
{
    Node *head = NULL;
    Node *left = NULL;

    for (int i = 0; i < n; i++)
    {
        Node *node = createNode(arr[i]);
        if (head == NULL)
        {
            head = node;
            left = node;
        }
        else
        {
            node->prev = left;
            left->next = node;
            left = node;
        }
    }
    return head;
}

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;

        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

void displayList(Node *head)
{
    Node *ptr = head;
    std::cout << "The list: ";
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = createList(arr, n);
    displayList(head);
    Node *reversedList = reverseDLL(head);
    std::cout << "After reversing ";
    displayList(reversedList);
}