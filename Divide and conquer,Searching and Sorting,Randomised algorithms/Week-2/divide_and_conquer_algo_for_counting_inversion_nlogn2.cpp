#include <bits/stdc++.h>
using namespace std;

long long _invcount(long long arr1[],long long tmp[],long long l, long long r);
long long merge_split_count(long long arr[],long long temp2[],long long left,long long mid, long right);

long long _invcount(long long arr1[],long long tmp[],long long l, long long r)
{
    long long count1=0,mid;
    if(r>l)
    {
        mid=(l+r)/2;

        count1= _invcount(arr1,tmp,l,mid);
        count1+= _invcount(arr1,tmp,mid+1,r);

        count1+= merge_split_count(arr1,tmp,l,mid+1,r);
    }
    return count1;
}

long long merge_split_count(long long arr[],long long temp2[],long long left,long long mid, long right)
{
    long long i,j,k;
    long long count2=0;

    i=left;    //index for left subarray
    j=mid;  //index for right subarray
    k=left;    //index for merged subarray
    while( (i<=mid-1) && (j<=right) )
    {
        if(arr[i]<=arr[j])
        {
            temp2[k++]=arr[i++];
        }
        else
        {
            temp2[k++]=arr[j++];
            count2+=(mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp2[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp2[k++]=arr[j++];
    }
    for(long long i=left; i<=right; i++)
    {
        arr[i]=temp2[i];
    }
    return count2;
}
int main()
{
    long long n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long arr[n],temp[n];

        for(long long i=0; i<n; i++)
        {
            cin >>arr[i];
        }
        cout << "Number of inversions are: "<<_invcount(arr,temp,0,n-1)<<endl;
    }
    return 0;
}
