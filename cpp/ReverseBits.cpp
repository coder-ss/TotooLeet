#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	int pos;

        while(n != 0) {
        	pos = findPos(n, 0, 32);

        	arr2[pos] = 1;
        	n -= arr[pos];
        }

        uint32_t rs = 0;
        for(int i = 0; i < 32; ++i) {
        	if(arr2[i] == 1) {
        		rs += arr[31 - i];
        	}
        }

        return rs;
    }

    Solution() {
    	arr[0] = 1; arr2[0] = 0;
    	for(int i = 1; i < 32; ++i) {
    		arr[i] = 2 * arr[i-1];
    		arr2[i] = 0;
    	}
    }
private:
	int arr[32];
	int arr2[32];

	int findPos(uint32_t n, int start, int end) {
		int mid;
		while(start < end) {
			mid = (start + end) / 2;

			if(arr[mid] <= n) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
		return start - 1;
	}
};

int main() {
	Solution *sol = new Solution;

	uint32_t rs = sol->reverseBits(43261596);
	cout<<rs<<endl;
	return 0;
}