// cpp program to print the Pascal's Triangle with given number of rows
// return type is 2D vector
// Input: 3
// Output: {{1}, {1,1}, {1,2,1}}
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int row) {
    vector<vector<int>> ans;
    if(row == 1) {
        ans.push_back({1});
        return ans;
    }
    else if(row == 2) {
        ans.push_back({1});
        ans.push_back({1,1});
        return ans;
    } else {
        ans.push_back({1});
        ans.push_back({1,1});
        
    }
    
    for(int i = 3; i<=row; i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j = 0; j<i-2; j++) {
            int sum = ans[i-2][j] + ans[i-2][j+1];
            temp.push_back(sum);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    
    return ans;
}

int main() {
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    vector<vector<int>> res = pascalTriangle(rows);
    std::cout << "Pascal's Triangle" << std::endl;
    for(int i = 0; i<res.size(); i++) {
        for(int j = 0; j<res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}