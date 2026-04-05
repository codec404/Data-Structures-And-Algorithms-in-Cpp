#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    string PostfixToPrefix(string expression)
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
                st.push(c + op1 + op2);
            }
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    string tc = "ab-de+f*/";
    string expected = "/-ab*+def";
    string ans = sol.PostfixToPrefix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}