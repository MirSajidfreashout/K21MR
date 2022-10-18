#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a,b; cin>>a>>b; string Queue[b];
    for(int i=0;i<b;i++)
        cin>>Queue[i];
    if(b>a) cout<<"Houseful\n";
    else cout<<"Booked\n";
    return 0;
}