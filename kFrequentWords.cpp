// cpp program to find the k frequent words from an array of words(leetcode)
// Return the answer sorted by the frequency from highest to lowest 
// Sort the words with the same frequency by their lexicographical order.
// Input: {"the","day","is","sunny","the","the","the","sunny","is","is"} k = 4
// Output: {the, is, sunny, day}  freq of "the" = 4, feq of "is" = 3, freq of "sunny" = 2, freq of "day" = 1

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

vector<string> frequent(vector<string> &words, int k) {
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

    return ans;
    
}

int main() {

    vector<string> vect = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    vector<string> ans = frequent(vect, 4);
    for(auto s : ans) {
        std::cout << s << " ";
    }

}
