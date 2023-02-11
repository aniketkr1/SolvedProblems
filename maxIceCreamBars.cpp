// cpp program to find the maximum Ice Creams bars a boy can buy with n coins 
// costs[i] represent the cost of ith Ice Cream bar
#include<bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    int maxm = 0;
    sort(costs.begin(), costs.end());
    for(int i = 0; i < costs.size(); i = i + 1) {
        if(costs[i] <= coins) {
            maxm++;
            coins -= costs[i];
        }
    }
    return maxm;
}

int main() {
    vector<int> costs{1,3,2,4,1};
    int coins = 7;
    int res = maxIceCream(costs, coins);
    std::cout << "Maximum number of Ice Cream bars the boy can buy: " << res;
}