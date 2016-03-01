#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：左括号的个数大于等于右括号的个数
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;

        gp(n, n, "", vs);

        return vs;
    }

    void gp(int ln, int rn, string s, vector<string> &vs) {
        if(ln == 0 && rn == 0) {
            vs.push_back(s);
        }

        if(ln > 0) {
            gp(ln - 1, rn, s + "(", vs);
        }
        if(rn > ln) {
            gp(ln, rn - 1, s + ")", vs);
        }
    }
};

int main() {
    vector<string> vs;
    Solution s;
    vs = s.generateParenthesis(0);

    for(vector<string>::iterator it = vs.begin(); it != vs.end(); ++it) {
        cout<<*it<<endl;
    }

    return 0;
}