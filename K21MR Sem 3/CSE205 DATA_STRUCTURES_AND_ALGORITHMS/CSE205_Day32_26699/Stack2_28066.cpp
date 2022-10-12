#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> vec)
{
    int sum_ = 0;
    for (auto i = vec.begin(); i < vec.end(); i++)
    {
        sum_ += *i;
    }
    return sum_;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    int sum1 = sum(h1), sum2 = sum(h2), sum3 = sum(h3);
    int min_;
    while (!h1.empty() && !h2.empty() && !h3.empty())
    {
        min_ = min(sum1, min(sum2, sum3));
        if (sum1 == sum2 && sum1 == sum3 && sum2 == sum3)
            break;

        if (sum1 > min_)
        {
            sum1 -= h1.at(0);
            h1.erase(h1.begin());
        }

        if (sum2 > min_)
        {
            sum2 -= h2.at(0);
            h2.erase(h2.begin());
        }

        if (sum3 > min_)
        {
            sum3 -= h3.at(0);
            h3.erase(h3.begin());
        }
    }
    if (h1.empty() || h2.empty() || h3.empty())
        return 0;
    return sum1;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> v1, v2, v3;
    int elem;
    for (int i = 0; i < n1; i++)
    {
        cin >> elem;
        v1.push_back(elem);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> elem;
        v2.push_back(elem);
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> elem;
        v3.push_back(elem);
    }

    cout << equalStacks(v1, v2, v3);
    return 0;
}
