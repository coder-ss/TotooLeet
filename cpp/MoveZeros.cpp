#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it1, it2;
        int tmp;
        it1 = it2 = nums.begin();

        while(it2 != nums.end() && it1 != nums.end() && *it1 != 0) {
            ++it1;
            ++it2;
        }

        if(it1 == nums.end()) { return; }
        ++it2;


        while(it2 != nums.end() && it1 != nums.end()) {
            while(it2 != nums.end() && *it2 == 0) { ++it2; }
            if(it2 == nums.end()) { return; }

            while(it1 != nums.end() && *it1 != 0) { ++it1; }
            if(it1 == nums.end()) { return; }

            tmp = *it1;
            *it1 = *it2;
            *it2 = tmp;
        }
    }
};

int main() {
    int arr[] = {4,2,4,0,0,3,0,5,1,0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution* sol = new Solution;
    sol->moveZeroes(nums);

    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}