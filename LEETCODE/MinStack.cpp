#include<bits/stdc++.h>
using namespace std;


int main()
{
    /*
        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
    */

    return 0;
}

class MinStack {
public:

    stack<int> min;
    stack<int> s;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty() || min.top()>= val) 
            min.push(val);
    }
    
    void pop() {
        if(min.top()==s.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */