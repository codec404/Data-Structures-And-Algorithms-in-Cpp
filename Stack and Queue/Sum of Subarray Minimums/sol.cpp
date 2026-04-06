#include <bits/stdc++.h>
using namespace std;
class Solution
{
    const int MOD = 1e9 + 7;

public:
    vector<int> NSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[i] < arr[st.top()])
                {
                    nse[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return nse;
    }
    vector<int> PSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[i] <= arr[st.top()])
                {
                    psee[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return psee;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int right = nse[i] - i;
            int left = i - psee[i];
            ans = (ans + (right * left * 1LL * arr[i])) % MOD;
        }

        return ans;
    }
};
int main()
{
    Solution ob;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    return 0;
}