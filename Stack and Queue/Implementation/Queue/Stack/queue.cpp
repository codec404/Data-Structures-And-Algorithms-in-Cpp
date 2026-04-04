#include <bits/stdc++.h>

using namespace std;

class QueueImpl
{
    stack<int> st1, st2;

private:
public:
    QueueImpl(int sz)
    {
        this->st1 = stack<int>();
        this->st2 = stack<int>();
    }
    ~QueueImpl()
    {
        while (!st1.empty())
        {
            st1.pop();
        }
        while (!st2.empty())
        {
            st2.pop();
        }
    }

    void push(int value)
    {
        if (st1.empty())
        {
            st1.push(value);
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(value);
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    int top()
    {
        if (st1.empty())
        {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }
        return st1.top();
    }

    void pop()
    {
        if (st1.empty())
        {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        st1.pop();
    }

    void optimizedPush(int value)
    {
        st1.push(value);
    }

    void optimizedPop()
    {
        if (!st2.empty())
        {
            st2.pop();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }

    int optimizedTop()
    {
        if (!st2.empty())
        {
            return st2.top();
        }
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
};

int main()
{
    int size = 10;
    QueueImpl st(size);
    try
    {
        int arr[7] = {100, 1, 2, 4, 101, 102, 3};
        for (int i = 0; i < 7; i++)
        {
            st.optimizedPush(arr[i]);
        }
        cout << st.optimizedTop() << endl;
        st.optimizedPop();
        cout << st.optimizedTop() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}