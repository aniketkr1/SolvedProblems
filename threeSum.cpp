// cpp program to find all possible 3 elements whose sum is equal to 0
// means (nums[i] + nums[j] + nums[k] == 0)  where i != j, i != k, and j != k
// method 1: two pointer approach (time complexity: O(nlogn) + O(n) == O(nlong), space complexity: O(1))
// method 2: using set (time complexity: O(n*n), space complexity: O(n))
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twoPointerApproach(vector<int>& nums) {
    // two pointer approach
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i = 0; i < nums.size()-2; i = i + 1) {
        
        // condition for ignoring the duplicate elements
        if(i>0 && (nums[i] == nums[i-1])) {
            continue;
        }
        int leftIndex = i + 1;
        int rightIndex = nums.size() - 1;

        while(leftIndex < rightIndex) {
            
            if(nums[i] + nums[leftIndex] + nums[rightIndex] > 0) {
                rightIndex--;
            } else if(nums[i] + nums[leftIndex] + nums[rightIndex] < 0) {
                leftIndex++;
            } else if(nums[i] + nums[leftIndex] + nums[rightIndex] == 0) {
                // the 3 elements found wholse sum == 0
                result.push_back({nums[i], nums[leftIndex], nums[rightIndex]});

                // if there is duplicate elements we ignore them
                while(((leftIndex < rightIndex) && nums[leftIndex] == nums[leftIndex+1])) {
                    leftIndex++;
                }
                leftIndex++;
            }
        }
    }
    return result;
}
    
vector<vector<int>> usingSet(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    set<vector<int>> temp;
    vector<vector<int>> result;

    for(int i = 0; i < nums.size()-2; i = i + 1) {
        sort(nums.begin(), nums.end());
        int leftIndex = i+1;
        int rightIndex = nums.size()-1;
        while(leftIndex < rightIndex) {
            if(nums[i] + nums[leftIndex] + nums[rightIndex] == 0) {
                temp.insert({nums[i], nums[leftIndex], nums[rightIndex]});
                leftIndex++;
                rightIndex--;
            } else
            if(nums[i] + nums[leftIndex] + nums[rightIndex] > 0) {
                rightIndex--;
            } else {
                leftIndex++;
            }
        }
    }

    for(auto s : temp){
            result.push_back(s);
    }
    return result;

}


int main() {
    vector<vector<int>> ans;
    vector<int> nums {-5,0,0,5,0,-2,5,9,2,0,1,-1};
    
    ans = twoPointerApproach(nums);
    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; j<ans[i].size(); j++) {
            std::cout << ans[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    
}