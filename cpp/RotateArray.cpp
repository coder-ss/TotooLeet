#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(nums == NULL || k == 0 || n == 0 || n == k) return;

        k %= n;
        reverse(nums, 0, n-k);
        reverse(nums, n-k, n);
        reverse(nums, 0, n);
    }
private:
    void reverse(int nums[], int start, int end) {
        --end;
        int tmp;
        while (start < end) {
            tmp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = tmp;
        }
    }
};

int main() {
    Solution *sol = new Solution;
    // int nums[] = {1,2,3,4,5,6,7};
    int nums[] = {1,2};
    
    sol->rotate(nums, 2, 0);
    
    for(int i = 0; i < 2; ++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}