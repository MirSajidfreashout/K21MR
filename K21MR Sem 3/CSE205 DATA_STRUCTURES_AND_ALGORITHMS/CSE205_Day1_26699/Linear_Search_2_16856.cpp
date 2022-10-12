// Consider the numeric linear array NUMBER[],using the linear search approach ,how many comparisons are used to locate element X in array

// Input Format

// you have to take two input lines: first line takes the array element second line takes the value of x
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int element, pos = -1;
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    cin >> element;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == element)
        {
            pos = i; 
            break;
        }
    }
    if (pos == -1)
    {
        cout << "ELEMENT NOT FOUND";
    }
    else
    {
        cout << pos + 1;
    }
    return 0;
}