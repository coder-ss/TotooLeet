#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, int>::iterator f;

        for(int i = 0; i < nums.size(); ++i) {
            f = m.find(nums[i]);
            if(f != m.end()) {
                if(i - f->second <= k) {
                    return true;
                }
                
                m[nums[i]] = i;
            }

            m.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};


int main() {
    int myints[] = {1,2,3,1};
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

    bool rs;
    Solution *sol = new Solution;
    rs = sol->containsNearbyDuplicate(nums, 3);
    cout<<rs<<endl;
}