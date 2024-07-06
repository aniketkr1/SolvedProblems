/*
Remove all occurences of duplicates in a linked list (Medium)
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list.

Examples:
Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation:
The duplicate numbers are 28, 49 and 53 which are removed from the list.

Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation:
All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

Node* removeAllDuplicates(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* current = head;
    Node* prev = dummy;;

    while (current != nullptr) {
        bool duplicate = false;

        while (current->next != NULL && current->data == current->next->data) {
            duplicate = true;
            current = current->next;
        }
        if (duplicate) {
            prev->next = current->next;
        }
        else {
            prev = prev->next;;
        }
        current = current->next;
    }
    Node* newHead = dummy->next;
    return newHead;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(23);
    head->next = new Node(28);
    head->next->next = new Node(28);
    head->next->next->next = new Node(35);
    head->next->next->next->next = new Node(49);
    head->next->next->next->next->next = new Node(49);
    head->next->next->next->next->next->next = new Node(53);
    head->next->next->next->next->next->next->next = new Node(53);

    printList(head);
    std::cout << "After remvoing all occurances of duplicates: ";
    removeAllDuplicates(head);
    printList(head);
}