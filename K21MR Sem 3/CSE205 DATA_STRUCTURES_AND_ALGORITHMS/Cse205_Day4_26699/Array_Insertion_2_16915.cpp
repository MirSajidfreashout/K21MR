// Insert lower case characters just after only upper case characters of the same alphanumeric symbol. The size of array(N) should be greater than 0 and less than equal to 20. If the size of array is not in the mention range then program should display “Invalid size of array”. And if no upper case character is present then display same array.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n; cin>>n;
    char ele;
    if(n<0 || n>20) { cout<<"Invalid size of array";}
    else
    {
        while(cin>>ele){
            if('A' <= ele && ele <= 'Z') printf("%c %c ", ele, ele+32);
            else printf("%c ", ele);
        }
    }
    return 0;
}