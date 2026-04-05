#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    string PrefixToPostfix(string expression)
    {
        stack<string> st;
        for (int i = expression.length() - 1; i >= 0; i--)
        {
            char c = expression[i];
            if (expression[i] >= 'a' && expression[i] <= 'z')
            {
                st.push(string(1, c));
            }
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push(op1 + op2 + c);
            }
        }

        return st.top();
    }
};

int main()
{
    Solution sol;
    string tc = "/-ab*+def";
    string expected = "ab-de+f*/";
    string ans = sol.PrefixToPostfix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}