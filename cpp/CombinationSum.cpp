#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int> > rs;
	vector<int> one;
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		sub(candidates, 0, target);

		return rs;
	}

	void sub(vector<int>& candidates, int pos, int target) {
		if(pos >= candidates.size()) {
			return;
		}

		if(0 == target) {
			rs.push_back(one);
			return;
		} else if(0 > target) {
			return;
		} else {
			for(int i = pos; i < candidates.size() && target >= candidates[i]; ++i) {
				one.push_back(candidates[i]);
				sub(candidates, i, target - candidates[i]);
				one.pop_back();
			}
		}
	}
};


int main(int argc, char** argv) {
	vector<int> candidates;
	for(int i = 1; i < argc; ++i) {
		candidates.push_back(atoi(argv[i]));
	}

	cout<<"input target:"<<endl;
	int target;
	cin>>target;

	Solution sol;
	vector<vector<int> > rs = sol.combinationSum(candidates, target);

	for(vector<vector<int> >::iterator it = rs.begin(); it != rs.end(); ++it) {
		for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout<<*it2<<" ";
		}
		cout<<endl;
	}

	return 0;
}