#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        int A[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string B[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i = 0; i < 13; ++i) {
            while(num >= A[i]) {
                num -= A[i];

                s += B[i];
            }
        }

        return s;
    }
};


int main() {
    int a;
    cin>>a;
    
    Solution* sol = new Solution;
    string rs = sol->intToRoman(a);
    cout<<rs<<endl;

    return 0;
}