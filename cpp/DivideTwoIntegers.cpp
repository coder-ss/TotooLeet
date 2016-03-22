#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if(dividend < 0) sign = -sign;
        if(divisor < 0) sign = -sign;

        unsigned int ddd = dividend < 0 ? (unsigned int)0 - dividend : dividend;
        unsigned int dsr = divisor < 0 ? (unsigned int)0 - divisor : divisor;

        if(dsr == 1) {
            return sign == -1 ? -ddd : ddd > INT_MAX ? INT_MAX : ddd;
        }

        if(ddd < dsr) {
            return 0;
        }

        int n, rs;
        unsigned int multi;
        multi = dsr;
        n = rs =0;

        while(multi <= ddd - multi) {
            multi <<= 1;
            ++n;
        }

        while(multi >= dsr) {
            if(ddd >= multi) {
                ddd -= multi;
                rs += 1 << n;
            }

            multi >>= 1;
            --n;
        }

        return sign == -1 ? -rs : rs > INT_MAX ? INT_MAX : rs;
    }
};

int main(int argc, char** argv) {
    if(argc != 3) {
        cout<<"args error!"<<endl;
        return 0;
    }

    int dividend = atoi(argv[1]);
    int divisor = atoi(argv[2]);

    Solution sol;
    int rs = sol.divide(dividend, divisor);
    cout<<"result: "<<rs<<endl;
    return 0;
}