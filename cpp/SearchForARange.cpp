#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * If the target is not found in the array, return [-1, -1].

 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int pos = bSearch(nums, 0, size - 1, target);


        if(pos == -1) {
            return vector<int>(2, -1);
        } else {
            int begin, end;
            begin = end = pos;
            while(begin > -1 && nums[begin] == target) --begin;
            while(end < size && nums[end] == target) ++end;

            vector<int> rs;
            rs.push_back(++begin);
            rs.push_back(--end);
            return rs;
        }
    }

private:
    int bSearch(vector<int>& nums, int p, int q, int target) {
        if(p > q) {
            return -1;
        }

        int mid = (p + q) / 2;

        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            return bSearch(nums, mid + 1, q, target);
        } else {
            return bSearch(nums, p, mid - 1, target);
        }
    }
};


int main(int argc, char** argv) {
    vector<int> nums;
    for(int i = 1; i < argc; ++i) {
        nums.push_back(atoi(argv[i]));
    }

    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"input the target:"<<endl;
    int target;
    cin>>target;

    Solution sol;
    vector<int> rs = sol.searchRange(nums, target);

    for(vector<int>::iterator it = rs.begin(); it != rs.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}