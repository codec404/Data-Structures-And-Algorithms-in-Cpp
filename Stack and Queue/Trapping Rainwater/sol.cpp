#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        /* formula: min(lMax, rMax) - arr[i] */
        /* vector<int> prefMax(n), suffMax(n);
            prefMax[0] = height[0];
            suffMax[n - 1] = height[n - 1];
            for (int i = 1; i < n; i++)
            {
                prefMax[i] = max(prefMax[i - 1], height[i]);
            }
            for (int i = n - 2; i >= 0; i--)
            {
                suffMax[i] = max(suffMax[i + 1], height[i]);
            }

            int total = 0;
            for (int i = 0; i < n; i++)
            {
                total += min(prefMax[i], suffMax[i]) - height[i];
            }

            return total; 

            Time complexity: O(3N)
            Space Complexity: O(2N)
        */

        int l = 0, r = n-1;
        int lMax = 0, rMax = 0;
        int total = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(lMax > height[l]) {
                    total += (lMax-height[l]);
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if(rMax > height[r]) {
                    total += (rMax-height[r]);
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }

        return total;
    }
};
int main()
{
    Solution ob;
    int n;
    cin >> n;
    vector<int> height(n);
    for (auto &x : height)
        cin >> x;
    int water = ob.trap(height);
    return 0;
}