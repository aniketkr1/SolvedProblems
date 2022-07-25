//Lapindrome is defined as a string which when split in the middle,
//gives two halves having the same characters and same frequency of each character. 
//If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. 
//For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. 
//Also, abccab, rotor and xyzxy are a few examples of lapindromes.
//Note that abbaab is NOT a lapindrome.

#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
    std::string s;
    std::vector<char> v1;
    std::vector<char> v2;
    int mid;
    std::cout << "Enter a string: ";
    std::cin >> s;
    if(s.length() % 2 == 0)
    {
        mid = s.length()/2;
        for(int i = 0; i<mid; i++)
        {
            v1.push_back(s[i]);
        }
        for(int i = mid; i<s.length(); i++)
        {
            v2.push_back(s[i]);
        }
    }
    else{
        mid = s.length()/2;
        for(int i = 0; i<mid; i++)
        {
            v1.push_back(s[i]);
        }
        for(int i = mid+1; i<s.length(); i++)
        {
            v2.push_back(s[i]);
        }
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    if(v1 == v2)
    {
        std::cout << "Given string " << s << " is lapindrome";
    }
    else{
        std::cout << "Given string " << s << " is not lapindrome";
    }

    
}