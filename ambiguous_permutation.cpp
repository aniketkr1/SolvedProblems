// cpp program to check a array is Ambiguous Permutation or not

#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    std::cout << "How many elements you want to insert:  ";
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 1; i<=n; i++)
    {
        std::cin >> arr[i];
    }
    int brr[n];
    for(int i = 1; i<=n; i++)
    {
        auto itr = std::find(arr, arr+n, i);
        int x = distance(arr, itr);
        brr[i] = x;
    }
    
    for(int i = 1; i<= n; i++)
    {
        if(brr[i] != arr[i]) {
            std::cout << "Not Ambiguous Permutations" << std::endl;
            return 0;
        }
    }
    
    std::cout << "Ambiguous Permutations" << std::endl;

    return 0;
}