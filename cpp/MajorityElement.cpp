#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        // sort(num.begin(), num.end());
        // return num[num.size() / 2];
        vector<int>::iterator iter = num.begin();
        int major = *iter;
        int count = 1;

        while(++iter < num.end()) {
        	if(count == 0) {
        		major = *iter;
        		++count;
        	} else if(*iter == major) {
        		++count;
        	} else {
        		--count;
        	}
        }

        return major;
    }
};

int main() {
	Solution *sol = new Solution;

	int arr[] = {1,2,2,4,5,6,2,2,2};
	vector<int> ivec(&arr[0], &arr[8]);
	int rs = sol->majorityElement(ivec);
	cout<<rs<<endl;

	return 0;
}