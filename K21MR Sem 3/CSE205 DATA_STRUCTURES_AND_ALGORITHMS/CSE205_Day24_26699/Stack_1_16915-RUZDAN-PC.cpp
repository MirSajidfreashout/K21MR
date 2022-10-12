#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> myStack;
    while (true)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int element;
            cin >> element;
            myStack.push_back(element);
        }
        else if (choice == 2)
        {
            myStack.pop_back();
        }
        else if (choice == 3)
        {
            if (myStack.size() == 0)
            {
                cout << -1;
                break;
            }
            else
            {
                for (auto i : myStack)
                {
                    cout << i << " ";
                }
                break;
            }
        }
    }
    return 0;
}