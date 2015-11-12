#include <iostream>

using namespace std;

bool isBadVersion(int version) {
    if(version >= 1702766719) {
        return true;
    }

    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        return this->binarySearch(1, n);
    }

private:
    int binarySearch(int start, int end) {
        int mid = ((long)start + (long)end) / 2;

        if(isBadVersion(mid)) {
            if(mid == start || !isBadVersion(mid - 1)) {
                return mid;
            }

            return this->binarySearch(start, mid - 1);
        } else {
            if(mid == end || isBadVersion(mid + 1)) {
                return mid + 1;
            }
            return this->binarySearch(mid + 1, end);
        }
    }
};

int main() {
    Solution* sol = new Solution;
    int rs = sol->firstBadVersion(2126753390);

    cout<<rs<<endl;

    return 0;
}
