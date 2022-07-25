// cpp program to find kth smallest factor of a number
#include<iostream>
#include<vector>

int kThSmallestFactor(int N , int K) 
{
   std::vector<int> fact;
   for(int i = 1; i<=N; i++){
       if(N%i == 0){
           fact.push_back(i);
       }
   }
   int x = fact[K-1];
   return x;
}
    
int main()
{
    int result = kThSmallestFactor(18,4);
    std::cout << "Result = " << result;
    
}
    