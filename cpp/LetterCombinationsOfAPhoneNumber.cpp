#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
    string *a;

public:
    Solution() {
        a = new string[10];
        a[0] = "";
        a[1] = "";
        a[2] = "abc";
        a[3] = "def";
        a[4] = "ghi";
        a[5] = "jkl";
        a[6] = "mno";
        a[7] = "pqrs";
        a[8] = "tuv";
        a[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> vs;

        int len = digits.size();
        
        for(int i = 0; i < len; ++i) {
            if(digits[i] == '*' || digits[i] == '#' || digits[i] == '1') {
                return vector<string>();
            }

            vector<string> *vs_last;

            if(vs.empty()) {
                vs_last = new vector<string>(1, "");
            } else {
                vs_last = new vector<string>(vs.begin(), vs.end());
            }
            vs.clear();

            string num_string = a[digits[i] - '0'];

            for(vector<string>::iterator it = vs_last->begin(); it != vs_last->end(); ++it) {

                for(string::iterator iter = num_string.begin(); iter != num_string.end(); ++iter) {
                    vs.push_back(*it + string(1, *iter));
                }
            }
        }
        
        return vs;
    }
};


int main() {
    Solution *s = new Solution;
    vector<string> rs = s->letterCombinations("23");
    for(vector<string>::iterator it = rs.begin(); it != rs.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}