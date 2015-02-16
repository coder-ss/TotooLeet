#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > rs;

        if (numRows > 0) {
        	vector<int> tmp_ivec;
        	tmp_ivec.push_back(1);
        	rs.push_back(tmp_ivec);
        }

        for (int i = 1; i < numRows; ++i) {
        	vector<int> last_vec = rs[i-1];
        	vector<int> curr_vec;

        	vector<int>::size_type num = last_vec.size();
        	for(int j = 0; j <= num; ++j) {
        		if(j == 0) {
        			curr_vec.push_back(last_vec[0]);
        		} else if(j == num) {
        			curr_vec.push_back(last_vec[num-1]);
        		} else {
        			curr_vec.push_back(last_vec[j-1] + last_vec[j]);
        		}
        	}

        	rs.push_back(curr_vec);
        }

        return rs;
    }
};


int main() {
	int numRows;
	cin>>numRows;

	Solution *sol = new Solution;
	vector<vector<int> > ivec = sol->generate(numRows);

	for(vector<vector<int> >::iterator iter1 = ivec.begin(); iter1 != ivec.end(); ++iter1) {
		for(vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2) {
			cout<<*iter2<<" ";
		}
		cout<<endl;
	}
}