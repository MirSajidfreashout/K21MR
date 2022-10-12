#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack
{
    int top;

public:
    string a[MAX];

    Stack()
    {
        top = -1;
    }
    bool push(string x);
    string pop();
    string peek();
    void display();
    bool isEmpty();
};

bool Stack::push(string x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

string Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        string x = a[top--];
        return x;
    }
}
string Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        string x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::display()
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << ' ';
        }
        // cout<<endl;
    }
    else
        cout << "empty" << endl;
}

int main()
{
    Stack s;
    while (1)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int n2;
            cin >> n2;
            for (int i = 0; i < n2; i++)
            {
                string s1;
                cin >> s1;
                s.push(s1);
            }
        }
        if (n == 2)
        {
            cout << s.pop() << endl;
            s.display();
            break;
        }
    }

    return 0;
}
