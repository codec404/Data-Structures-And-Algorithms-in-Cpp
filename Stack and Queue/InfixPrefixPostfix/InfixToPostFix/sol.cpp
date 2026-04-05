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

public:
    string infixToPostfix(string expression)
    {
        string ans = "";
        stack<char> st;
        for (char c : expression)
        {
            if (c >= 'a' && c <= 'z')
            {
                ans += c;
            }
            else
            {
                if (!st.empty())
                {
                    char top = st.top();
                    if (c == '(')
                    {
                        st.push(c);
                    }
                    else if (c == ')')
                    {
                        while (!st.empty() && top != '(')
                        {
                            ans += top;
                            st.pop();
                            if (!st.empty())
                            {
                                top = st.top();
                            }
                        }
                        st.pop();
                    }
                    else
                    {
                        if (precedence(top) < precedence(c))
                        {
                            st.push(c);
                        }
                        else
                        {
                            while (!st.empty() && precedence(top) >= precedence(c))
                            {
                                ans += top;
                                st.pop();
                                if (!st.empty())
                                {
                                    top = st.top();
                                }
                            }
                            st.push(c);
                        }
                    }
                }
                else
                {
                    st.push(c);
                }
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string tc = "a+b*(c^d-e)^(f+g*h)-i";
    string expected = "abcd^e-fgh*+^*+i-";
    string ans = sol.infixToPostfix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}