#include<bits/stdc++.h>
using namespace std;

void xy(int count)
{
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<i;j++)
        cout<<i<<" "<<j;
    }
    cout<<endl;
}

int main()
{
    int n; cin>>n;
    xy(n);
    return 0;
}