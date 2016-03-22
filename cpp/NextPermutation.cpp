#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i;
        for(i = n - 1; i > 0; --i) {
            if(nums[i - 1] < nums[i]) {
                break;
            }
        }

        if(i != 0) {
            int pos = find(nums, i - 1, n);
            int tmp = nums[i - 1];
            nums[i - 1] = nums[pos];
            nums[pos]  = tmp;
        }

        sort(nums.begin() + i, nums.end());
    }

private:
    int find(vector<int>& nums, int p, int q) {
        int max = nums[p + 1];
        int pos = p + 1;

        for(int i = p + 1; i < q; ++i) {
            if(nums[i] > nums[p] && nums[i] < max) {
                max = nums[i];
                pos = i;
            }
        }

        return pos;
    }
};


int main(int argc, char** argv) {
    if(argc == 1) {
        return 0;
    }

    vector<int> nums;
    for(int i = 1; i < argc; ++i) {
        nums.push_back(atoi(argv[i]));
    }

    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
        cout<<*iter<<" ";
    }
    cout<<endl;

    Solution sol;
    sol.nextPermutation(nums);

    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
        cout<<*iter<<" ";
    }
    cout<<endl;

    return 0;
}