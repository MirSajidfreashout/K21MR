#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n];
    int count = 0;
    if (n > 4 && n < 20)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 'W')
            {
                cout << i << " ";
                count++;
            }
        }
        if (count == 0)
            cout << -1 << endl << 0;
        else
            cout << endl << count;
    }
    else
    {
        return 0;
    }
    return 0;
}