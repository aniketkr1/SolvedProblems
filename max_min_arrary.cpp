#include<iostream>
using namespace std;
int main()
{
    int arr[100],n,i,j;
    cout << "Enter the size of array: ";
    cin >> n;                       //taking input as size of arry
    cout << "Enter " << n << " elements" << endl;
    for( i=0; i<n; i++ )
    {
        cin >> arr[i];
    }
    int max = arr[0];
    int min = arr[0];
    for( i=1; i<n; i++ )
    {
        if( arr[i] > max )  //comparing between array elements
        {
            max = arr[i];
        }
        if( arr[i] < min )
        {
            min = arr[i];
        }
    }
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
}