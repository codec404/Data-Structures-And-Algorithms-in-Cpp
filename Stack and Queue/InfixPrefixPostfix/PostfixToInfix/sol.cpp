#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    string PostfixToInfix(string expression)
    {
        stack<string> st;
        for(char c : expression) {
            if(c >= 'a' && c <= 'z') {
                st.push(string(1, c));
            }
            else {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
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
    string tc = "ab+cd^e-fgh*+^*i-";
    string expected = "(((a+b)*(((c^d)-e)^(f+(g*h))))-i)";
    string ans = sol.PostfixToInfix(tc);
    cout << ans << endl;
    cout << (ans == expected ? "true" : "false") << endl;
    return 0;
}