#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &temp, int k)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (abs(temp[i] - temp[j]) > k)
            {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        if (temp.size() == 3)
        {
            if (check(temp, k))
            {
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                ans.clear();
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 3;

    vector<vector<int>> ans = divideArray(nums, k);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
}