// Let There are 20 students in the Class. Accept the Marks of N Students and insert the next student mark after the highest mark in the list.
// For Example
// if 5 Students Mark are 50 70 55 85 35 62 , then the highest mark is 85 ,So the next student mark(let 40) will be inserted after 85. final array will be 50 70 55 85 40 35 62
#include<iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int element;
    cin>>element;
    int maxIndex=0;
    for(int i=0;i<n;i++)
    {
        if(arr[maxIndex]<arr[i])
        {
            maxIndex=i;
        }
    }
    for(int i=n-1;i>maxIndex;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[maxIndex+1]=element;
    for(int i=0;i<n+1;i++)
    cout<<arr[i]<<" ";
    return 0;
}