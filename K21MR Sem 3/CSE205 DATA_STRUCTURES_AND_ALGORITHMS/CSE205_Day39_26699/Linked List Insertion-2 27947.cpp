#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n < 5 or n > 10)
    {
        cout << "Invalid Input";
    }
    else
    {
        int arr[n + 2];
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        arr[n] = arr[n + 1] = 0;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(arr[i]);
            if (arr[i] == arr[i + 1])
            {
                int res = 0;
                res = arr[i - 1] + arr[i + 2];
                ans.push_back(res);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
int main()
{
    solve();
}