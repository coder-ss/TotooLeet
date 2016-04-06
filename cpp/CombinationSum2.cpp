#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

class Solution {
private:
	vector<vector<int> > rs;
	vector<int> one;
	map<vector<int>, int> rs_map;
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		for(int i = 0; i < candidates.size(); ++i) {
			sub(candidates, i, target);
		}

		for(map<vector<int>, int>::iterator it = rs_map.begin(); it != rs_map.end(); ++it) {
			rs.push_back((*it).first);
		}

		return rs;
	}

private:
	void sub(vector<int>& candidates, int pos, int target) {
		if(pos >= candidates.size()) {
			return;
		}
		// cout<<"one:";
		// for(vector<int>::iterator it = one.begin(); it != one.end(); ++it) {
		// 	cout<<*it<<" ";
		// }
		// cout<<endl;
		// cout<<"candidates["<<pos<<"]="<<candidates[pos]<<", target="<<target<<endl;

		// if(0 == target) {
		// 	rs_map[one] = 1;
		// 	return - 1;
		// } else if(0 > target) {
		// 	return -2;
		// }

		one.push_back(candidates[pos]);

		target -= candidates[pos];
		if(0 == target) {
			rs_map[one] = 1;
		} else if(0 > target) {
		} else {
			for(int i = pos + 1; i < candidates.size() && candidates[i] <= target; ++i) {
				sub(candidates, i, target);
			}
		}

		one.pop_back();
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
	vector<vector<int> > rs = sol.combinationSum2(candidates, target);

	for(vector<vector<int> >::iterator it = rs.begin(); it != rs.end(); ++it) {
		for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout<<*it2<<" ";
		}
		cout<<endl;
	}

	return 0;
}