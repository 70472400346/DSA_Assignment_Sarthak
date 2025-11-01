// Problem: Implement Stack using Queues
// Platform: LeetCode
// Category: Stack
// Time Complexity: O(n) for push, O(1) for pop/top/empty
// Space Complexity: O(n)
// Author: Sarthak

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q; // single queue used to simulate stack
public:
    MyStack() {} // constructor

    // Push element x onto stack
    void push(int x) {
        q.push(x);           // insert new element
        int size = q.size();
        // rotate the queue so that the new element is at the front
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the top element and returns it
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // Returns the top element
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    // Checks if the stack is empty
    bool empty() {
        return q.empty();
    }
};

// Example usage
int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top after pop: " << st.top() << endl;
    cout << (st.empty() ? "Stack is empty" : "Stack is not empty") << endl;
    return 0;
}
