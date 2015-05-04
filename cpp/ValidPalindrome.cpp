#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator iter1 = s.begin();
        string::iterator iter2 = s.end() - 1;

        while(iter1 < iter2) {
            while(iter1 < s.end() && !isalnum(*iter1)) {
                ++iter1;
            }
            while(iter2 >= s.begin() && !isalnum(*iter2)) {
                --iter2;
            }
            if(*iter1 == *iter2 || *iter1 == *iter2 + 32 || *iter1 == *iter2 - 32) {
                ++iter1;
                --iter2;
            } else {
                return false;
            }
        }

        return true;
    }
};


int main() {
    string s;
    cin>>s;
    Solution *sol = new Solution;
    bool rs = sol->isPalindrome(s);
    cout<<"result: "<<rs<<endl;
}