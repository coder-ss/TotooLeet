#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int rs = 0;
        int tmp;
        for(string::iterator iter = s.begin(); iter != s.end(); ++iter) {
        	if(*iter == 'A') tmp = 1;
        	else if(*iter == 'B') tmp = 2;
        	else if(*iter == 'C') tmp = 3;
        	else if(*iter == 'D') tmp = 4;
        	else if(*iter == 'E') tmp = 5;
        	else if(*iter == 'F') tmp = 6;
        	else if(*iter == 'G') tmp = 7;
        	else if(*iter == 'H') tmp = 8;
        	else if(*iter == 'I') tmp = 9;
        	else if(*iter == 'J') tmp = 10;
        	else if(*iter == 'K') tmp = 11;
        	else if(*iter == 'L') tmp = 12;
        	else if(*iter == 'M') tmp = 13;
        	else if(*iter == 'N') tmp = 14;
        	else if(*iter == 'O') tmp = 15;
        	else if(*iter == 'P') tmp = 16;
        	else if(*iter == 'Q') tmp = 17;
        	else if(*iter == 'R') tmp = 18;
        	else if(*iter == 'S') tmp = 19;
        	else if(*iter == 'T') tmp = 20;
        	else if(*iter == 'U') tmp = 21;
        	else if(*iter == 'V') tmp = 22;
        	else if(*iter == 'W') tmp = 23;
        	else if(*iter == 'X') tmp = 24;
        	else if(*iter == 'Y') tmp = 25;
        	else if(*iter == 'Z') tmp = 26;
        	else tmp = 0;

        	rs = 26*rs + tmp;
        }
        return rs;
    }
};

int main() {
	string s;
	cin>>s;
	Solution *sol = new Solution();
	int rs = sol->titleToNumber(s);
	cout<<rs<<endl;
}