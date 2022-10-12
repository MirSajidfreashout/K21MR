#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    if (t < 1)
    {
        cout << "Invalid Input";
        exit(0);
    }
    else
    {
        while (t--)
        {
            string word;
            cin >> word;
            int size = word.length();
            int flag = 0;
            for (int i = 0; i < size / 2; i++)
            {
                if (word[i] != word[size - i - 1])
                    flag = 1;
            }
            if (flag)
                cout << "No";
            else
                cout << "Yes";
            cout << endl;
        }
    }
    return 0;
}