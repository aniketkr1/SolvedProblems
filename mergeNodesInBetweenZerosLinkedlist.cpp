/*
2181. Merge Nodes in Between Zeros (Medium)

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
Return the head of the modified linked list.

Example 1:
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int data) {
        this->val = data;
        this->next = NULL;
    }
};

ListNode* createLinkedList(int arr[], int n) {
    ListNode* temp = NULL;
    ListNode* prev = NULL;
    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (temp == NULL) {
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

void displayList(ListNode* head)
{
    ListNode* ptr = head;
    std::cout << "List : ";
    while (ptr != NULL)
    {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    ListNode* ptr = head->next;
    int sum = 0;
    while (ptr != NULL) {
        if (ptr->val == 0) {
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
            sum = 0;
        }

        sum += ptr->val;
        ptr = ptr->next;
    }
    return dummy->next;
}

int main() {
    int arr[] = { 0,3,1,0,4,5,2,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* root = createLinkedList(arr, n);
    displayList(root);
    ListNode *newHead = mergeNodes(root);
    displayList(newHead);
}