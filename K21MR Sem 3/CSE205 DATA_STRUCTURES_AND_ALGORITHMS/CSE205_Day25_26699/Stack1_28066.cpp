#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    if (size >= 3)
    {
        int start = 0, end = size - 1;
        int mid = start + (end - start) / 2;
        int myStack[size];
        for (int i = 0; i < size; i++)
        {
            cin >> myStack[i];
        }
        cout << myStack[mid] << endl;
        end = end - 1;
        mid = start + (end - start) / 2;
        cout << myStack[mid];
    }
    else
        exit(0);
    return 0;
}