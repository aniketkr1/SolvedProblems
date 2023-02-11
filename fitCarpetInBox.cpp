// cpp program to find the minimum number of moves required to fit the carpet in the box
// carpet: l*b = A*B;
// box: l*b = C*D;
// In one move, you can either decrease the length or 
// the breadth of the carpet by half (floor value of its half).
// Note: One can even turn the carpet by 90 degrees any number of times, wont be counted as a move.
// Input:  A = 8, B = 13, C = 6, D = 10
// Output: 1 {if we floor the carpet breadth it becomes 6 so now the lenght and breadth of carpet is 8*6
// and fit into the box of lenght 6*10}

#include<bits/stdc++.h>
using namespace std;

int carpetBox(int A, int B, int C, int D){
    if(A > B) {
        swap(A, B);
    } 
    if(C > D) {
        swap(C, D);
    }
    int count = 0;
    while( A > C|| B > D) {
        if(A > B) {
            swap(A, B);
        }
        if(B > D) {
            B = B/2;
            count++;
        }
        else if( A > C) {
            A/=2;
            count++;
        }
    }
    return count;
}

int main() {
    int A = 8;
    int B = 12;
    int C = 6;
    int D = 10;

    std::cout << "Minimum number of moves: " << carpetBox(A, B, C, D);
}