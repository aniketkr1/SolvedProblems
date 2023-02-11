// cpp program to merge all overlaping intervals and return
// an array of the non-overlapping intervals that cover all the intervals in the input
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explaination: Interval(1,3) is overlaping with interval (2,6) so the merged Interval is(1,6)
// Intervals (8,10) adn (15,18) don't overlaping with any other intervasl so the
// final result: (1,6), (8,10) and (15,18)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int s = intervals.size();
    if(s == 1) {
        return intervals;
    }
    int start = intervals[0][0];
    int end = intervals[0][1];
    for(int i = 1; i<intervals.size(); i++) {
        if(intervals[i][0] <= end) {
            end = max(intervals[i][1], end);
        } else if(intervals[i][0] > end) {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    
    ans.push_back({start, end});
    return ans;
}

int main() {
    vector<vector<int>> intervals ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);
    for(int i = 0; i<res.size(); i++) {
        std::cout << "(" << res[i][0] << "," << res[i][1] << ")" << "  ";
    }

}