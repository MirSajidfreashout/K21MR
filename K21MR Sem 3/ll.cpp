#include<bits/stdc++.h>
using namespace std;
void hanoi(int n, char beg, char end, char aux)
{
    if(n==0) // move disk from Source to the Dest
    return;
    else
    hanoi(n-1, beg, aux, end);
    // move n-1 disks to auxilliary
    // move nth disk to destination
    // move n-1 disks to destination
    cout<<"Move disk "<< n <<" from beg "<<beg<<" to end "<< end<<endl;
    hanoi(n-1, aux, end, beg);
}
int main()
{
    cout<<"Enter number of disks: ";
    ios_base::sync_with_stdio(0);




    
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}