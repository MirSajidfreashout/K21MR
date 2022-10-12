#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    while (1)
    {
        int n1;
        cin >> n1;
        vector<string> v1;
        int n2;
        if (n1 == 1)
        {
            cin >> n2;
            if (n2 > 9)
            {
                cout << "No other spectator is allowed";
                return 0;
            }
            for (int i = 0; i < n2; i++)
            {
                string s1;
                cin >> s1;
                v1.push_back(s1);
            }
        }
        int n3;
        cin >> n3;
        int i = 1;
        while (i < n2)
        {
            cout << v1.at(i) << " ";
            i = i + 2;
        }
        break;
    }
    return 0;
}