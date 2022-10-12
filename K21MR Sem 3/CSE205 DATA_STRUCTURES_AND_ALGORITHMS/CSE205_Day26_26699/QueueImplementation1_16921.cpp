#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

template <class T>
class Queue : protected list<T>
{
public:
    void enqueue(T value)
    {
        this->push_back(value);
    };
    bool deque()
    {
        if (list<T>::size() == 0)
            return 0;
        this->pop_front();
        return true;
    }
    T front()
    {
        return *(this->begin());
    }

    void display()
    {
        for (auto i = this->begin(); i != this->end(); i++)
            cout << *i << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (2 >= n || n > 10)
    {
        cout << "Invalid size";
        return 0;
    }
    Queue<int> q;
    int val;
    cin >> val;
    q.enqueue(val);
    while (cin >> val)
    {
        if (val > q.front())
            q.enqueue(val);
    }
    q.display();
    return 0;
}