// cpp program to remove duplicate from a unsorted linked list

#include<bits/stdc++.h>
using namespace std;

void displayList();

struct node {
    int data;
    struct node *next;
};


struct node *createLinkedList(struct node *head, int arr[], int n) {
    for(int i = 0; i<n; i++) {
        struct node *newNode = new node();
        newNode->data = arr[i];
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            struct node *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

    }
    return head;
    
}

void displayList(struct node *head) 
{
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

node *removeDuplicates(node *head) {
    unordered_set<int> st;
    node *ptr = head;
    node *prev = NULL;
    while(ptr != NULL) {
        if(st.find(ptr->data) != st.end()) {
            prev->next = ptr->next;
        } else {
            st.insert(ptr->data);
            prev = ptr;
        }
        ptr = ptr->next;
    }
    return head;
}

int main() {
    int list1[] = {1, 3, 1, 1, 1, 4};

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int size = sizeof(list1)/sizeof(list1[0]);
    // function for creating linked list
    std::cout << "Original Linked list:- ";
    struct node *temp1 = createLinkedList(head1, list1, size);
    displayList(temp1); std::cout << std::endl;

    std::cout << "After removing duplicates Linked list:- ";
    node *res = removeDuplicates(temp1);
    displayList(res); std::cout << std::endl;

  

}