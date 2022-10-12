#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

template <class T>
class Queue : protected list<T>
{
    int even = 0;

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

    int size() { return this->size(); }

    void display()
    {
        for (auto i = this->begin(); i != this->end(); i++)
        {
            if (!(*i & 1))
            {
                cout << *i << ' ';
                even++;
            }
        }
        if (!even)
            cout << "No even element is there";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Queue<int> q;
    int n, elem;
    cin >> n;
    if (n < 2 || n > 15)
    {
        cout << "Invalid Queue range";
        return 0;
    }
    fii
    {
        cin >> elem;
        q.enqueue(elem);
    }
    q.display();
    return 0;
}