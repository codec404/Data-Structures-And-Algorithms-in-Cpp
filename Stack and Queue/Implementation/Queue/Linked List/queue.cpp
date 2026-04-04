#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }

    Node(int value, Node* next) {
        this->data = value;
        this->next = next;
    }
};

class QueueImpl{
    int currSize;
    Node* start;
    Node* end;
private:
public:
    QueueImpl() {
        this->start = NULL;
        this->end = NULL;
        this->currSize = 0;
    }
    ~QueueImpl() {
        while(start != NULL) {
            Node* temp = start;
            start = start->next;
            delete temp;
        }
    }
    void push(int value) {
        if(start == NULL && end == NULL) {;
            end = new Node(value);
            start = end;
        }
        else {
            Node* temp = end;
            end = new Node(value);
            temp->next = end;
        }

        currSize ++;
    }
    
    int front() {
        if(start == NULL) {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }

        return start->data;
    }

    void pop() {
        if(start == NULL) {
            cout << "no element in the queue" << endl;
            throw runtime_error("queue is empty");
        }

        if(currSize == 1) {
            start = NULL;
            end = NULL;
            currSize = 0;
        }
        else {
            start = start->next;
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
    QueueImpl q;
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