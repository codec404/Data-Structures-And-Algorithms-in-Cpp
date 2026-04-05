#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getNGE(vector<int> &v)
    {
        int n = v.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(i);
            else
            {
                while (!st.empty() && v[i] > v[st.top()])
                {
                    ans[st.top()] = v[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        return ans;
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nge = getNGE(nums2);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = i;
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = nge[mp[nums1[i]]];
        }

        return ans;
    }
};
int main()
{
    Solution ob;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> ans = ob.nextGreaterElement(b,a); 
    return 0;
}