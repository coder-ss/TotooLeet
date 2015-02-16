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
    int minDepth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        return this->mindep(root, 1);
    }

    int mindep(TreeNode *p, int l) {
        if(p->left == NULL && p->right == NULL) {
            return l;
        }

        if(p->left != NULL && p->right == NULL) {
            return this->mindep(p->left, l+1);
        } else if(p->left == NULL && p->right != NULL) {
            return this->mindep(p->right, l+1);
        } else {
            int min_l = this->mindep(p->left, l+1);
            int min_r = this->mindep(p->right, l+1);
            return min_l < min_r ? min_l : min_r;
        }
    }
};


TreeNode* buildTree(int*, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,-1,-1,5};
	// int arr[] = {3,9,20,-1,-1,15,7,-1,-1,-1,-1,-1,8};

	TreeNode *phead = buildTree(arr, 0, 6);

	Solution *sol = new Solution;
	int rs = sol->minDepth(phead);
	cout<<"min length: "<<rs<<endl;

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


