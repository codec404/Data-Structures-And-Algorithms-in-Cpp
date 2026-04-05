#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    string PostfixToInfix(string expression)
    {
        stack<string> st;
        for (char c : expression)
        {
            if (c >= 'a' && c <= 'z')
            {
                st.push(string(1, c));
            }
            else
            {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                st.push("(" + op1 + c + op2 + ")");
            }
        }
        return st.top();
    }
    string PrefixToInfix(string expression)
    {
        /* approach 1:
        string newExpr = string(expression.rbegin(), expression.rend());
        string ans = PostfixToInfix(newExpr);
        reverse(ans.begin(), ans.end());
        for(char &c : ans) {
            if(c == '(') {
                c = ')';
            }
            else if(c == ')') {
                c = '(';
            }
        }
        return ans;
        */
        /* approach 2: */
        stack<string> st;
        for (int i = expression.length() - 1; i >= 0; i--)
        {
            char c = expression[i];
            if (c >= 'a' && c <= 'z')
            {
                st.push(string(1, c));
            }
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push("(" + op1 + c + op2 + ")");
            }
        }

        return st.top();
    }
};

int main()
{
    Solution sol;
    string tc = "*+pq-mn";
    string expected = "((p+q)*(m-n))";
    string ans = sol.PrefixToInfix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}