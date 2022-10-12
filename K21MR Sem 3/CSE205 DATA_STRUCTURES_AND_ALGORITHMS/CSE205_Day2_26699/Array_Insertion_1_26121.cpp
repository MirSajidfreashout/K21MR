#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int element;
    cin >> element;
    int index=0;
    if (n == size)
        cout << "Insertion is not possible because Array Overflow.. !!";
    else
    {
        if (element < n)
        {
            index = n % element;
        }
        else
        {
            index = element % n;
        }
    }
    if (index != 0)
        index = index - 1;
    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    return 0;
}