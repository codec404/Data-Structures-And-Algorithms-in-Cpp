#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        //  code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[i] < arr[st.top()])
                {
                    ans[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
            }
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
    for(auto &x: arr) {
        cin >> x;
    }
    vector<int> ans = ob.prevSmaller(arr);
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}