//Search techniques(linear and binary) on sorted array of unkown size!

#include <bits/stdc++.h>
using namespace std;

// Function for linear search, for a sorted array, without using its size and traversing the entire array
int linear_search(int arr[], int x)
{
    for (int i = 0;; i++) 
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

// Function for Binary Search, for a sorted array, without using its size
int binary_search(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x) //if element to be found is still greater that the element at index high
    {
        low = high; //updating the low value
        high = 2 * high; //double the range of search
    }
    //binary search operation
    int mid = (low+high) / 2;
    while(low<=high)
    {
        if(arr[mid]>x)
        {
            high = mid - 1;
            mid = (low+high) / 2;
        }
        else if(arr[mid]<x)
        {
            low = mid+1;
            mid = (low+high) / 2;
        }
        else
        {
            return mid;
        }
    }
    
}

int main()
{
    int n;
    cout << "enter the number of elemnents in the sorted array: ";
    cin >> n;
    cout<<"enter the sorted array: ";
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int x;
    cout << "enter the element to be found : ";
    cin >> x;
    
    cout <<"index of element to be found(using linear search) : " << linear_search(array, x) << endl;
    cout <<"index of element to be found(using binary search) : " << binary_search(array, x) << endl;
}