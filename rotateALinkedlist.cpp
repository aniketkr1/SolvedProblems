/*
Rotate a Linked List (Medium)

Given the head of a singly linked list, the task is to rotate the linked list clockwise by k nodes, i.e., left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:
Input: linkedlist: 2->4->7->8->9 , k = 3
Output: 8->9->2->4->7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Example 2:
Input: linkedlist: 1->2->3->4->5->6->7->8 , k = 4
Output: 5->6->7->8->1->2->3->4

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* rotate(Node* head, int k) {
    if (k == 0) {
        return head;
    }
    Node* tail = NULL;
    Node* temp = head;
    while (temp != NULL) {
        tail = temp;
        temp = temp->next;
    }
    Node* ptr = head;
    while (k--) {
        tail->next = ptr;
        tail = tail->next;
        ptr = ptr->next;
        head = ptr;
    }
    tail->next = NULL;

    return head;
}

void displayList(Node *root) {
    while(root != NULL) {
        std::cout << root->data << " ";
        root = root->next;
    }
}

int main() {
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = new Node(7);
    root->next->next->next->next->next->next->next = new Node(8);
    int k = 4;
    root = rotate(root, k);
    displayList(root);
}