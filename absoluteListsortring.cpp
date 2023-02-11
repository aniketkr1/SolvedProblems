// cpp program to sort the linked list in increasing order
// from absolute sotred linked list
// Input: 1 -> -2 -> -3 -> 4 -> -5
// Output: -5 -> -3 -> -2 -> 1 -> 4

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;

    node(int value) {
        data = value;
        next = NULL;
    }
};

node  *createLinkedList(int arr[], int n) {
    node *temp = NULL;
    node *prev = NULL;
    for(int i = 0; i<n; i++) {
        node *newNode = new node(arr[i]);
        if(temp == NULL) {
            temp  = newNode;
            prev = temp;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
    }
    return temp;
}

node *sortring(node *head) {
    
    node *temp = head;
    node *parent = NULL;

    while(temp != NULL) {
        if(temp->data <= 0 && temp != head) {
            parent->next = temp->next;
            node *n = new node(temp->data);
            n->next = head;
            head = n;
            temp = parent;
        }
        parent = temp;
        temp = temp->next;
    }
    return head;
}


void displayList(node *head) {
    node *ptr = head;
    std::cout << "\nThe list : ";
    while(ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main() {
    int arr[] = {1, -2, -3, 4, -5};
    node *m1 = createLinkedList(arr, 5);
    displayList(m1);
    node *m2 = sortring(m1);
    displayList(m2);
}   
