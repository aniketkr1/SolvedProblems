// cpp porgram to remove duplicate from a sorted vector
#include<iostream>
#include<vector>
#include<algorithm>

void returnDuplicate(std::vector<int>& nums)
{
    int k = 0;
    int size = nums.size();
    for( int i = 1; i<size; i++ )
    {
       if(nums[i] != nums[i+1]){
           k++;
           nums[k] = nums[i];
       }
    }
    std::cout << "Vector after removing duplicates:- ";
    for(int i = 0; i<k+1; i++ )
    {
        std::cout << "  " << nums[i];
    }
}

int main()
{
    // vector should be shorted
    std::vector<int> nums = {1, 2, 6, 3, 3, 9, 0, 6, 6};
    // sort(startAddress, endAddress);
    sort(nums.begin(), nums.end());
    returnDuplicate(nums);
    
}