#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int x, y, area;

        vector<int>::iterator it_start = height.begin();
        vector<int>::iterator it_end = height.end() - 1;

        while(it_start < it_end) {
            x = it_end - it_start;
            y = *it_start <= *it_end ? *it_start++ : *it_end--;

            area = x * y;

            if(max < area) {
                max = area;
            }
        }

        return max;
    }
};

int main() {

}