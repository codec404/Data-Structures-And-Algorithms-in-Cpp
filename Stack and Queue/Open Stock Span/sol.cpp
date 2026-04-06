#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
private:
    int cnt;
    stack<pair<int, int>> st;

public:
    StockSpanner()
    {
        this->cnt = 0;
        this->st = stack<pair<int, int>>();
    }

    int next(int price)
    {
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        if (st.empty())
        {
            st.push({price, cnt});
            cnt++;
            return cnt;
        }
        else
        {
            int idx = st.top().second;
            st.push({price, cnt});
            cnt++;
            return cnt - idx - 1;
        }
    }
};
int main()
{
    int price;
    cin >> price;
    StockSpanner* obj = new StockSpanner();
    int param_1 = obj->next(price);
    return 0;
}