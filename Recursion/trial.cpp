// C++ program in-place Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void mergeArray(int arr[], int low, int high)
    {
         // Your code here
         int mid = (low+high)/2;
      int i = low;
      int j = mid+1;
      int k = low;
     
    
     int temp[high+1];
    
      while(i<=mid && j<=high)
      {
            if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
    
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
        
   }
    
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j<=high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for(int z = low; z<=high; z++){
        arr[z] = temp[z];
    }
    
    }
void mergeSort(int a[], int si, int end)
{
    if (si >= end)
    {
        return;
    }

    int mid = (si + end) / 2;
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, end);
    mergeArray(a, si, end);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int a[100];
    int n;
    cin >> n;
    inputArray(a, n);
    mergeSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}