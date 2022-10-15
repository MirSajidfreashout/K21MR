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
    // unsigned int i = 0;
    // int j = -1;
    // cout<<(i > j);
    hanoi(5, 'A', 'B', 'C');
    return 0;
}