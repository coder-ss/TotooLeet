#include <iostream>
#include <deque>

using namespace std;

class MinStack {
private:
    deque<int> ivec, mivec;

public:
    void push(int x) {
        if(this->ivec.empty() || x <= this->mivec.back()) {
            this->mivec.push_back(x);
        }

        this->ivec.push_back(x);
    }

    void pop() {
        if(!this->ivec.empty()) {
            if(this->mivec.back() == this->ivec.back()) {
                this->mivec.pop_back();
            }
            this->ivec.pop_back();
        }
    }

    int top() {
        if(!this->ivec.empty()) {
            return this->ivec.back();
        }
    }

    int getMin() {
        if(!this->mivec.empty()) {
            return this->mivec.back();
        }
    }
};


int main() {
    MinStack *ms = new MinStack;

    ms->push(5);
    ms->push(4);
    ms->push(3);
    ms->push(5);

    cout<<ms->top()<<endl;
    cout<<ms->getMin()<<endl;
}