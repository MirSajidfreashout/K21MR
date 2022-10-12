#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string isBalanced(string s)
{
    stack<char> st;

    for (auto i : s)
    {
        switch (i)
        {
        case '{':
        case '(':
        case '[':
            st.push(i);
            break;
        case '}':
            if (st.empty() || (st.top() != '{'))
            {
                return "NO";
            }
            st.pop();
            break;
        case ')':
            if (st.empty() || (st.top() != '('))
            {
                return "NO";
            }
            st.pop();
            break;
        case ']':
            if (st.empty() || (st.top() != '['))
            {
                return "NO";
            }
            st.pop();
            break;
        }
    }

    if (st.empty() == false)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}