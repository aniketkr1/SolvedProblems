// implementation of stack using two queue
#include<iostream>
#include<queue>

std::queue<int> q1;
std::queue<int> q2;

void pushQueue(int x) {

    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();    
    }

    q1.push(x);

    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }

} 


int popQueue() {
    std::cout << q1.front() << std::endl;
    q1.pop();
}

int main() {
    pushQueue(2);
    pushQueue(3);
    pushQueue(4);
    popQueue();
    pushQueue(5);
    popQueue();
    popQueue();

}