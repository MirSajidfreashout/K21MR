#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (accumulate(arr + i, arr + i + j + 1, 1, multiplies<int>()) == accumulate(arr + i, arr + i + j + 1, 0))
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
