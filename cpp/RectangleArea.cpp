#include <iostream>

using namespace std;

class Solution {
public:
    int area(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > G || B > H || C < E || D < F) {
            return this->area(A, B, C, D) + this->area(E, F, G, H);
        } else {
            int M = (A > E) ? A : E;
            int N = (B > F) ? B : F;
            int O = (C < G) ? C : G;
            int P = (D < H) ? D : H;

            return this->area(A, B, C, D) + this->area(E, F, G, H) - this->area(M, N, O, P);
        }
    }
};

int main() {
    return 0;
}