#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	set<int> hSet;
        int m, t;

        if(n <= 0) return false;

        while(n != 1) {
        	if(hSet.find(n) != hSet.end()) {
        		return false;
        	}
        	hSet.insert(n);
        	t = 0;
        	while(n) {
        		m = n % 10;
        		n = n / 10;

        		t += m * m;
        	}
        	n = t;
        }

        return true;
    }
};

int main() {
	int n;
	Solution sol;

	while(scanf("%d", &n)) {
	    cout<<sol.isHappy(n)<<endl;;
	}
	return 0;
}