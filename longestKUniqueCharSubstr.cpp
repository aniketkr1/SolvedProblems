// cpp program to print the size of the longest possible substring that has exactly K unique characters
// If there is no possible substring then print -1.
/*Input:
S = "aabacbebebe", K = 3
Output:
7
Explanation:
"cbebebe" is the longest substring with 3 distinct characters.*/

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    // your code here
    int ans = -1;
    unordered_map<char, int> mp;
    int j = 0;
    int i = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        while (mp.size() > k)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

int main()
{
    string str = "aabacbebebe";
    int k = 3;
    std::cout << "size: " << longestKSubstr(str, k);
}