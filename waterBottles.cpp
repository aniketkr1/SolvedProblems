/*
1518. Water Bottles (Easy)

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
The operation of drinking a full water bottle turns it into an empty bottle.
Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

Example 1:
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

Example 2:
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.
*/

#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int drunkBottles = 0;
    drunkBottles += numBottles;
    int total = numBottles;
    while (total >= numExchange) {
        int q = total / numExchange;
        int rem = total % numExchange;
        total = q + rem;
        drunkBottles += q;
    }
    return drunkBottles;
}

int main() {
    int numBottles = 9, numExchange = 3;
    std::cout << "The maximum number of water bottles you can drink: " << numWaterBottles(numBottles, numExchange);
}