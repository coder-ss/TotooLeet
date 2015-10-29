#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
    int int_top;

public:
    // Push element x onto stack.
    void push(int x) {
        q2.empty() ? q1.push(x) : q2.push(x);
        this->int_top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> *qa = q1.empty() ? &q2 : &q1;
        queue<int> *qb = qa == &q2 ? &q1 : &q2;


        int tmp;
        while((*qa).size() > 1) {
            tmp = (*qa).front();
            (*qa).pop();
            (*qb).push(tmp);
            this->int_top = tmp;
        }

        (*qa).pop();
    }

    // Get the top element.
    int top() {
        return this->int_top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    Stack *s = new Stack;

    s->push(1);
    s->push(2);
    s->push(3);
    cout<<"top:"<<s->top()<<endl;
    cout<<"empty:"<<s->empty()<<endl;
    s->pop();
    cout<<"top:"<<s->top()<<endl;
    s->pop();
    cout<<"top:"<<s->top()<<endl;
    s->pop();
    cout<<"empty:"<<s->empty()<<endl;

    s->push(1);
    s->push(2);
    s->push(3);
    cout<<"top:"<<s->top()<<endl;
    cout<<"empty:"<<s->empty()<<endl;
    s->pop();
    cout<<"top:"<<s->top()<<endl;
    s->pop();
    cout<<"top:"<<s->top()<<endl;
    s->pop();
    cout<<"empty:"<<s->empty()<<endl;

    return 0;
}