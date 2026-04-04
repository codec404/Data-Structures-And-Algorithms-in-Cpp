#include<bits/stdc++.h>

using namespace std;

class QueueImpl{
    int sz, start, end, currSize;
    int *arr;
private:
public:
    QueueImpl(int sz) {
        this->sz = sz;
        this->start = -1;
        this->end = -1;
        this->currSize = 0;
        arr = new int[sz];
    }
    ~QueueImpl(){
        delete[] arr;
    }
    void push(int value) {
        if(currSize == sz) {
            cout << "queue is full. cannot enter more data" << endl;
            throw runtime_error("queue is full");
        }
        if(start == -1 && end == -1) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % sz;
        }

        arr[end] = value;
        currSize ++;
    }
    
    int front() {
        if(start == -1) {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }

        return arr[start];
    }

    void pop() {
        if(start == -1) {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }

        if(currSize == 1) {
            start = -1;
            end = -1;
            currSize = 0;
        }
        else {
            start = (start + 1) % sz;
            currSize --;
        }
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
    QueueImpl q(size);
    try {
        int arr[7] = {100,1,2,4,101,102,3};
        for(int i = 0; i < 7; i++) {
            q.push(arr[i]);
        }
        cout << q.front() << endl;
        q.pop();
        cout << q.front() << endl;
        
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}