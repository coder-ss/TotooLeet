#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int rs = num % 9;

        if(rs == 0 && num != 0) {
            rs = 9;
        }

        return rs;
    }
};

int main() {
    int x, rs;
    Solution* sol = new Solution;

    while(cin>>x) {
        rs = sol->addDigits(x);
        cout<<"digit: "<<x<<", add digits: "<<rs<<endl;
    }

    return 0;
}