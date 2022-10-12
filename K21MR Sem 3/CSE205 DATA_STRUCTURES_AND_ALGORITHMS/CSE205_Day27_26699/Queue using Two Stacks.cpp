#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s1, s2;
    int num_operations;
    cin >> num_operations;
    int operation, x;
    for (int i = 0; i < num_operations; i++)
    {
        cin >> operation;
        if (operation == 1)
        {
            cin >> x;
            s1.push(x);
        }
        if (operation == 2)
        {
            if (!s2.empty())
            {
                s2.pop();
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
            }
        }
        if (operation == 3)
        {

            if (!s2.empty())
            {
                cout << s2.top() << endl;
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s2.top() << endl;
            }
        }
    }

    return 0;
}