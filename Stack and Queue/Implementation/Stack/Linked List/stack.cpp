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

class StackImpl{
    int currSize;
    Node* topNode;
private:
public:
    StackImpl(int sz) {
        this->topNode = NULL;
        this->currSize = 0;
    }
    ~StackImpl() {
        while(topNode != NULL) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;;
        }
    }
    void push(int value) {
        Node* temp = topNode;
        topNode = new Node(value);
        topNode->next = temp;
        currSize ++;
    }
    
    int top() {
        if(topNode == NULL) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        return topNode->data;
    }

    void pop() {
        if(topNode == NULL) {
            cout << "no element in the stack" << endl;
            throw runtime_error("stack is empty");
        }

        topNode = topNode->next;
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