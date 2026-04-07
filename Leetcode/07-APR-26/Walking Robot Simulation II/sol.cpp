#include <bits/stdc++.h>
using namespace std;
class Robot
{
    int width, height;
    int x, y;
    int dir;
    int perimeter;
    int stepsTaken;

public:
    Robot(int width, int height)
    {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = 0;
        perimeter = 2 * (width + height) - 4;
        stepsTaken = 0;
    }

    void step(int num)
    {
        if (perimeter == 0)
            return;

        stepsTaken += num;
        int steps = stepsTaken % perimeter;

        x = 0;
        y = 0;

        if (steps == 0 && stepsTaken > 0)
        {
            dir = 3;
            return;
        }

        if (steps <= width - 1)
        {
            x = steps;
            y = 0;
            dir = 0;
        }
        else if (steps <= width - 1 + height - 1)
        {
            x = width - 1;
            y = steps - (width - 1);
            dir = 1;
        }
        else if (steps <= 2 * (width - 1) + height - 1)
        {
            x = width - 1 - (steps - (width - 1 + height - 1));
            y = height - 1;
            dir = 2;
        }
        else
        {
            x = 0;
            y = height - 1 - (steps - (2 * (width - 1) + height - 1));
            dir = 3;
        }
    }

    vector<int> getPos()
    {
        return {x, y};
    }

    string getDir()
    {
        if (dir == 0)
            return "East";
        if (dir == 1)
            return "North";
        if (dir == 2)
            return "West";
        return "South";
    }
};
int main()
{
    int width, height;
    cin >> width >> height;
    Robot* obj = new Robot(width,height);
    return 0;
}