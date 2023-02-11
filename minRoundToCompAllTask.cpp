// cpp program to find the minimum number of rounds required to complete all tasks[leetcode-2244]
// given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task
// In each round, you can complete either 2 or 3 tasks of the same difficulty level.
// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.
// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
// Output: 4
//Explanation: To complete all the tasks, a possible plan is:
//- In the first round, you complete 3 tasks of difficulty level 2. 
//- In the second round, you complete 2 tasks of difficulty level 3. 
//- In the third round, you complete 3 tasks of difficulty level 4. 
//- In the fourth round, you complete 2 tasks of difficulty level 4.  
// It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

#include<bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int>& tasks) {
    map<int, int> m;
    for(int i = 0; i<tasks.size(); i++) {
        m[tasks[i]]++;
    }
    // goal is to complete all tasks
    int count = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        int num = it->second;
        if(num == 1) {
            return -1;
        }
        if(num%3 == 0) {
            count = count + num/3;
        } else if(num%3 == 2) {
            int k = num/3;
            count = count + k + 1;
        } else if(num%3 == 1) {
            count = count + num/3 + 1;
        }
        
    }
    return count;
}

int main() {
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    int ans = minimumRounds(tasks);
    std::cout << "Minimum Rounds required to complete all tasks: " << ans;
}