#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int A[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string B[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int len, pos, rs;
        pos = rs = 0;
        for(int i = 0; i < 13; ++i) {
            len = B[i].size();

            while(s.substr(pos, len) == B[i]) {
                rs += A[i];
                pos += len;
            }
        }

        return rs;
    }
};

int main() {
    string s;
    while(cin>>s) {
        Solution* sol = new Solution;
        int rs = sol->romanToInt(s);
        cout<<rs<<endl;
    }

    return 0;
}
