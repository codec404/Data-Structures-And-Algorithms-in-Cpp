#include<bits/stdc++.h>

using namespace std;

class StackImpl{
    queue<int> q;
private:
public:
    StackImpl() {
        this->q = queue<int>();
    }
    ~StackImpl() {
        while (!q.empty()) {
            q.pop();
        }        
    }
    void push(int value) {
       int sz = q.size();
       q.push(value);
       for(int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
       }
    }
    
    int top() {
        if(q.empty()) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        return q.front();
    }

    void pop() {
        if(q.empty()) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        q.pop();
    }
};

int main() {
    StackImpl st;
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