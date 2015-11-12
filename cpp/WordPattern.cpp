#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> hash1;
        map<string, char> hash2;

        string::iterator it_sub_start, it_sub_end;
        it_sub_start = it_sub_end = str.begin();
        for(string::iterator it = pattern.begin(); it != pattern.end(); ++it) {
            while(*it_sub_end != ' ' && it_sub_end != str.end()) {
                ++it_sub_end;
            }

            string sub = string(it_sub_start, it_sub_end);

            if(hash1.find(*it) == hash1.end()) {
                hash1[*it] = sub;
            } else if(hash1[*it] != sub) {
                return false;
            }

            if(hash2.find(sub) == hash2.end()) {
                hash2[sub] = *it;
            } else if(hash2[sub] != *it) {
                return false;
            }

            if(it_sub_end != str.end()) {
                ++it_sub_end;
                it_sub_start = it_sub_end;
            }
        }

        if(it_sub_end == str.end()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution* sol = new Solution;
    bool rs = sol->wordPattern("aaa", "aa aa aa aa");
    cout<<rs<<endl;

    return 0;
}