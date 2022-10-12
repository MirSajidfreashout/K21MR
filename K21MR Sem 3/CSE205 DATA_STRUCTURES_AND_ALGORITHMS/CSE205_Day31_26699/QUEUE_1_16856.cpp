#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long long int n, k, ans = 1;
    cin >> n >> k;

    const long long mod = 1e9 + 7;

    long long int arr[n];
    for (long long int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    for (long long int i = n; i > 0; i--)
    {
        while (st.size() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.size())
            ans = ans * (st.top() - i + 1) % mod;
        st.push(i);
    }
    cout << ans << endl;
    return 0;
}