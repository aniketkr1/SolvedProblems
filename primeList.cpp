// cpp program to  to replace all the values of the nodes with the nearest prime number
// If more than one prime number exists at an equal distance, choose the smallest one
// Input: 2 → 6 → 10
// Output: 2 → 5 → 11
//Explanation:The nearest prime of 2 is 2 itself.
// The nearest primes of 6 are 5 and 7,
// since 5 is smaller so, 5 will be chosen.
// The nearest prime of 10 is 11. 

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


bool isPrime(int num) {
    if(num == 1) {
        return false;
    }
    if(num == 2 || num == 3) {
        return true;
    }
    if(num %2 == 0 || num%3 == 0) {
        return false;
    }
    for(int i = 5; i<=sqrt(num); i+=6) {
        if(num%i == 0 || num%(i+2) == 0) {
            return false;
        }
    } 
    return true;
}

int nearestPrime(int num) {
    int prime1, prime2;
    if(num == 1) {
        return 2;
    }
    
    for(int i = num; i>1; i--) {
        if(isPrime(i)) {
            prime1 = i;
            break;
        }   
    }

    for(int i = num; i < num*num; i++) {
        if(isPrime(i)) {
            prime2 = i;
            break;
        }
    }

    if(abs(num-prime1) > abs(num-prime2)) {
        return prime2;
    } else if(abs(num-prime1) < abs(num-prime2)) {
        return prime1;
    } else {
        if(prime1 > prime2) {
            return prime2;
        } else {
            return prime1;
        }
    }
    
}

node *primeList(node * head) {
    node *temp = head;
    while(temp) {
        if(!isPrime(temp->data)) {
            int p = nearestPrime(temp->data);
            std::cout << "Nerest Prime: " << p << std::endl;
            temp->data = p;
        }
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
    std::cout << std::endl;
} 


int main() {
    int arr[] = {1,15,20};
    struct node *temp = createLinkedList(arr, 3);
    displayList(temp);
    struct node *res = primeList(temp);
    displayList(res);
}
