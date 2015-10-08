#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int dep = 0;
        return this->balance(root, dep);
    }
    
    bool balance(TreeNode *p, int &dep) {
        if(p == NULL) {
            dep = 0;
            return true;
        }

        int l_dep,r_dep;
        bool l_balance = this->balance(p->left, l_dep);
        bool r_balance = this->balance(p->right, r_dep);

        if(l_balance && r_balance) {
            int diff = l_dep - r_dep;

            if(diff >= -1 && diff <= 1) {
                dep = 1 + (l_dep >= r_dep ? l_dep : r_dep);
                return true;
            }
        }

        return false;
    }
};


TreeNode* buildTree(int*, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {3,9,20,-1,-1,15,7,-1,-1,-1,-1,-1,8};

    TreeNode *phead = buildTree(arr, 0, 12);

    cout<<"是否平衡树：";
    Solution *sol = new Solution;
    bool rs = sol->isBalanced(phead);
    if(rs) {
        cout<<"是！"<<endl;
    } else {
        cout<<"否！"<<endl;
    }

    return 0;
}

TreeNode* buildTree(int *arr, int pos, int total) {
    if(pos > total || pos < 0 || arr[pos] == -1) {
        return NULL;
    }

    TreeNode *p = new TreeNode(arr[pos]);

    p->left = buildTree(arr, 2*pos + 1, total);
    p->right = buildTree(arr, 2*pos + 2, total);

    return p;
}


