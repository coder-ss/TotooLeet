#include <iostream>

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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) {
            return false;
        }

        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) {
                return true;
            } else {
                return false;
            }
        }

        return this->hasPathSum(root->left, sum - root->val) || this->hasPathSum(root->right, sum - root->val);
    }
};


TreeNode* buildTree(int*, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,-1,-1,5};
	// int arr[] = {3,9,20,-1,-1,15,7,-1,-1,-1,-1,-1,8};

	TreeNode *phead = buildTree(arr, 0, 6);

	Solution *sol = new Solution;
	bool rs = sol->hasPathSum(phead, 9);
	cout<<"is have path sum: "<<rs<<endl;

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


