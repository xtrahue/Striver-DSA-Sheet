#include <bits/stdc++.h>
using namespace std;

int precedence(char x)
{
    if (x == '^')
    {
        return 3;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isLeft(char ch)
{
    if (ch == '^')
    {
        return 0;
    }
    return 1;
}

string inToPost(string &s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            res.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() &&
                   (precedence(s[i]) < precedence(st.top())))
            { // || (precedence(s[i])==precedence(st.top()) && isLeft(s[i])) -> for only post
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    string res = inToPost(s);
    reverse(res.begin(), res.end());
    cout << res << endl;
}
