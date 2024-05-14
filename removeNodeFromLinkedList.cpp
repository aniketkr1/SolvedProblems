/*
2487. Remove Nodes From Linked List (Medium)

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
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

// Time complexity: O(n^2)
// Space complexity: O(1)
/*Node* removeNodes(Node* head) {

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        int value = current->data;
        Node* temp = current->next;
        int flag = 0;
        while (temp != NULL) {
            if (temp->data > value) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0) {
            if (prev == NULL) {
                head = current;
            }
            else {
                prev->next = current;
            }
            prev = current;
        }
        current = current->next;
    }

    return head;
}*/

// using monotonic stack approach
// Time complexity: O(n)
// Space complexity: O(n)
Node* removeNodes(Node* head) {

    Node* current = head;
    stack<Node*> st;
    while (current != NULL) {
        while (!st.empty() && st.top()->data < current->data) {
            st.pop();
        }
        st.push(current);
        current = current->next;
    }

    Node* ptr = NULL;
    while (!st.empty()) {
        current = st.top();
        st.pop();
        current->next = ptr;
        ptr = current;
    }
    return current;
}

int main() {
    int arr[] = { 9, 3, 8, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createLinkedList(arr, n);
    printLinkedList(head);
    Node* ptr = removeNodes(head);
    printLinkedList(ptr);
}