// Write a program to remove element from the specific or provided location and after removing , print all the remaining other elements.

// Input Format

// In first line, it will take the total number of elements in array In second line, pollute the values in array In third Line, it will ask for the index number , from where you want to delete the element
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    for (int i = k; i < n; i++)
    {
        arr[i] = arr[i+1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i];
    }
    return 0;
}