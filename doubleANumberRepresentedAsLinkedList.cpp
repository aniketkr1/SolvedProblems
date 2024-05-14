/*
2816. Double a Number Represented as a Linked List (Medium)

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* createLinkedList(int arr[], int n) {
    Node* prev = NULL;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        Node* ptr = new Node(arr[i]);
        if (head == NULL) {
            head = ptr;
            prev = head;
        }
        else {
            prev->next = ptr;
            prev = ptr;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    std::cout << "The List: ";
    while (head != NULL) {
        std::cout << head->data << "  ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* reverse(Node* head) {
    Node* prev = NULL, * current = head;
    Node* nex = NULL;
    while (current != NULL) {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
    head = prev;
    return head;
}

Node* doubleIt(Node* head) {
    if (head->data == 0) {
        Node* ptr = new Node(0);
        return ptr;
    }

    Node* rev = reverse(head);
    Node* ptr = rev;
    Node* prev = NULL;

    int carry = 0;

    while (ptr != NULL) {
        int value = ptr->data;
        int digit = value * 2 + carry;
        carry = digit / 10;
        digit %= 10;
        ptr->data = digit;
        prev = ptr;
        ptr = ptr->next;
    }
    if (carry > 0) {
        prev->next = new Node(carry);
    }
    Node* ans = reverse(rev);

    return ans;
}

int main() {
    int arr[] = {9,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* num = createLinkedList(arr, n);
    std::cout << "Before doubling ";
    printLinkedList(num);
    Node* ans = doubleIt(num);
    std::cout << "After doubling ";
    printLinkedList(ans);
}