// c program to find a element that occur k times first
#include<iostream>
#include<unordered_map>
#include<iterator>
#include<algorithm>

int main() {
    int arr[] = {1, 7, 4, 3, 4, 8, 7, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int k = 2;

    std::unordered_map<int, int> m;
    
    for(int i = 0; i<size; i++) {
        
        if(m.find(arr[i]) != m.end())
        {
            if(++m[arr[i]] == k) {
                std::cout << arr[i] << " is the first element to occur " << k << " times " << std::endl;
                break;
            }
        }
        else
        {
            m[arr[i]] = 1;
        }
    }

}