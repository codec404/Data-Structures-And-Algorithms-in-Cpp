#include<bits/stdc++.h>

using namespace std;

class QueueImpl{
    stack<int> st1, st2;
private:
public:
    QueueImpl(int sz) {
        this->st1 = stack<int>();
        this->st2 = stack<int>();
    }
    ~QueueImpl() {
        while(!st1.empty()) {
            st1.pop();
        }
        while(!st2.empty()) {
            st2.pop();
        }
    }

    void push(int value) {
        if(st1.empty()) {
            st1.push(value);
        } else {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(value);
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    
    int top() {
        if(st1.empty()) {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }
        return st1.top();
    }

    void pop() {
        if(st1.empty()) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

       st1.pop();
    }
};

int main() {
    int size = 10;
    QueueImpl st(size);
    try {
        int arr[7] = {100,1,2,4,101,102,3};
        for(int i = 0; i < 7; i++) {
            st.push(arr[i]);
        }
        cout << st.top() << endl;
        st.pop();
        cout << st.top() << endl;
        
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}