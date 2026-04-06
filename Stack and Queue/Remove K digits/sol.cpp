#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        // cout << n << endl;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(num[i]);
            }
            else
            {
                while (!st.empty() && k > 0 && (num[i] - '0' < st.top() - '0'))
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        // cout << ans << " " << k << endl;

        while (ans.length() > 0)
        {
            if (ans.back() != '0')
            {
                break;
            }
            ans.pop_back();
        }
        // cout << ans << " " << k << endl;
        reverse(ans.begin(), ans.end());
        int l = (int)ans.length();
        for (int i = 0; i < min(k, l); i++)
        {
            ans.pop_back();
        }

        if (ans == "")
            ans.push_back('0');
        return ans;
    }
};
int main()
{
    Solution ob;
    return 0;
}