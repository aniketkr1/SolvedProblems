// cpp program to find the k frequent words from an array of words(leetcode)
#include<bits/stdc++.h>

using namespace std;

struct compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

void frequent(vector<string> &words, int k) {
    map<string, int> mp;
    for(auto word : words) {
        mp[word]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> q;
    for(auto p : mp) {
        q.push({p.second, p.first});
    }

    vector<string> ans;

    while(k--) {
        ans.push_back(q.top().second);
        q.pop();
    }

    for(auto p : ans) {
        std::cout << p << " " ;
    }
    
}

int main() {

    vector<string> vect = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    frequent(vect, 4);

}