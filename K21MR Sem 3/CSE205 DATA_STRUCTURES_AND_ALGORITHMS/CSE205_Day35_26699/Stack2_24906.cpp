#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    stack<string> st;
    while (t != 2)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            string s;
            cin >> s;
            st.push(s);
        }
        cin >> t;
        if (t == 2)
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}