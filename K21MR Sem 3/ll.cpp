#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        map<char, int> pehla;
        map<char, int> doosra;
        for (int i = 0; i < n; i++)
        {
            pehla[a[i]]++;
            doosra[b[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            int var = 0;
            if (pehla.find(a[i]) != pehla.end())
                temp = pehla[a[i]];
            if (doosra.find(b[i]) != doosra.end())
                var = doosra[a[i]];
            int k = min(temp, var);
            ans = max(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}
