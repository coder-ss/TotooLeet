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
    int maxDepth(TreeNode *root) {
    	int max = 0;
        this->dep(root, 1, max);

        return max;
    }

    void dep(TreeNode *p, int l, int &max) {
    	if(p == NULL)
    		return;

    	if(l > max)
    		max = l;

    	this->dep(p->left, l+1, max);
    	this->dep(p->right, l+1, max);
    }
	
};


TreeNode* buildTree(int*, int, int);

int main(int argc, char const *argv[])
{
	int arr[] = {3,9,20,-1,-1,15,7,-1,-1,-1,-1,-1,8};

	TreeNode *phead = buildTree(arr, 0, 12);

	Solution *sol = new Solution;
	int rs = sol->maxDepth(phead);
	cout<<"max length: "<<rs<<endl;

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


