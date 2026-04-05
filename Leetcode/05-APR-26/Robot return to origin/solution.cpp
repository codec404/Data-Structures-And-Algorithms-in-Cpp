#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (int i = 0; i < moves.length(); i++)
        {
            switch (moves[i])
            {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            }
        }

        if(x == 0 && y == 0) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string moves = "LL";
    cout << (sol.judgeCircle(moves) ? "true" : "false") << endl;
}
