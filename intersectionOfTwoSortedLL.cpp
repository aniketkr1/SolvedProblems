/*Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Input:
LinkedList1 = 1->2->3->4->6
LinkedList2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two
linked list, 2, 4 and 6 are the elements
in the intersection.
*/

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

Node *findIntersection(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *head = NULL;
    Node *curr = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            if (head == NULL)
            {
                Node *newNode = new Node(ptr1->data);
                head = newNode;
                curr = newNode;
            }
            else
            {
                curr->next = new Node(ptr1->data);
                curr = curr->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            if (ptr1->data < ptr2->data)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
    return head;
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

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 5, 9};

    Node *head1 = createLinkedList(arr1, 5);
    Node *head2 = createLinkedList(arr2, 3);

    displayList(head1);
    displayList(head2);

    Node *ans = findIntersection(head1, head2);

    displayList(ans);
}
