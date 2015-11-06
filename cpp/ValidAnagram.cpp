#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        char a[256] ={0};

        if(s.size() != t.size()) {
            return false;
        }

        for(string::iterator it = s.begin(); it != s.end(); ++it) {
            a[*it]++;
        }
        for(string::iterator it = t.begin(); it != t.end(); ++it) {
            a[*it]--;
        }

        for(int i = 0; i < 256; ++i) {
            if(a[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};


int main() {
    Solution *sol = new Solution;

    bool rs = sol->isAnagram("rat", "car");
    cout<<rs<<endl;

    return 0;
}