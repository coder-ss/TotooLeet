#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) {
            return NULL;
        }

        TreeNode *tmp = NULL;

        if(p->val > q->val) {
            tmp = p;
            p = q;
            q = tmp;
        }

        tmp = root;

        if(p->val <= tmp->val && tmp->val <= q->val) {
            return tmp;
        } else if(p->val >= tmp->val) {
            return this->lowestCommonAncestor(tmp->right, p, q);
        } else {
            return this->lowestCommonAncestor(tmp->left, p, q);
        }
    }
};


int main() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    TreeNode *p = root->left;
    p->left = new TreeNode(0);
    p->right = new TreeNode(4);

    TreeNode *q = root->right;
    q->left = new TreeNode(7);
    q->right = new TreeNode(9);

    q = p->right;

    Solution *sol = new Solution;

    TreeNode *rs = sol->lowestCommonAncestor(root, p, q);

    cout<<rs->val<<endl;

    return 0;
}