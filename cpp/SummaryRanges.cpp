#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> svec;
        string s;
        char t[100];

        vector<int>::iterator iter2 = nums.begin();
        for(vector<int>::iterator iter1 = nums.begin(); iter1 != nums.end(); ++iter1) {
            if(iter2 < iter1) {
                iter2 = iter1;
            }

            while(iter2 + 1 < nums.end() && *iter2 == *(iter2 + 1) - 1) {
                ++iter2;
            }

            
            if(iter1 == iter2) {
                sprintf(t, "%d", *iter1);
            } else {
                sprintf(t, "%d->%d", *iter1, *iter2);
                iter1 = iter2;
            }

            s = t;
            svec.push_back(s);
        }

        return svec;
    }
};

int main() {
    vector<int> ivec;
    ivec.push_back(-1);
    // ivec.push_back(0);
    // ivec.push_back(1);
    // ivec.push_back(2);
    // ivec.push_back(4);
    // ivec.push_back(5);
    // ivec.push_back(7);

    Solution *sol = new Solution;
    vector<string> svec = sol->summaryRanges(ivec);

    for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter) {
        cout<<*iter<<" ";
    }
    cout<<endl;

    return 0;
}