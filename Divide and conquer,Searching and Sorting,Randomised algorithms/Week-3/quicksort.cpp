#include<bits/stdc++.h>
using namespace std;

//quicksort algorithm with first element as pivot
long long partition (long long arr2[],long long left,long long right)
{
    //i is the boundary between elements that are less than the pivot and those greater than pivot
    //j is the boundary between partitioned and unpartitioned array
    //piv is the pivot element
    long long i=left + 1;
    long long piv=arr2[left];
    for(long long j=left+1; j<=right; j++)
    {
        if(arr2[j]<piv)
        {
            swap(arr2[i],arr2[j]);
            i++;
        }
    }
    swap(arr2[left],arr2[i-1]);
    return i-1;
}
void quicksort(long long arr1[],long long left,long long right)
{
    if(left<right)
    {
        long long pi=partition(arr1,left,right);
        quicksort(arr1,left,pi-1);
        quicksort(arr1,pi+1,right);
    }
    return;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0; i<n ;i++)
    {
        cin >>arr[i];
    }
    quicksort(arr,0,n-1);
    for(long long i=0; i<n ;i++)
    {
        cout <<arr[i]<<" ";
    }
    return 0;
}
