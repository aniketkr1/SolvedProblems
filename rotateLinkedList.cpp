// cpp program to rotate the linkedList to the right by k places
// Input: {1, 2, 3, 4, 5}, k = 3
// Output: {3, 4, 5, 1, 2}
// Explaination: The linkedList will be rotated 3 times 
// after 1st rotation: {5, 1, 2, 3, 4}
// after 2nd rotation: {4, 5, 1, 2, 3}
// after 3rd rotation: {3, 4, 5, 1, 2}
#include<bits/stdc++.h>
using namespace  std;

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


void displayList(node *head) {
    node *ptr = head;
    std::cout << "\nThe list : ";
    while(ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
} 
node *rotateList(node *head, int k) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        return head;
    }
    
    node *mainHead = head;
    node *temp = head;
    node* prev = NULL;
    int len = 0;
    node *ptr = head;
    while(ptr != NULL) {
        ptr = ptr->next;
        len++;
    }
    k = k % len;
    for(int i = 0; i<k; i++) {
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        temp->next = mainHead;
        mainHead = temp;
        prev->next = NULL;
    }
    return mainHead;
}

int main() {
    int arr[] = {0, 1, 2, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    node *ptr = createLinkedList(arr, sz);
    displayList(ptr);
    ptr = rotateList(ptr, 2);
    displayList(ptr);
}
