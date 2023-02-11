// cpp program to find the minimum numbers of arrows required to burst all blloons
// There are some spherical balloons taped onto a flat wall that represents the XY-plane
// The balloons are represented as a 2D integer array points where points[i] = [xstart, xend]
// denotes a balloon whose horizontal diameter stretches between xstart and xend 
// You do not know the exact y-coordinates of the balloons
// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis
// A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend
// There is no limit to the number of arrows that can be shot
// A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
//- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
//- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() == 1) {
        return 1;
    }
    int arrow = 1;
    sort(points.begin(), points.end());
    int end = points[0][1];
    for(int i = 0; i<points.size(); i++) {
        if(points[i][0] > end) {
            arrow++;
            end = points[i][1];
        } else {
            end = min(end, points[i][1]);
        }
    }
    return arrow;
}

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    std::cout << "Minimum number of arrows required to burst all ballons: " << findMinArrowShots(points);
    
}