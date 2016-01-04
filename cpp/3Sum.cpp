#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        vector<vector<int> > rs;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = len - 1;

            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    int arr[] = {nums[i], nums[j], nums[k]};
                    rs.push_back(vector<int>(arr, arr + sizeof(arr) / sizeof(int)));

                    while(j < k && nums[j] == nums[j + 1]) ++j;
                    while(j < k && nums[k] == nums[k - 1]) --k;
                    ++j;--k;
                } else if(sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return rs;
    }
};


int main() {
    //int arr[] = {3,0,-2,-1,1,2};
    int arr[] = {-1,0,1,2,-1,-4};

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution *sol = new Solution;
    vector<vector<int> > rs = sol->threeSum(nums);

    for(int i = 0; i < rs.size(); ++i) {
        for(int j = 0; j < rs[i].size(); ++j) {
            cout<<rs[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}