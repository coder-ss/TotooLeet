#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    //筛法求小于n的素数个数
    int countPrimes(int n) {
        int *p = new int[n];
        int cnt = 0;

        for(int i = 2; i < n; ++i) {
            p[i] = i;
        }

        for(int i = 2; i * i < n; ++i) {
            if(p[i] == 0) {
                continue;
            }
            for(int j = 2 ; j * i < n; ++j) {
                p[j * i] = 0;
            }
        }

        for(int i = 2; i < n; ++i) {
            if(p[i] != 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout<<"need 1 parameter"<<endl;
        return 0;
    }
    int num = 0;
    Solution *sol = new Solution;
    num = sol->countPrimes(atoi(argv[1]));
    cout<<"the number of prime numbers less than "<<argv[1]<<" is "<<num<<endl;
    return 0;
}