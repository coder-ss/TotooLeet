#include <iostream>
#include <cstring>

using namespace std;

class Solution {
private:
    static const int MAX_SIZE = 256;

public:
    bool isIsomorphic(string s, string t) {
        int *ps = new int[Solution::MAX_SIZE];
        int *pt = new int[Solution::MAX_SIZE];

        memset(ps, -1, Solution::MAX_SIZE * sizeof(*ps));
        memset(pt, -1, Solution::MAX_SIZE * sizeof(*pt));

        int ls = s.length();
        int lt = t.length();
        if(ls != lt) {
            return false;
        }
        for(int i = 0; i < ls; ++i) {
            if((ps[s[i]] == -1 && pt[t[i]] == -1) || ps[s[i]] == pt[t[i]]) {
                ps[s[i]] = i;
                pt[t[i]] = i;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout<<"need 2 parameters";
        return 0;
    }
    Solution *sol = new Solution;

    bool rs= sol->isIsomorphic(argv[1], argv[2]);
    cout<<"result: "<<rs<<endl;
    return 0;
}