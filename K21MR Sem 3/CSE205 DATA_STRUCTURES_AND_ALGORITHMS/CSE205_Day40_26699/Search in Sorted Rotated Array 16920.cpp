#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int ele, int n)
{
    int low = 0, high = n - 1;
    long int mid = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == ele)
            return mid;
        if (arr[mid] >= arr[low])
        {
            if (ele >= arr[low] && ele < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (ele > arr[mid] && ele <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ele;
    cin >> ele;
    int index = solve(arr, ele, n);
    if (index != -1)
        cout << "Found at index " << index;
    else
        cout << "Not found";
    return 0;
}