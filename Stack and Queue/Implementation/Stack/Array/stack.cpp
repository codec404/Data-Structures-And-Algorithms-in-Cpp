#include<bits/stdc++.h>

using namespace std;

class StackImpl{
    int sz, tp, currSize;
    int *arr;
private:
public:
    StackImpl(int sz) {
        this->sz = sz;
        this->tp = -1;
        this->currSize = 0;
        arr = new int[sz];
    }
    ~StackImpl() {
        delete[] arr;
    }
    void push(int value) {
        if(currSize == sz) {
            cout << "stack is full. cannot enter more data" << endl;
            throw runtime_error("stack is full");
        }
        tp++;
        arr[tp] = value;
        currSize ++;
    }
    
    int top() {
        if(tp == -1) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        return arr[tp];
    }

    void pop() {
        if(tp == -1) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        tp --;
        currSize --;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    int size() {
        return currSize;
    }
};

int main() {
    int size = 10;
    StackImpl st(size);
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