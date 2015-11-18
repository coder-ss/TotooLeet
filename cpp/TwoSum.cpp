#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int MOD_NUM = 9997;

struct MyListNode {
    int key;
    int val;
    MyListNode *next;
    MyListNode(int x, int y) : key(x), val(y), next(NULL) {}
};

struct MyHash {
private:
    MyListNode** arr;

public:
    MyHash() {
        arr = new MyListNode*[MOD_NUM];
        for(int i = 0 ; i < MOD_NUM; ++i) {
            arr[i] = NULL;
        }
    }

    bool insert(int x, int y) {
        int index = abs(x % MOD_NUM);

        MyListNode* head = arr[index];

        if(head == NULL) {
            head = new MyListNode(x, y);
            arr[index] = head;

            return true;
        }

        while(head->next) {
            if(head->key == x) {
                return false;
            }
            head = head->next;
        }

        if(head->key == x) {
            return false;
        }
        head->next = new MyListNode(x, y);

        return true;
    }

    bool isExist(int x) {
        int index = abs(x % MOD_NUM);

        MyListNode* head = arr[index];

        while(head) {
            if(head->key == x) {
                return true;
            }
            head = head->next;
        }

        return false;
    }

    int get(int x) {
        int index = abs(x % MOD_NUM);

        MyListNode* head = arr[index];

        while(head) {
            if(head->key == x) {
                return head->val;
            }
            head = head->next;
        }

        return -1;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ivec;

        MyHash* pHash = new MyHash;

        for(int i = 0; i < nums.size(); ++i) {
            pHash->insert(nums[i], i);
        }

        int m, j;
        for(int i = 0; i < nums.size(); ++i) {
            m = target - nums[i];

            if(pHash->isExist(m)) {
                j = pHash->get(m);

                if(i != j) {
                    if(i < j) {
                        ivec.push_back(i + 1);
                        ivec.push_back(j + 1);
                    } else {
                        ivec.push_back(j + 1);
                        ivec.push_back(i + 1);
                    }
                    

                    return ivec;
                }
            }
        }

        return ivec;
    }
};



int main(int argc, char* argv[]) {
    if(argc < 2) {
        return 0;
    }

    char* cn = argv[1];
    int n = atoi(cn);

    //int arr[] = {-3,4,3,90};
    int arr[] = {0,3,4,0}; // target 0
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));


    Solution* sol = new Solution;
    vector<int> rs = sol->twoSum(nums, n);

    for(int i = 0; i < rs.size(); ++i) {
        cout<<rs[i]<<endl;
    }

    return 0;
}