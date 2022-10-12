// You are given two integers representing the size of two different sized arrays. Take the elements of the arrays from the user in the non-decreasing order. If the elements are not in sorted order in any array, display the message “Incorrect Array Elements”. Merge the elements of the given arrays in sorted order and display them. The size of the array should be greater than 0 and less than equal to 20. If array will not be in the given range then display the message “Invalid Array”.

// Input Format

// Your program should take the 4 types of inputs. The first input will represent the size of the first array (n1). Second input will represent the elements of the first array. Third input will represent the size of second array (n2). And fourth input will represent the elements of the second array.

// Constraints

// Size of the arrays should be 0 < n1 <= 20 and 0 < n2 <= 20. If the size will not be in the range, then it should not take the further inputs and display the message “Invalid Array”.
// If the elements of the array will not be in the required order, it should not take the further inputs and display the message “Incorrect Array Elements”.
// If the size of two arrays will be same, then do not take further inputs and display the message “Invalid Array”.
#include <bits/stdc++.h>
using namespace std;
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
}
int main()
{
    int n1;
    cin >> n1;
    if ((n1 < 1 || n1 > 20))
    {
        cout << "Invalid Array";
        return 0;
    }
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n1 - 1; i++)
    {
        if (arr1[i] > arr1[i + 1])
        {
            cout << "Incorrect Array Elements";
            return 0;
        }
    }
    int n2;
    cin >> n2;
    if ((n2 < 1 || n2 > 20))
    {
        cout << "Invalid Array";
        return 0;
    }
    if (n1 == n2)
    {
        cout << "Invalid Array";
        return 0;
    }
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n2 - 1; i++)
    {
        if (arr2[i] > arr2[i + 1])
        {
            cout << "Incorrect Array Elements";
            return 0;
        }
    }
    int arr3[n1 + n2];
    merge(arr1, arr2, n1, n2, arr3);
    for (int i = 0; i < n1 + n2; i++)
        cout << arr3[i] << endl;
    return 0;
}