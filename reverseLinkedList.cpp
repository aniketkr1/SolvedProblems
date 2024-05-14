// cpp program to reverse a linkedlist in cpp
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

node* reverse(struct node *head) {
    struct node *prev = NULL, *current = head;
    struct node *nex = NULL;
    while(current != NULL) {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
    head = prev;
    return head;
}

void displayList(node *head) {
    node *ptr = head;
    std::cout << "\nThe list : ";
    while(ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
} 

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    node *ptr = createLinkedList(arr, size);
    displayList(ptr);
    node *rev = reverse(ptr);
    std::cout << "After Reverse ";
    displayList(rev);
    
}