#include <bits/stdc++.h>
using namespace std;
class Solution
{
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
    vector<int> NGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[i] > arr[st.top()])
                {
                    nge[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return nge;
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
    vector<int> PGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pgee(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[i] >= arr[st.top()])
                {
                    pgee[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        return pgee;
    }
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int right = nse[i] - i;
            int left = i - psee[i];
            ans += right * left * 1LL * arr[i];
        }

        return ans;
    }
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge = NGE(arr);
        vector<int> pgee = PGEE(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int right = nge[i] - i;
            int left = i - pgee[i];
            ans += right * left * 1LL * arr[i];
        }

        return ans;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        long long sumMax = sumSubarrayMaxs(nums);
        long long sumMin = sumSubarrayMins(nums);

        return sumMax - sumMin;
    }
};
int main()
{
    Solution ob;
    int n;
    cin >> n;
    vector<int> nums;
    for (auto &x : nums)
        cin >> x;
    return 0;
}