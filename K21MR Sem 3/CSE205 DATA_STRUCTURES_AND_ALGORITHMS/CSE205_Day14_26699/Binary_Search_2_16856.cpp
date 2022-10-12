#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int arr[],int n)
{
    int value;
    cin>>value;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==value)
        {
            cout<<mid;
            return 0;
        }
        else if(arr[mid]>value)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<-1;
    return 0;
}

int main() {

    int n;
    cin>>n;
    if(n==1)
    {
        int arr[5];
        arr[0]=n;
        for(int i=1;i<5;i++)
       {
          cin>>arr[i];
       }
        binarysearch(arr,5);
        
    }
    else{
            int arr[n];
        for(int i=0;i<n;i++)
       {
        cin>>arr[i];
       }
        binarysearch(arr,n);
        

    }
    return 0;
}