// Akash got an interesting assignment. He got K balls, every ball has its diameter inscribed. Write a programming solution, to help akash to find the largest ball. He is supposed to solve assignment N times.

// Input Format

// 1st line contain N(nos. of problem)
// 2nd line contain space separated diameter from K balls
// Constraints

// K=6
// N>0 & N<5
// Output Format

// Return diameter of highest ball. For Every assignment, output should be on a new line.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    if(t>0 && t<5)
    {
    while (t--)
    {
        int arr[6];
        for (int i = 0; i < 6; i++)
            cin >> arr[i];
        int max = arr[0];
        for (int i = 0; i < 6; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        cout << max << endl;
    }
    }
    else{
        return 0;
    }
    return 0;
}