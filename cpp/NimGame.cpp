#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    return 0;
}