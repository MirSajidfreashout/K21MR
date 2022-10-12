// Consider there are N number of employees in Programming domain sitting in one room and have their unique emp_id and M number of employees of Automata domain sitting in an another room with their unique emp_id. As per new guidelines, sitting arrangements have been updated and now all members of Automata domain are shifted in Programming domain. Now as per new sitting arrangement firstly programming domain employees will occupy the cubicle and then automata domain employee will occupy the cubicle(index begins from 0) .Also find the cubicle of employees having even emp_id.If there is no employee with even emp_id then print -1.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    int arr3[n1 + n2];
    for (int i = 0; i < n1; i++)
        arr3[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        arr3[n1 + i] = arr2[i];
    for (int i = 0; i < (n1 + n2); i++)
        cout << arr3[i] << " ";
    cout << endl;
    int count = 0;
    for (int i = 0; i < (n1 + n2); i++)
    {
        if (arr3[i] % 2 != 0)
            count++;
    }
    if (count == (n1 + n2))
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < (n1 + n2); i++)
            if (arr3[i] % 2 == 0)
                cout << i << " ";
    }
    return 0;
}