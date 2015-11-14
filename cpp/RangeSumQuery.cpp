#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> sums;

public:
    NumArray(vector<int> &nums) {
        this->sums.push_back(0);

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            this->sums.push_back(*it + this->sums[this->sums.size() - 1]);
        }
    }

    int sumRange(int i, int j) {
        int len = this->sums.size();

        i = i < 0 ? 0 : i;
        j = j > len - 1 ? len - 1 : j;


        return this->sums[j + 1] - this->sums[i];
    }
};

int main() {
    int a[] = {-2, 0, 3, -5, 2, -1};
    vector<int> ivec(a, a + sizeof(a) / sizeof(int));

    NumArray* sol = new NumArray(ivec);
    int rs = sol->sumRange(0, 2);
    cout<<rs<<endl;

    return 0;
}