#include <iostream>
#include <string>
#include <queue>

using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.size() == 1) {
//             return s;
//         }

//         if(this->isPalindrome(s)) {
//             return s;
//         }

//         queue<string> q;
//         q.push(string(s.begin(), s.end() - 1));
//         q.push(string(s.begin() + 1, s.end()));

//         while(!q.empty()) {
//             string s1 = q.front();
//             q.pop();

//             if(this->isPalindrome(s1)) {
//                 return s1;
//             }

//             q.push(string(s1.begin(), s1.end() - 1));
//             q.push(string(s1.begin() + 1, s1.end()));
//         }

//         return string("");
//     }

// private:
//     bool isPalindrome(string s) {
//         string::iterator it1 = s.begin();
//         string::iterator it2 = s.end() - 1;

//         while(it1 < it2) {
//             if(*it1 != *it2) {
//                 cout<<s<<":false"<<endl;
//                 return false;
//             }

//             ++it1;
//             --it2;
//         }

//         cout<<s<<":true"<<endl;
//         return true;
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();

        bool B[len][len];
        int mi, mj;
        mi = mj = -1;

        for(int i = len; i >= 0; --i) {
            for(int j = i; j < len; ++j) {
                if(i == j) {
                    B[i][j] = true;
                    if(mi == -1) {
                        mi = i;
                        mj = i;
                    }
                } else if(i + 1 == j) {
                    B[i][j] = s[i] == s[j];
                    if(B[i][j]) {
                        if(mj - mi < j - i) {
                            mi = i;
                            mj = j;
                        }
                    }
                } else {
                    B[i][j] = B[i+1][j-1] && s[i] == s[j];
                    if(B[i][j]) {
                        if(mj - mi < j - i) {
                            mi = i;
                            mj = j;
                        }
                    }
                }
            }
        }

        return s.substr(mi, mj - mi + 1);
    }
};


int main() {
    string s;
    cin>>s;

    Solution *sol = new Solution;
    string rs = sol->longestPalindrome(s);
    cout<<rs<<endl;

    return 0;
}