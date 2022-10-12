#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    string myStack[9];
    int size;
    cin >> size;
    if (size > 9)
    {
        cout << "No other spectator is allowed";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            string name;
            cin >> name;
            myStack[i] = name;
        }
        int y;
        cin >> y;
        for (int i = 1; i < size; i += 2)
        {
            cout << myStack[i] << " ";
        }
    }
    return 0;
}