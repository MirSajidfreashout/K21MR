#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n)
{
    int rev = 0;
    while (n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    for (; cin >> arr[i]; i++)
        ;
    if (i != n)
    {
        cout << "Invalid Input";
        return 0;
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (reverse(arr[i]) != arr[n - i - 1])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}