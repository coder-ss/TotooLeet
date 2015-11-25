#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }

        if(s.size() == 1) {
            return 1;
        }

        int longest, longest_tmp;
        char arr[256];

        memset(arr, 0, 256 * sizeof(char));

        string::iterator it1 = s.begin();
        string::iterator it2 = it1;

        longest = 0;
        longest_tmp = 0;
        
        while(it2 != s.end()) {
            if(arr[*it2] > 0) {
                longest = it2 - it1 > longest ? it2 - it1 : longest;

                while(arr[*it2] > 0) {
                    --arr[*it1];
                    ++it1;
                }
                ++arr[*it2];
            } else {
                ++arr[*it2];
            }

            ++it2;
        }

        longest = it2 - it1 > longest ? it2 - it1 : longest;

        return longest;
    }
};

int main() {
    return 0;
}