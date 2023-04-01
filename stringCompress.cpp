/*Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
*/

//Input: chars = ["a","a","b","b","c","c","c"]
//Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
//Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3"

//Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
//Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
//Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

// we have to edit the chars

#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    if(chars.size() == 1) {
        return 1;
    }
    int len = chars.size();
    int count = 1;
    int i = 0;
    for( i = 0; i<len-1; i++) {
        if(chars[i] != chars[i+1]) {
            chars.push_back(chars[i]);
            if(count > 1) {
                string temp = to_string(count);
                for(int j = 0; j<temp.size(); j++) {
                    chars.push_back(temp[j]);
                }
                count = 1;
            } 
        }
        else {
            count++;
        }
    }
    chars.push_back(chars[i]);
    if(count > 1) {
        string temp = to_string(count);
        for(int j = 0; j<temp.size(); j++) {
            chars.push_back(temp[j]);
        }
    } 
    chars.erase(chars.begin(), chars.begin()+len);
    return chars.size();
}

int main() {
    vector<char> chars {'a','a','b','b','c','c','c'};
    std::cout << compress(chars);
}