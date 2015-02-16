#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr_ivec;

        if (rowIndex >= 0) {
            curr_ivec.push_back(1);
        }

        for (int i = 1; i <= rowIndex; ++i) {
        	vector<int> last_ivec = curr_ivec;
            vector<int> tmp_ivec;

        	vector<int>::size_type num = last_ivec.size();
        	for(int j = 0; j <= num; ++j) {
        		if(j == 0) {
        			tmp_ivec.push_back(last_ivec[0]);
        		} else if(j == num) {
        			tmp_ivec.push_back(last_ivec[num-1]);
        		} else {
        			tmp_ivec.push_back(last_ivec[j-1] + last_ivec[j]);
        		}
        	}

        	curr_ivec = tmp_ivec;
        }

        return curr_ivec;
    }
};


int main() {
	int numRows;
	cin>>numRows;

	Solution *sol = new Solution;
	vector<int> ivec = sol->getRow(numRows);

	for(vector<int>::iterator iter2 = ivec.begin(); iter2 != ivec.end(); ++iter2) {
		cout<<*iter2<<" ";
	}
	cout<<endl;
}