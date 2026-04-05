#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; i++)
        {
            if (st.empty())
            {
                st.push(i % n);
            }
            else
            {
                while (!st.empty() && nums[i % n] > nums[st.top()])
                {
                    if (ans[st.top()] == -1)
                        ans[st.top()] = nums[i % n];
                    st.pop();
                }

                st.push(i % n);
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
    vector<int> nums(n);
    for(auto &x : nums) cin >> x;
    vector<int> ans = ob.nextGreaterElements(nums);
    return 0;
}