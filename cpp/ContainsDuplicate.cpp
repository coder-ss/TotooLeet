#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(m.find(*it) != m.end()) {
                return true;
            }

            m.insert(pair<int, int>(*it, 1));
        }
        return false;
    }
};


int main() {
    int myints[] = {1,1};
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

    bool rs;
    Solution *sol = new Solution;
    rs = sol->containsDuplicate(nums);
    cout<<rs<<endl;
}