#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();

        string as[10], ag[10];
        for(int i = 0; i < 10; ++i) {
            as[i] = string(len, '0');
            ag[i] = string(len, '0');
        }

        int bulls = 0;
        int cows = 0;

        for(unsigned long i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++bulls;
            } else {
                as[secret[i] - '0'][i] = '1';
                ag[guess[i] - '0'][i] = '1';
            }
        }


        for(int i = 0; i < 10; ++i) {
            int m = this->countBitOne(as[i]);
            int n = this->countBitOne(ag[i]);
            cows += m < n ? m : n;
        }

        char buffer[10];
        sprintf(buffer, "%dA%dB", bulls, cows);

        return string(buffer);
    }

private:
    int countBitOne(string s) {
        int count = 0;
        for(string::iterator it = s.begin(); it != s.end(); ++it) {
            if(*it == '1') {
                ++count;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout<<"3 parametes"<<endl;
        return 0;
    }

    char* s = argv[1];
    char* g = argv[2];

    Solution* sol = new Solution;
    string rs = sol->getHint(s, g);

    cout<<rs<<endl;
    return 0;
}