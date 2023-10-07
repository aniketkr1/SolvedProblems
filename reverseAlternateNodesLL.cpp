#include<bits/stdc++.h>
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
    std::cout << "List : ";
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
Node *reverse(struct Node *head)
{
    struct Node *prev = NULL, *current = head;
    struct Node *nex = NULL;
    while (current != NULL)
    {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
    head = prev;
    return head;
}

void rearrange(struct Node *odd)
{
    // add code here
    Node *ptr1 = odd;
    Node *ptr2 = odd;
    Node *ans = ptr2;
    Node *newList = ans->next; 
    Node *prev = odd;
   
    int count = 0;
    while (ptr1 != NULL)
    {
        if (count % 2 != 0)
        {
            ptr2->next = ptr1;
            ptr2 = ptr1;

            // arranging
            prev->next = ptr1->next;
            prev = ptr1->next;
        }
        count++;
        prev = ptr1;
        ptr1 = ptr1->next;
        ptr2->next = NULL;
    }
    
    Node * ptr = odd;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    std::cout << "List after extracting  the alternative nodes starting from second node ";
    displayList(odd);
    std::cout << "Alternate nodes ";
    displayList(newList);
    Node * rev = reverse(newList);
    std::cout << "Reversed ";
    displayList(rev);
    ptr->next = rev;
    std::cout << "Final ";
    displayList(odd);
}

int main()
{
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createLinkedList(arr, n);
    std::cout << "Main ";
    displayList(root);
    rearrange(root);
}