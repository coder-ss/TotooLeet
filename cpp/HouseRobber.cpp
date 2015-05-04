#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int size = nums.size();
    	int *arr = new int[size];

    	if(size == 0) {
    		return 0;
    	} else if(size == 1) {
    		return nums[0];
    	}

    	arr[0] = nums[0];
    	arr[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    	for(int i = 2; i < size; ++i) {
    		int tmp = nums[i] + arr[i - 2];
    		if(tmp > arr[i - 1]) {
    			arr[i] = tmp;
    		} else {
    			arr[i] = arr[i - 1];
    		}
    	}

    	return arr[size - 1];
    }
};

int main() {
	int arr[] = {1,12,3,4,5};
	vector<int> nums(&arr[0], &arr[5]);

	Solution *sol = new Solution;
	int rs = sol->rob(nums);

	cout<<"result: "<<rs<<endl;

	return 0;
}