#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	char A[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    	--n;
        int multiple = n / 26;
        int remainder = n % 26;

        string rs;

        rs.append(1, A[remainder]);

        while(multiple) {
        	--multiple;
        	remainder = multiple % 26;
        	multiple = multiple / 26;

        	rs.append(1, A[remainder]);
        }

        string s(rs.rbegin(),rs.rend());
        return s;
    }
};

int main() {
	int a;
	cin>>a;
	Solution *sol = new Solution;
	string rs = sol->convertToTitle(a);
	cout<<rs<<endl;
}