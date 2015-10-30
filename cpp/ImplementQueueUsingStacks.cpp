#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
	stack<int> s1, s2;

public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.empty()) {
        	while(!s1.empty()) {
        		s2.push(s1.top());
        		s1.pop();
        	}
        }

        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(s2.empty()) {
        	while(!s1.empty()) {
        		s2.push(s1.top());
        		s1.pop();
        	}
        }

        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};

int main() {
	Queue q;

	cout<<"empty: "<<q.empty()<<endl;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<"top: "<<q.peek()<<endl;
	cout<<"empty: "<<q.empty()<<endl;
	q.pop();
	cout<<"top: "<<q.peek()<<endl;
	q.pop();
	q.pop();
	cout<<"empty: "<<q.empty()<<endl;

	return 0;
}