// cpp program to delete nodes having greater value on right
// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes.
// So, after deleting them, the linked list would like be 15, 11, 6, 3.

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

Node *compute(Node *head)
{
    Node *ans = new Node(0);
    Node *final = ans;
    Node *ptr = head;
    Node *temp = head;
    while (ptr != NULL)
    {
        temp = ptr->next;
        int value = ptr->data;
        int flag = 0;
        // std::cout << "Value: " << value << std::endl;
        while (temp != NULL)
        {
            if (temp->data > value)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0)
        {
            // std::cout << "Data: " << value << std::endl;
            ans->next = ptr;
            ans = ptr;
        }
        ptr = ptr->next;
    }
    return final->next;
}

int main()
{
    // int arr[] = {10, 23, 22, 100, 42, 101, 323, 5, 22};
    // output: 323 22
    // int arr[] = {12, 15, 10, 11, 5, 6, 2, 3};
    // output: 15 11 6 3
    int arr[] = {10, 20, 30, 40, 50, 60};
    // output: 60
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *ptr = createLinkedList(arr, n);
    displayList(ptr);
    Node *ans = compute(ptr);
    std::cout << "After deleting: ";
    displayList(ans);
}
