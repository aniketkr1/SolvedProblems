// cpp program to print roman of an integer
#include<iostream>
#include<vector>
int main()
{
    int num;
    std::string result;
    std::vector<int> n = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    std::vector<std::string> s = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    std::cout << "Enter an Integer: ";
    std::cin >> num;

    int i = 0;
    while( num != 0 )
    {
        int r = num/n[i];
        while( r != 0 )
        {
            result = result + s[i];
            r--;
        }
        num = num%n[i];
        i++;
    }
    std::cout << "\nRoman = " << result;

}