#include <bits/stdc++.h>

using namespace std;

class Minstack {
private:
    stack<pair<int,int>> st;
public:
    Minstack(){
        this->st = stack<pair<int,int>>();
    }
    ~Minstack(){
        while(!st.empty()) {
            st.pop();
        }
    }

    void push(int value) {
        if(st.empty()) {
            st.push({value,value});
        } else {
            pair<int,int> topEle = st.top();
            int prevMini = topEle.second;
            st.push({value, min(value,prevMini)});
        }
    }

    void pop() {
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

class SpaceOptimizedMinstack{
private:
    stack<int> st;
    int mini;
public:
    SpaceOptimizedMinstack(){
        this->st = stack<int>();
        this->mini = 1e9;
    }
    ~SpaceOptimizedMinstack(){
        while(!st.empty()) {
            st.pop();
        }
    }

    void push(int value) {
        if(mini == 1e9) {
            st.push(value);
            mini = value;
            return;
        }

        if(value < mini) {
            st.push(2*value - mini);
            mini = value;
            return;
        }

        st.push(value);
    }

    void pop() {
        if(st.top() < mini) {
            mini = 2*mini - st.top();
        }
        st.pop();
    }

    int top(){
        return (st.top() >= mini ? st.top() : mini);
    }

    int getMin() {
        return mini;
    }
};

int main() {
    Minstack ms;
    ms.push(12);
    ms.push(15);
    ms.push(10);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;

    SpaceOptimizedMinstack sms;
    sms.push(12);
    sms.push(15);
    sms.push(10);
    cout << sms.getMin() << endl;
    sms.pop();
    cout << sms.top() << endl;
    cout << sms.getMin() << endl;
}