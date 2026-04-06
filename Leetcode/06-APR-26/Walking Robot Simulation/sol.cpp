#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        map<int, set<int>> x, y;

        for (auto &o : obstacles)
        {
            x[o[0]].insert(o[1]);
            y[o[1]].insert(o[0]);
        }

        int r = 0, c = 1;
        int xPos = 0, yPos = 0;
        int ans = 0;

        for (int cmd : commands)
        {
            if (cmd == -1)
            {
                int temp = r;
                r = c;
                c = -temp;
            }
            else if (cmd == -2)
            {
                int temp = r;
                r = -c;
                c = temp;
            }
            else
            {
                if (c == 0)
                {
                    auto &row = y[yPos];

                    if (r > 0)
                    {
                        auto it = row.upper_bound(xPos);
                        if (it == row.end() || *it > xPos + cmd)
                        {
                            xPos += cmd;
                        }
                        else
                        {
                            xPos = (*it) - 1;
                        }
                    }
                    else
                    {
                        auto it = row.lower_bound(xPos);
                        if (it == row.begin())
                        {
                            xPos -= cmd;
                        }
                        else
                        {
                            --it;
                            if (*it < xPos - cmd)
                            {
                                xPos -= cmd;
                            }
                            else
                            {
                                xPos = (*it) + 1;
                            }
                        }
                    }
                }
                else
                {
                    auto &col = x[xPos];

                    if (c > 0)
                    {
                        auto it = col.upper_bound(yPos);
                        if (it == col.end() || *it > yPos + cmd)
                        {
                            yPos += cmd;
                        }
                        else
                        {
                            yPos = (*it) - 1;
                        }
                    }
                    else
                    {
                        auto it = col.lower_bound(yPos);
                        if (it == col.begin())
                        {
                            yPos -= cmd;
                        }
                        else
                        {
                            --it;
                            if (*it < yPos - cmd)
                            {
                                yPos -= cmd;
                            }
                            else
                            {
                                yPos = (*it) + 1;
                            }
                        }
                    }
                }

                ans = max(ans, xPos * xPos + yPos * yPos);
            }
        }

        return ans;
    }
};
int main()
{
    Solution ob;
    int n, m;
    cin >> n >> m;
    vector<int> commands(n);
    vector<vector<int>> obstacles(m, vector<int>(2));
    for (auto &x : commands)
        cin >> x;
    for (auto &x : obstacles)
        cin >> x[0] >> x[1];
    return 0;
}