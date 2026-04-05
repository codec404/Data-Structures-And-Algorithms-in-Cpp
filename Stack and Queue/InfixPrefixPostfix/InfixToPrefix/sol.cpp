#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int precedence(char c)
    {
        switch (c)
        {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
        }
    }
    string infixToPostFix(string expression)
    {
        string ans = "";
        stack<char> st;
        for (char c : expression)
        {
            if (c >= 'a' && c <= 'z')
            {
                ans += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() &&
                       (precedence(st.top()) > precedence(c) ||
                        (precedence(st.top()) == precedence(c) && c == '^')))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

public:
    string infixPrefix(string expression)
    {
        string newExpression = expression;
        reverse(newExpression.begin(), newExpression.end());
        for (auto &c : newExpression)
        {
            if (c == '(')
            {
                c = ')';
            }
            else if (c == ')')
            {
                c = '(';
            }
        }

        string ans = infixToPostFix(newExpression);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;
    string tc = "a+b*(c^d-e)^(f+g*h)-i";
    string expected = "-+a*b^-^cde+f*ghi";
    string ans = sol.infixPrefix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}