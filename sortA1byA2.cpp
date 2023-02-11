#include<bits/stdc++.h>
using namespace std;

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
{
    //Your code here
    vector<int> ans;

    map<int, int> mp;
    for(int i = 0; i<N; i++) {
        mp[A1[i]]++;
    }
    
    for(int i = 0; i<M; i++) {
        int t = mp[A2[i]];
        while(t--) {
            ans.push_back(A2[i]);
        }
        mp.erase(A2[i]);
    }
    
    for(auto it : mp) {
        int t = it.second;
        while(t--) {
            ans.push_back(it.first);
        }
    }
    
    return ans;
} 

int main() {
    vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> A2 = {2, 1, 8, 3};

    int n = A1.size();
    int m = A2.size();

    vector<int> res = sortA1ByA2(A1, n, A2, m);
    for(auto v : res) {
        std::cout << v << " ";
    }

}