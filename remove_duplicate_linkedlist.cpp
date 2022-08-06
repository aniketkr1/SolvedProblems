// cpp program to remvoe duplicate element from linked list
#include<iostream>
#include<unordered_map>
struct node {
    int data;
    struct node *link;
};

struct node *head;

void insertEnd()
{
    node *newNode = new node();
    newNode->link = NULL;
    std::cout << "Enter data: ";
    std::cin >> newNode->data;
    if(head == NULL)
    {
        head = newNode;
    }
    else {
        node *ptr = head;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newNode;
    }
}

void displayList()
{
    node *ptr = head;
    while(ptr != NULL)
    {
        std::cout << ptr->data << "  ";
        ptr = ptr->link;
    }
    
}

void removeDuplicate()
{
    std::unordered_map<int, bool> mp;
    node *ptr = head, *prev;
    while(ptr != NULL)
    {
        if(mp[ptr->data] == true)
        {
            prev->link = ptr->link;
        } else {
            mp[ptr->data] = true;
            prev = ptr;
        }
        ptr = ptr->link;
    }
}

int main()
{
    int n;
    std::cout << "How many elements you want to insert: ";
    std::cin >> n;
    for(int i = 0; i<n; i++)
    {
        insertEnd();
    }
    std::cout << "Original elements: ";
    displayList();
    removeDuplicate();
    std::cout << "\nAfter remvoing duplicates: ";
    displayList();
}