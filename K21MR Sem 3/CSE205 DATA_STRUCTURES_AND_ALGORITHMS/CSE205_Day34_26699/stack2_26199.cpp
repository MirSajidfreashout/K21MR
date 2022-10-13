#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    char stack[999];
    int top;
} s;
void push(char item)
{
    s.top = s.top + 1;
    s.stack[s.top] = item;
}
void pop()
{
    s.top = s.top - 1;
}
int checkPair(char v1, char v2)
{
    return (((v1 == '(') && (v2 == ')')) || ((v1 == '[') && (v2 == ']')) || ((v1 == '{') && (v2 == '}')));
}
int checkBalanced(char exp[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else
        {
            if (s.top == -1)
                return 0;
            else if (checkPair(s.stack[s.top], exp[i]))
            {
                pop();
                continue;
            }
            return 0;
        }
    }
    return 1;
}
int main()
{
    string brackets;
    cin >> brackets;
    int b = brackets.size();
    if(b>10){
        cout<<"Stack Full";
        return 0;
    }
    char B[b];
    for (int i = 0; i < b; i++)
        B[i] = brackets[i];
    s.top = -1;
    if (checkBalanced(B, b))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}