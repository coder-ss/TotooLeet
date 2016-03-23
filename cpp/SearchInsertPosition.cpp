#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.

 * You may assume no duplicates in the array.
 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */


class Solution {
private:
    int pos_greate;

public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        pos_greate = size;

        return bSearch(nums, 0, size - 1, target);
    }

private:
    int bSearch(vector<int>& nums, int p, int q, int target) {
        if(p > q) {
            return pos_greate;
        }

        int mid = (p + q) / 2;

        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            return bSearch(nums, mid + 1, q, target);
        } else {
            pos_greate = mid;
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
    int rs = sol.searchInsert(nums, target);

    cout<<rs;
    cout<<endl;

    return 0;
}